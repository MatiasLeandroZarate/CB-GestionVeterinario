#include "ConsultasManager.h"
#include "MascotaManager.h"
#include "SucursalManager.h"
#include "VeterinariosManager.h"
#include "TratamientosManager.h"

using namespace std;

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

    do{
        cout << "A continuacion debera ingresar los datos del nuevo registro de consulta medica..." << endl;
        esperarCualquierTecla();
        limpiarPantalla();

        cout << "========== Alta de consulta medica ==========" << endl;
        cout << "Ingrese el ID de la Mascota: ";
        cin >> idMascota;

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

        nuevaConsultaEsValida = validarNuevaConsulta(consulta);

        if(nuevaConsultaEsValida){
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
    int id;
    cout << "Ingrese el ID de la consulta a modificar: ";
    cin >> id;

    GestorArchivo archivo("consultas.dat");
    int pos = BuscarConsultaPorID(id);
    if (pos == -1) return;

    Consultas consulta = archivo.LeerConsultas(pos);

    string nuevoDiagnostico;
    cout << "Diagnóstico actual: " << consulta.getDiagnostico() << "\n";
    cout << "Nuevo diagnóstico: ";
    cin.ignore();
    getline(cin, nuevoDiagnostico);

    consulta.setDiagnostico(nuevoDiagnostico);
    archivo.GuardarConsultas(consulta);

    cout << "Consulta modificada con éxito.\n";
}

void ConsultasManager::listarConsultas() {
    GestorArchivo archivoConsultas("consultas.dat");
    Consultas consulta;

    int totalRegistros = archivoConsultas.CantidadRegistrosConsultas();

    if (totalRegistros == 0) {
        cout << "No hay consultas registradas.\n";
        return;
    }

    for (int i = 0; i < totalRegistros; i++) {
        consulta = archivoConsultas.LeerConsultas(i);
        cout << consulta.toCSV() << endl;
    }
}

void ConsultasManager::bajaConsulta() {
    int id;
    cout << "Ingrese el ID de la consulta a dar de baja: ";
    cin >> id;

    GestorArchivo archivoConsultas("consultas.dat");
    int pos = BuscarConsultaPorID(id);
    if (pos == -1) return;

    Consultas consulta = archivoConsultas.LeerConsultas(pos);
    consulta.setEstado(false);

    if (archivoConsultas.GuardarConsultas(consulta)) {
        cout << "Consulta dada de baja exitosamente." << endl;
    } else {
        cout << "Error al dar de baja la consulta." << endl;
    }
}

void ConsultasManager::consultarPorMascota() {
    int idMascota;
    cout << "Ingrese ID de la mascota: ";
    cin >> idMascota;

    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDMascotas() == idMascota) {
            cout << consulta.toCSV() << endl;
            encontrado = true;
        }
    }

    if (!encontrado) cout << "No se encontraron consultas para la mascota indicada.\n";
}

void ConsultasManager::consultarPorFecha() {
    Fecha f;
    f = f.ValidacionFecha(f);

    GestorArchivo archivoConsultas("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < archivoConsultas.CantidadRegistrosConsultas(); i++) {
        consulta = archivoConsultas.LeerConsultas(i);
        if (consulta.getFecha().getAnio() == f.getAnio()
            && consulta.getFecha().getMes() == f.getMes()
            && consulta.getFecha().getAnio() == f.getAnio()) {
            cout << consulta.toCSV() << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron consultas en esa fecha." << endl;
    }
}

void ConsultasManager::consultarPorSucursal() {
    int id;
    cout << "Ingrese el ID de la sucursal: ";
    cin >> id;

    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDSucursal() == id) {
            cout << consulta.toCSV() << endl;
            encontrado = true;
        }
    }

    if (!encontrado) cout << "No se encontraron consultas para esa sucursal.\n";
}

void ConsultasManager::consultarPorVeterinario() {
    int id;
    cout << "Ingrese el ID del veterinario: ";
    cin >> id;

    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDVeterinario() == id) {
            cout << consulta.toCSV() << endl;
            encontrado = true;
        }
    }

    if (!encontrado) cout << "No se encontraron consultas para ese veterinario.\n";
}

void ConsultasManager::consultarPorCliente() {
    int id;
    cout << "Ingrese el ID del cliente: ";
    cin >> id;

    GestorArchivo archivo("consultas.dat");
    GestorArchivo archivoMascotas("mascotas.dat");

    Consultas consulta;
    bool encontrado = false;

    /*
    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        consulta.getIDMascotas()
        if (consulta.getIDMascotas() == id) {
            cout << consulta.toCSV() << endl;
            encontrado = true;
        }
    }
    */

    if (!encontrado) cout << "No se encontraron consultas para ese cliente.\n";
}

void ConsultasManager::imprimirListado() {
    cout << "ID Consulta | Mascota ID | Diagnostico | Estado | Fecha | Fecha proxima visita | Sucursal | Veterinario | Sintomas | Tratamiento";
}

void ConsultasManager::imprimirConsulta(Consultas consulta) {
    cout << " ===== Consulta ====" << endl;
    cout << "ID de consulta: " << consulta.getIDConsultas() << endl;
    cout << "Fecha: " << consulta.getFecha().toString() << endl;
    cout << "Sintomas: " << consulta.getSintomas() << endl;
    cout << "Diagnostico: " << consulta.getDiagnostico() << endl;
    cout << "Estado: " << consulta.getEstado() << endl;
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

bool ConsultasManager::validarNuevaConsulta(Consultas consulta) {
    cout << " ------- Verificando los datos ingresados... -------" << endl;
    //Validar que la mascota cliente no tenga otra consulta para el mismo dia y veterinario.
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
