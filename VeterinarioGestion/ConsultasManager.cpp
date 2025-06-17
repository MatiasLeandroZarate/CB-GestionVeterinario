#include "ConsultasManager.h"
#include "MascotaManager.h"
#include "SucursalManager.h"
#include "VeterinariosManager.h"
#include "TratamientosManager.h"
#include "Validaciones.h"

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

const string MENSAJE_CONFIRMACION_DATOS = "========== Confirma que los datos y la accion a realizar son correctos? (S/N) ==========";

int ConsultasManager::idMascotaFiltro = 0;
Fecha ConsultasManager::fechaDesdeFiltro = Fecha();
Fecha ConsultasManager::fechaHastaFiltro = Fecha();
int ConsultasManager::idSucursalFiltro = 0;
int ConsultasManager::idVeterinarioFiltro = 0;
int ConsultasManager::idClienteFiltro = 0;

void ConsultasManager::altaConsulta() {
    GestorArchivo archivoConsultas("consultas.dat");
    TratamientosManager tratatamientosManager;

    int idMascota, idTratamiento, idVeterinario, idSucursal;
    int diaConsulta, mesConsulta, anioConsulta;
    int diaProximaConsulta, mesProximaConsulta, anioProximaConsulta;

    string sintomas, diagnostico;
    bool registraProximaVisita, nuevaConsultaEsValida, aceptaNuevoRegistro;
    char respuestaProximaVisita;

    Tratamientos tratamiento;
    Veterinarios veterinario;
    Sucursales Sucursales;
    Fecha fechaConsulta, fechaProximaVisita;

    Validaciones validador;

    do{
        cout << ENCABEZADO_ALTA_CONSULTA << endl;
        cout << "Ingrese el ID de la Mascota: ";
        idMascota = validador.validarNumero();

        optional<Mascotas> mascotaOptional = mascotasManager.obtenerMascotaPorId(idMascota);

        if(!mascotaOptional.has_value()){
            cout << "La mascota ingresada no existe" << endl;
            break;
        } else {
            cout << "La mascota encontrada es: " << mascotaOptional.value().getNombre() << endl;
            //Confirmar o reingresar...
        };

        //Validar y confirmar mascota.

        cout << "Ingrese la fecha de la consulta: " << endl;
        cout << "Dia: ";
        cin >> diaConsulta;
        cout << endl;

        cout << "Mes:";
        cin >> mesConsulta;
        cout << endl;

        cout << "Anio:";
        cin >> anioConsulta;
        cout << endl;

        fechaConsulta = Fecha(diaConsulta,mesConsulta,anioConsulta);
        //Validar y confirmar fecha consulta.

        cin.ignore();

        cout << "Ingrese los sintomas: ";
        getline(cin, sintomas);

        cout << "Ingrese el diagnostico: ";
        getline(cin, diagnostico);

        cout << "Ingrese el ID del Tratamiento: ";
        cin >> idTratamiento;
        //Validar y confirmar tratamiento.

        cout << "Ingrese el ID del veterinario: ";
        cin >> idVeterinario;
        //Validar y confirmar veterinario.

        cout << "Ingrese el ID de la sucursal: ";
        cin >> idSucursal;
        //Validar y confirmar sucursal.

        cout << "Desea registrar una proxima visita? (S/N): ";
        cin >> respuestaProximaVisita;

        if(respuestaProximaVisita == 'S')
        {
            cout << "Ingrese la Fecha de la proxima visita: ";
            cout << "-> Ingrese la fecha de la consulta: ";
            cout << "Ingrese dia: ";
            cin >> diaProximaConsulta;

            cout << "Ingrese mes:";
            cin >> mesProximaConsulta;

            cout << "Ingrese año:";
            cin >> anioProximaConsulta;
            cout << endl;

            fechaProximaVisita = Fecha(diaProximaConsulta, mesProximaConsulta, anioProximaConsulta);
            //Validar y confirmar fecha consulta.
        }

        Consultas consulta = Consultas(obtenerProximoId(), idMascota, fechaConsulta, sintomas, diagnostico, idTratamiento, fechaProximaVisita, idVeterinario, idSucursal);

        nuevaConsultaEsValida = esConsultaValida(consulta);

        if(nuevaConsultaEsValida){
            cout << MENSAJE_CONFIRMACION_DATOS << endl;
            imprimirConsulta(consulta);

            aceptaNuevoRegistro = true;

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
            cout << "Porfavor, corrija los datos indicados, e intente nuevamente.";
            esperarCualquierTecla();
        }

        if(!aceptaNuevoRegistro){
            limpiarPantalla();
        }
    } while(!nuevaConsultaEsValida || !aceptaNuevoRegistro);
}

void ConsultasManager::modificarConsulta() {
    cout << ENCABEZADO_MODIFICACION_CONSULTA << endl;
    int id;
    cout << "Ingrese el ID de la consulta a modificar: ";
    cin >> id;

    GestorArchivo archivo("consultas.dat");
    int pos = BuscarConsultaPorID(id);
    if (pos == -1) return;

    Consultas consulta = archivo.LeerConsultas(pos);

    string nuevoDiagnostico;
    cout << "Diagnostico actual: " << consulta.getDiagnostico() << "\n";
    cout << "Nuevo diagnóstico: ";
    cin.ignore();
    getline(cin, nuevoDiagnostico);

    consulta.setDiagnostico(nuevoDiagnostico);
    archivo.GuardarConsultas(consulta);

    cout << "Consulta modificada con exito.\n";
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
        cout << "Ingrese el ID de la consulta a dar de baja: ";
        cin >> id;

        optional<Consultas> consultaOptional = obtenerConsultaPorId(id);


        if(!consultaOptional.has_value()){
            cout << "No existe ninguna consulta asociada a ese ID, porfavor ingrese uno valido." << endl;
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
    cout << MENSAJE_CONFIRMACION_DATOS << endl;
    Validaciones validador;
    string letra = validador.validarLetra();

    if(letra == "S" || letra == "s"){
        return true;
    }

    return false;
}


void ConsultasManager::consultarPorMascota() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_MASCOTA << endl;
    cout << "Ingrese ID de la mascota: ";
    Validaciones validador;
    idMascotaFiltro = validador.validarNumero();
    listarConsultasConFiltro(filtroPorMascota);
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
    cout << "Ingrese el ID de la sucursal: ";
    cin >> idSucursalFiltro;

    optional<Sucursales> sucursalOptional = sucursalesManager.obtenerSucursalPorId(idSucursalFiltro);

    if(!sucursalOptional.has_value()){
        cout << "No existe una sucursal con el ID especificado." << endl;
        return;
    }

    listarConsultasConFiltro(filtroPorSucursal);
}

void ConsultasManager::consultarPorVeterinario() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_VETERINARIO << endl;
    cout << "Ingrese el ID del veterinario: ";
    cin >> idVeterinarioFiltro;
    listarConsultasConFiltro(filtroPorVeterinario);
}

void ConsultasManager::consultarPorCliente() {
    cout << ENCABEZADO_LISTADO_CONSULTAS_POR_CLIENTE << endl;
    cout << "Ingrese el ID del cliente: ";
    cin >> idClienteFiltro;
    listarConsultasConFiltro(filtroPorCliente);
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
    cout << "ID de consulta: " << consulta.getIDConsultas() << endl;
    cout << "Fecha: " << consulta.getFecha().toString() << endl;
    cout << "Sintomas: " << consulta.getSintomas() << endl;
    cout << "Diagnostico: " << consulta.getDiagnostico() << endl;
    cout << "Estado: " <<  (consulta.getEstado() ? "Activo" : "Baja");
    cout << "Fecha proxima visita: " << consulta.getFechaproximavisita().toString() << endl;

    optional<Mascotas> mascotaOptional = mascotasManager.obtenerMascotaPorId(consulta.getIDMascotas());
    optional<Sucursales> sucursalOptional = sucursalesManager.obtenerSucursalPorId(consulta.getIDSucursal());
    optional<Veterinarios> veterinarioOptional = veterinariosManager.obtenerVeterinarioPorId(consulta.getIDVeterinario());
    optional<Tratamientos> tratamientoOptional = tratamientosManager.obtenerTratamientoPorId(consulta.getIDTratamiento());

    cout << "Mascota: " << mascotaOptional.value().getNombre() << endl;
    cout << "Sucursal: " << sucursalOptional.value().getNombre() << endl;
    cout << "Veterinario: " << veterinarioOptional.value().getNombre() << endl;
    cout << "Tratamiento: " << tratamientoOptional.value().getNombreTratamiento() << endl;
}

bool ConsultasManager::esConsultaValida(Consultas consulta) {
    cout << "Atencion: Verificando los datos ingresados..." << endl;
    //Validar que la mascota no tenga otra consulta para el mismo dia, sucursal y veterinario.
   //  if(esConsultaDuplicada(consulta)){
   //     return false;
   // }

    return true;
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
