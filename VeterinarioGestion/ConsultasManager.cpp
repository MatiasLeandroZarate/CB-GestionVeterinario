#include "ConsultasManager.h"

using namespace std;

const string ENCABEZADO_ALTA_CONSULTA = "========== Alta de consulta medica ==========";
const string ENCABEZADO_MODIFICACION_CONSULTA = "========== Modificacion de consulta medica ==========";
const string ENCABEZADO_LISTADO_CONSULTAS = "========== Listado de consultas medicas activas ==========";
const string ENCABEZADO_BAJA_CONSULTA = "========== Baja de consulta medica ==========";
const string ENCABEZADO_LISTADO_CONSULTAS_POR_MASCOTA = "========== Listado de consultas medicas por mascota ==========";
const string ENCABEZADO_LISTADO_CONSULTAS_POR_FECHAS = "========== Listado de consultas medicas por rango de fechas ==========";
const string ENCABEZADO_LISTADO_CONSULTAS_POR_SUCURSAL = "========== Listado de consultas medicas por sucursal ==========";
const string ENCABEZADO_LISTADO_CONSULTAS_POR_VETERINARIO = "========== Listado de consultas medicas por veterinario ==========";
const string ENCABEZADO_LISTADO_CONSULTAS_POR_CLIENTE = "========== Listado de consultas medicas por cliente ==========";

const string MENSAJE_AVISO_RETORNO_MENU = "ATENCION: Sera regresado al menu anterior.";
const string MENSAJE_CONFIRMACION_DATOS = "-> Confirma que los datos y la accion a realizar son correctos? (S/N): ";
const int MAXIMOS_REINTENTOS_ENTRADA_DATOS = 3;

int ConsultasManager::idMascotaFiltro = 0;
Fecha ConsultasManager::fechaDesdeFiltro = Fecha();
Fecha ConsultasManager::fechaHastaFiltro = Fecha();
int ConsultasManager::idSucursalFiltro = 0;
int ConsultasManager::idVeterinarioFiltro = 0;
int ConsultasManager::idClienteFiltro = 0;

void ConsultasManager::altaConsulta() {
    GestorArchivo archivoConsultas("consultas.dat");

    int idMascota, idTratamiento, idVeterinario, idSucursal;
    int contadorIntentosCreacion = 0;
    string sintomas, diagnostico,respuestaProximaVisita;
    bool registraProximaVisita, nuevaConsultaEsValida, aceptaNuevoRegistro;

    Tratamientos tratamiento;
    Veterinarios veterinario;
    Fecha fechaConsulta, fechaProximaVisita = Fecha();

    Validaciones validador;

    do{
        contadorIntentosCreacion++;

        cout << ENCABEZADO_ALTA_CONSULTA << endl;
         //Obtencion de  Sucursal.
        optional<Sucursales> sucursalOptional = solicitarSucursalValidada();
        if(sucursalOptional.has_value()){
            int idSucursal = sucursalOptional.value().getIDSucursal();
         } else {
             cout << MENSAJE_AVISO_RETORNO_MENU << endl;
             break;
         }

        //Obtencion de mascota
         optional<Mascotas> mascotaOptional = solicitarMascotaValidada();
         if(mascotaOptional.has_value()){
                idMascota = mascotaOptional.value().getIDMascota();
         } else {
             cout << MENSAJE_AVISO_RETORNO_MENU << endl;
             break;
         }

        //Obtencion de fecha de consulta
        fechaConsulta = fechaConsulta.ValidacionFecha(fechaConsulta);

        cout << "Ingrese los sintomas: ";
        getline(cin, sintomas);

        cout << "Ingrese el diagnostico: ";
        getline(cin, diagnostico);

        //Obtencion de  tratamiento.
         optional<Tratamientos> tratamientoOptional = solicitarTratamientoValidado();
         if(tratamientoOptional.has_value()){
            idTratamiento = tratamientoOptional.value().getIDTratamiento();
         } else {
             cout << MENSAJE_AVISO_RETORNO_MENU << endl;
             break;
         }

        //Obtencion de  Veterinario.
         optional<Veterinarios> veterinarioOptional = solicitarVeterinarioValidado();
         if(veterinarioOptional.has_value()){
            idVeterinario = veterinarioOptional.value().getIDVeterinario();
         } else {
             cout << MENSAJE_AVISO_RETORNO_MENU << endl;
             break;
         }

        cout << "Desea registrar una proxima visita? (S/N): ";
        respuestaProximaVisita = validador.validarLetra();

        if(respuestaProximaVisita == "S")
        {
            fechaProximaVisita = fechaProximaVisita.ValidacionFecha(fechaProximaVisita);
        }

        Consultas consulta = Consultas(obtenerProximoId(), idMascota, fechaConsulta, sintomas, diagnostico, idTratamiento, fechaProximaVisita, idVeterinario, idSucursal);

        nuevaConsultaEsValida = esConsultaValida(consulta);

        if(nuevaConsultaEsValida){
            cout << MENSAJE_CONFIRMACION_DATOS << endl;
            imprimirConsulta(consulta);

            aceptaNuevoRegistro = confirmaAccion();

            if(aceptaNuevoRegistro){
              if (archivoConsultas.GuardarConsultas(consulta)) {
                    cout << "Consulta creada exitosamente.";
                    esperarCualquierTecla();
                } else {
                    cout << "Ocurrio un error al guardar la consulta, intente de nuevo mas tarde.";
                    esperarCualquierTecla();
                    limpiarPantalla();
                }
            } else {
                cout << "Porfavor, ingrese todos los datos nuevamente.";
                esperarCualquierTecla();
            }
        } else {
            cout << "Ya existe una consulta para los datos ingresados, corrija e intente nuevamente.";
            esperarCualquierTecla();
        }

        if(!aceptaNuevoRegistro){
            limpiarPantalla();
        }

        if(contadorIntentosCreacion == MAXIMOS_REINTENTOS_ENTRADA_DATOS){
            cout << MENSAJE_AVISO_RETORNO_MENU << endl;
            break;
        }
    } while(!nuevaConsultaEsValida || !aceptaNuevoRegistro);

    esperarCualquierTecla();
    limpiarPantalla();
}

void ConsultasManager::modificarConsulta() {
    bool usuarioConfirmaAccion = false;
    Consultas consulta;
    int id;

    do{
        limpiarPantalla();
        cout << ENCABEZADO_MODIFICACION_CONSULTA << endl;
        optional<Consultas> consultaOptional = solicitarConsultaPorId();

        if(consultaOptional.has_value()){
            cout << "No existe ninguna consulta asociada a ese ID, porfavor ingrese uno valido." << endl;
            return;
        } else {
            cout << MENSAJE_AVISO_RETORNO_MENU << endl;
            return;
        }

        consulta = consultaOptional.value();

        imprimirConsulta(consulta);

        cin.ignore();
        usuarioConfirmaAccion = confirmaAccion();
    }while(!usuarioConfirmaAccion);

    string nuevoDiagnostico;
    cout << "Diagnostico actual: " << consulta.getDiagnostico() << endl;
    cout << "Nuevo diagnóstico: ";
    cin.ignore();
    getline(cin, nuevoDiagnostico);

    consulta.setDiagnostico(nuevoDiagnostico);
    GestorArchivo archivoConsultas("consultas.dat");

    int posicionConsultaArchivo = BuscarConsultaPorID(id);

    if (archivoConsultas.ModificarConsulta(posicionConsultaArchivo, consulta)) {
        cout << "Consulta modificada exitosamente." << endl;
    } else {
        cout << "Error al modificar la consulta." << endl;
    }
}

void ConsultasManager::listarConsultas() {
    cout << ENCABEZADO_LISTADO_CONSULTAS << endl;
   listarConsultasConFiltro(sinFiltro);
}


bool ConsultasManager::sinFiltro(Consultas consulta) {
    return true;
}

bool ConsultasManager::filtroPorMascota(Consultas consulta) {
    return consulta.getIDMascotas() == idMascotaFiltro;
}

bool ConsultasManager::filtroPorRangoDeFecha(Consultas consulta) {
    return consulta.getFecha().isBetween(fechaDesdeFiltro, fechaHastaFiltro);
}

bool ConsultasManager::filtroPorSucursal(Consultas consulta) {
    return consulta.getIDSucursal() == idSucursalFiltro;
}

bool ConsultasManager::filtroPorVeterinario(Consultas consulta) {
    return consulta.getIDVeterinario() == idVeterinarioFiltro;
}

bool ConsultasManager::filtroPorCliente(Consultas consulta) {
    Mascotas mascota;
    GestorArchivo archivoMascotas("mascotas.dat");
    int cantidadRegistros = archivoMascotas.CantidadRegistrosMascotas();

    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascota = archivoMascotas.LeerMascota(i);

        if(mascota.getIDMascota() == consulta.getIDMascotas()){
            return mascota.getIDCliente() == idClienteFiltro;
        } else {
            return false;
        }
    }
}

void ConsultasManager::listarConsultasConFiltro(bool (*filtro)(Consultas)) {
    GestorArchivo archivoConsultas("consultas.dat");
    Consultas consulta;

    int totalRegistros = archivoConsultas.CantidadRegistrosConsultas();

    if (totalRegistros == 0) {
        limpiarPantalla();
        cout << "No existen registros cargados." << endl;
        return;
    }

    int filaPantalla = 4;
    int contadorRegistrosEncontrados = 0;

    imprimirEncabezadoListado();

    for (int i = 0; i < totalRegistros; i++) {
        consulta = archivoConsultas.LeerConsultas(i);

        if (filtro(consulta) && consulta.getEstado()) {
            contadorRegistrosEncontrados++;

            optional<Mascotas> mascotaOptional = mascotasManager.obtenerMascotaPorId(consulta.getIDMascotas());
            optional<Sucursales> sucursalOptional = sucursalesManager.obtenerSucursalPorId(consulta.getIDSucursal());
            optional<Veterinarios> veterinarioOptional = veterinariosManager.obtenerVeterinarioPorId(consulta.getIDVeterinario());
            optional<Tratamientos> tratamientoOptional = tratamientosManager.obtenerTratamientoPorId(consulta.getIDTratamiento());

            rlutil::locate(1, filaPantalla);    cout << consulta.getIDConsultas();
            rlutil::locate(6, filaPantalla);    cout << mascotaOptional.value().getNombre().substr(0, 13);
            rlutil::locate(20, filaPantalla);   cout << consulta.getDiagnostico().substr(0, 15);
            rlutil::locate(37, filaPantalla);   cout << (consulta.getEstado() ? "Activo" : "Baja");
            rlutil::locate(46, filaPantalla);   cout << consulta.getFecha().toString();
            rlutil::locate(59, filaPantalla);   cout << consulta.getFechaproximavisita().toString();
            rlutil::locate(76, filaPantalla);   cout << sucursalOptional.value().getNombre().substr(0, 15);
            rlutil::locate(92, filaPantalla);   cout << veterinarioOptional.value().getNombre().substr(0, 15);
            rlutil::locate(109, filaPantalla);  cout << consulta.getSintomas().substr(0, 16);
            rlutil::locate(126, filaPantalla);  cout << tratamientoOptional.value().getNombreTratamiento().substr(0, 15);

            filaPantalla++;
        }
    }

    if (contadorRegistrosEncontrados == 0) {
        limpiarPantalla();
        cout << "No existen registros que coincidan con el filtro especificado." << endl;
    }
}

void ConsultasManager::bajaConsulta() {
    bool usuarioConfirmaAccion = false;
    Consultas consulta;
    int id;

    do{
        limpiarPantalla();
        cout << ENCABEZADO_BAJA_CONSULTA << endl;
        optional<Consultas> consultaOptional = solicitarConsultaPorId();

        if(consultaOptional.has_value()){
            cout << "No existe ninguna consulta asociada a ese ID, porfavor ingrese uno valido." << endl;
            return;
        } else {
            cout << MENSAJE_AVISO_RETORNO_MENU << endl;
            return;
        }

        consulta = consultaOptional.value();

        imprimirConsulta(consulta);
        usuarioConfirmaAccion = confirmaAccion();
    }while(!usuarioConfirmaAccion);

    consulta.setEstado(false);

    GestorArchivo archivoConsultas("consultas.dat");

    int posicionConsultaArchivo = BuscarConsultaPorID(id);

    if (archivoConsultas.ModificarConsulta(posicionConsultaArchivo,consulta)) {
        cout << "Consulta dada de baja exitosamente, no aparecera mas en los listados." << endl;
    } else {
        cout << "Error al dar de baja la consulta." << endl;
    }
}

bool ConsultasManager::confirmaAccion() {
    cout << MENSAJE_CONFIRMACION_DATOS;

    Validaciones validador;
    string letra = validador.validarLetra();

    if(letra == "S" || letra == "s"){
        return true;
    }

    return false;
}

void ConsultasManager::consultarPorMascota() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_MASCOTA << endl;

    optional<Mascotas> mascotaOptional = solicitarMascotaValidada();

    if(mascotaOptional.has_value()){
        listarConsultasConFiltro(filtroPorMascota);
    } else {
        cout << MENSAJE_AVISO_RETORNO_MENU << endl;
    }
}

std::optional<Mascotas> ConsultasManager::solicitarMascotaValidada() {
    bool usuarioConfirmaAccion = false;
    optional<Mascotas> mascotasOptional = nullopt;
    int cantidadIntentosIngreso = 0;

    do {
        cantidadIntentosIngreso++;
        cout << "Ingrese ID de la mascota: ";
        Validaciones validador;
        idMascotaFiltro = validador.validarNumero();

         mascotasOptional = mascotasManager.obtenerMascotaPorId(idMascotaFiltro);

        if(mascotasOptional.has_value()){
            cout << "Mascota encontrada: " << mascotasOptional.value().getNombre() << endl;
            usuarioConfirmaAccion = confirmaAccion();

            if(usuarioConfirmaAccion){
                return mascotasOptional.value();
            }
        } else {
            cout << "No existe una mascota con el ID especificado..." << endl;
            esperarCualquierTecla();
        }
    } while (cantidadIntentosIngreso < MAXIMOS_REINTENTOS_ENTRADA_DATOS);

    if(mascotasOptional.has_value()){
         return mascotasOptional.value();
    } else {
        return std::nullopt;
   }
}

std::optional<Sucursales> ConsultasManager::solicitarSucursalValidada() {
    bool usuarioConfirmaAccion = false;
    optional<Sucursales> sucursalOptional = nullopt;
    int cantidadIntentosIngreso = 0;

    do {
        cantidadIntentosIngreso++;
        cout << "Ingrese ID de la sucursal: ";
        Validaciones validador;
        idSucursalFiltro = validador.validarNumero();
        sucursalOptional = sucursalesManager.obtenerSucursalPorId(idSucursalFiltro);

        if(sucursalOptional.has_value()){
            cout << "Sucursal encontrada: " << sucursalOptional.value().getNombre() << endl;
            usuarioConfirmaAccion = confirmaAccion();

            if(usuarioConfirmaAccion){
                return sucursalOptional.value();
            }
        } else {
            cout << "No existe una sucursal con el ID especificado..." << endl;
            esperarCualquierTecla();
        }
    } while (cantidadIntentosIngreso < MAXIMOS_REINTENTOS_ENTRADA_DATOS);

    if(sucursalOptional.has_value()){
         return sucursalOptional.value();
    } else {
        return std::nullopt;
   }
}

std::optional<Veterinarios> ConsultasManager::solicitarVeterinarioValidado() {
    bool usuarioConfirmaAccion = false;
    optional<Veterinarios> veterinarioOptional = nullopt;
    int cantidadIntentosIngreso = 0;

    do {
        cantidadIntentosIngreso++;
        cout << "Ingrese ID de veterinario: ";
        Validaciones validador;
        idVeterinarioFiltro = validador.validarNumero();
        veterinarioOptional = veterinariosManager.obtenerVeterinarioPorId(idVeterinarioFiltro);

        if(veterinarioOptional.has_value()){
            cout << "Veterinario encontrado: " << veterinarioOptional.value().getNombre() << endl;
            usuarioConfirmaAccion = confirmaAccion();

            if(usuarioConfirmaAccion){
                return veterinarioOptional.value();
            }
        } else {
            cout << "No existe un veterinario con el ID especificado..." << endl;
            esperarCualquierTecla();
        }
    } while (cantidadIntentosIngreso < MAXIMOS_REINTENTOS_ENTRADA_DATOS);

    if(veterinarioOptional.has_value()){
         return veterinarioOptional.value();
    } else {
        return std::nullopt;
   }
}

std::optional<Cliente> ConsultasManager::solicitarClienteValidado() {
    bool usuarioConfirmaAccion = false;
    optional<Cliente> clienteOptional = nullopt;
    int cantidadIntentosIngreso = 0;

    do {
        cantidadIntentosIngreso++;
        cout << "Ingrese ID de cliente: ";
        Validaciones validador;
        idClienteFiltro = validador.validarNumero();
        clienteOptional = clientesManager.obtenerClientePorId(idClienteFiltro);

        if(clienteOptional.has_value()){
            cout << "Cliente encontrado: " << clienteOptional.value().getNombre() << endl;
            usuarioConfirmaAccion = confirmaAccion();

            if(usuarioConfirmaAccion){
                return clienteOptional.value();
            }
        } else {
            cout << "No existe un cliente con el ID especificado..." << endl;
            esperarCualquierTecla();
        }
    } while (cantidadIntentosIngreso < MAXIMOS_REINTENTOS_ENTRADA_DATOS);

    if(clienteOptional.has_value()){
         return clienteOptional.value();
    } else {
        return std::nullopt;
   }
}

std::optional<Tratamientos> ConsultasManager::solicitarTratamientoValidado() {
    bool usuarioConfirmaAccion = false;
    optional<Tratamientos> tratamientoOptional = nullopt;
    int cantidadIntentosIngreso = 0;
    int idTratamiento;

    do {
        cantidadIntentosIngreso++;
        cout << "Ingrese ID de tratamiento: ";
        Validaciones validador;
        idTratamiento = validador.validarNumero();
        tratamientoOptional = tratamientosManager.obtenerTratamientoPorId(idTratamiento);

        if(tratamientoOptional.has_value()){
            cout << "Cliente encontrado: " << tratamientoOptional.value().getNombreTratamiento() << endl;
            usuarioConfirmaAccion = confirmaAccion();

            if(usuarioConfirmaAccion){
                return tratamientoOptional.value();
            }
        } else {
            cout << "No existe un tratamiento con el ID especificado..." << endl;
            esperarCualquierTecla();
        }
    } while (cantidadIntentosIngreso < MAXIMOS_REINTENTOS_ENTRADA_DATOS);

    if(tratamientoOptional.has_value()){
         return tratamientoOptional.value();
    } else {
        return std::nullopt;
   }
}

std::optional<Consultas> ConsultasManager::solicitarConsultaPorId() {
    bool usuarioConfirmaAccion = false;
    optional<Consultas> consultaOptional = nullopt;
    int cantidadIntentosIngreso = 0;
    int idConsulta;

    do {
        cantidadIntentosIngreso++;
        cout << "Ingrese ID de Consulta: ";
        Validaciones validador;

        cin.ignore();
        idConsulta = validador.validarNumero();
        consultaOptional = obtenerConsultaPorId(idConsulta);

        if(consultaOptional.has_value()){
            imprimirConsulta(consultaOptional.value());

            usuarioConfirmaAccion = confirmaAccion();

            if(usuarioConfirmaAccion){
                return consultaOptional.value();
            }
        } else {
            cout << "No existe una consulta con el ID especificado..." << endl;
            esperarCualquierTecla();
        }
    } while (cantidadIntentosIngreso < MAXIMOS_REINTENTOS_ENTRADA_DATOS);

    if(consultaOptional.has_value()){
         return consultaOptional.value();
    } else {
        return std::nullopt;
   }
}

void ConsultasManager::consultarPorFecha() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_FECHAS << endl;
    Fecha fecha;
    cout << "======================================= " << endl;
    cout << "Ingrese fecha desde: " << endl;
    fechaDesdeFiltro = fecha.ValidacionFecha(fecha);
    cout << "======================================= " << endl;
    cout << "Ingrese fecha hasta: " << endl;
    fechaHastaFiltro = fecha.ValidacionFecha(fecha);

    listarConsultasConFiltro(filtroPorRangoDeFecha);
}

void ConsultasManager::consultarPorSucursal() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_SUCURSAL << endl;

    optional<Sucursales> sucursalOptional = solicitarSucursalValidada();

    if(sucursalOptional.has_value()){
        listarConsultasConFiltro(filtroPorSucursal);
    } else {
        cout << MENSAJE_AVISO_RETORNO_MENU << endl;
    }
}

void ConsultasManager::consultarPorVeterinario() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_VETERINARIO << endl;

    optional<Veterinarios> veterinarioOptional = solicitarVeterinarioValidado();

    if(veterinarioOptional.has_value()){
        listarConsultasConFiltro(filtroPorVeterinario);
    } else {
        cout << MENSAJE_AVISO_RETORNO_MENU << endl;
    }
}

void ConsultasManager::consultarPorCliente() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_CLIENTE << endl;


    optional<Cliente> clienteOptional = solicitarClienteValidado();

    if(clienteOptional.has_value()){
        listarConsultasConFiltro(filtroPorCliente);
    } else {
        cout << MENSAJE_AVISO_RETORNO_MENU << endl;
    }
}

void ConsultasManager::imprimirEncabezadoListado() {
    rlutil::locate(1, 2);   cout << "ID";
    rlutil::locate(6, 2);   cout << "| Mascota";
    rlutil::locate(20, 2);  cout << "| Diagnostico";
    rlutil::locate(37, 2);  cout << "| Estado";
    rlutil::locate(46, 2);  cout << "| Fecha";
    rlutil::locate(59, 2);  cout << "| Prox. Visita";
    rlutil::locate(76, 2);  cout << "| Sucursal";
    rlutil::locate(92, 2);  cout << "| Veterinario";
    rlutil::locate(109, 2); cout << "| Sntomas";
    rlutil::locate(126, 2); cout << "| Tratamiento";
}

void ConsultasManager::imprimirConsulta(Consultas consulta) {
    cout << " ============== Consulta =================== " << endl;
    cout << "ID de consulta: " << consulta.getIDConsultas() << endl;
    cout << "Fecha: " << consulta.getFecha().toString() << endl;
    cout << "Sintomas: " << consulta.getSintomas() << endl;
    cout << "Diagnostico: " << consulta.getDiagnostico() << endl;
    cout << "Estado: " <<  (consulta.getEstado() ? "Activo" : "Baja") << endl;
    cout << "Fecha proxima visita: " << consulta.getFechaproximavisita().toString() << endl;

    optional<Mascotas> mascotaOptional = mascotasManager.obtenerMascotaPorId(consulta.getIDMascotas());
    optional<Sucursales> sucursalOptional = sucursalesManager.obtenerSucursalPorId(consulta.getIDSucursal());
    optional<Veterinarios> veterinarioOptional = veterinariosManager.obtenerVeterinarioPorId(consulta.getIDVeterinario());
    optional<Tratamientos> tratamientoOptional = tratamientosManager.obtenerTratamientoPorId(consulta.getIDTratamiento());

    cout << "Mascota: " << mascotaOptional.value().getNombre() << endl;
    cout << "Sucursal: " << sucursalOptional.value().getNombre() << endl;
    cout << "Veterinario: " << veterinarioOptional.value().getNombre() << endl;
    cout << "Tratamiento: " << tratamientoOptional.value().getNombreTratamiento() << endl;
    cout << " ============================================== " << endl;
}

bool ConsultasManager::esConsultaValida(Consultas consulta) {
    cout << "Atencion: Verificando los datos ingresados..." << endl;
     if(esConsultaDuplicada(consulta)){
        return false;
    }

    return true;
}

bool ConsultasManager::esConsultaDuplicada(Consultas consulta) {
    cout << "Atencion: Verificando los datos ingresados..." << endl;

    GestorArchivo archivoConsultas("consultas.dat");

    Consultas consultaFichero;
	int cantidadRegistros = archivoConsultas.CantidadRegistrosConsultas();

	for (int i = 0; i < cantidadRegistros; i++){
		consultaFichero = archivoConsultas.LeerConsultas(i);

		if(consulta.getIDConsultas() != consultaFichero.getIDConsultas()
        && consulta.getIDSucursal() == consultaFichero.getIDSucursal()
        && consulta.getIDVeterinario() == consultaFichero.getIDVeterinario()){
            return true;
        }
    }

    return false;
}

int ConsultasManager::obtenerProximoId() {
    Consultas ultimaConsulta;
	GestorArchivo archivoConsultas("consultas.dat");
	int cantidadRegistros = archivoConsultas.CantidadRegistrosConsultas();
	return cantidadRegistros + 1;
}

int ConsultasManager::BuscarConsultaPorID(int idBuscado) {
    GestorArchivo archivoConsultas("consultas.dat");
    Consultas consulta;
    int total = archivoConsultas.CantidadRegistrosConsultas();

    for (int i = 0; i < total; i++) {
        consulta = archivoConsultas.LeerConsultas(i);
        if (consulta.getIDConsultas() == idBuscado) return i;
    }

    cout << "Consulta con ID " << idBuscado << " no encontrada.\n";
    return -1;
}

std::optional<Consultas> ConsultasManager::obtenerConsultaPorId(int idBuscado){
    GestorArchivo archivoConsultas("consultas.dat");
    Consultas consulta;
	int cantidadRegistros = archivoConsultas.CantidadRegistrosConsultas();

	for (int i = 0; i < cantidadRegistros; i++)
        {
		consulta = archivoConsultas.LeerConsultas(i);

		if (consulta.getIDConsultas() == idBuscado){
            return consulta;
        }
    }

    return std::nullopt;
}
