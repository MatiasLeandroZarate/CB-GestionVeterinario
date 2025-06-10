#include "ConsultasManager.h"

using namespace std;

void ConsultasManager::altaConsulta() {
    GestorArchivo archivoConsultas("consultas.dat");
    GestorArchivo archivoTratamientos("tratamientos.dat");
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

    cout << "---- Alta de consulta medica ----" << endl;
    cout << "A continuacion debera ingresar los datos del nuevo registro de consulta medica..." << endl;
    esperarCualquierTecla();
    limpiarPantalla();

    cout << "Ingrese el ID de la Mascota: ";
    cin >> idMascota;

    cout << "-> Ingrese la fecha de la consulta: ";
    cout << "Ingrese dia: ";
    cin >> diaConsulta;
    cout << endl;

    cout << "Ingrese mes:";
    cin >> mesConsulta;
    cout << endl;

    cout << "Ingrese año:";
    cin >> anioConsulta;
    cout << endl;

    fechaConsulta = Fecha(diaConsulta,mesConsulta,anioConsulta);

    cin.ignore();

    cout << "Ingrese los sintomas: ";
    getline(cin, sintomas);

    cout << "Ingrese el diagnostico: ";
    getline(cin, diagnostico);

    cout << "Ingrese el ID del Tratamiento: ";
    cin >> idTratamiento;

    cout << "Ingrese el ID del veterinario: ";
    cin >> idVeterinario;

    cout << "Ingrese el ID de la sucursal: ";
    cin >> idSucursal;

    cout << "Desea registrar una proxima visita? (S/N)";
    cin >> respuestaProximaVisita;

    if(respuestaProximaVisita == 'S')
    {
        cout << "Ingrese la Fecha de la proxima visita: ";
        cout << "-> Ingrese la fecha de la consulta: ";
        cout << "Ingrese dia: ";
        cin >> diaProximaConsulta;
        cout << endl;

        cout << "Ingrese mes:";
        cin >> mesProximaConsulta;
        cout << endl;

        cout << "Ingrese año:";
        cin >> anioProximaConsulta;
        cout << endl;

        fechaProximaVisita = Fecha(diaProximaConsulta, mesProximaConsulta, anioProximaConsulta);
    }

    Consultas consulta = Consultas(1, idMascota, fechaConsulta, sintomas, diagnostico, tratamiento, fechaProximaVisita, idVeterinario, idSucursal);

    nuevaConsultaEsValida = validarNuevaConsulta(consulta);

    if(nuevaConsultaEsValida){
        aceptaNuevoRegistro = confirmarVistaPrevia(consulta);

        if(aceptaNuevoRegistro){
          if (archivoConsultas.GuardarConsultas(consulta)) {
                cout << "Consulta registrada exitosamente.";
            } else {
                cout << "Ocurrio un error al guardar la consulta, intente de nuevo mas tarde.";
            }
        } else {

        }
    } else {
        cout << "Porfavor, corrija los datos indicados, e intente nuevamente.";
    }
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
    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    int total = archivo.CantidadRegistrosConsultas();

    if (total == 0) {
        cout << "No hay consultas registradas.\n";
        return;
    }

    cout << "\nIDConsulta,IDMascota,Fecha,Sintomas,Diagnostico,IDTratamiento,NombreTratamiento,DescTratamiento,Duracion,Costo,FechaProximaVisita,IDVeterinario,IDSucursal\n";
    for (int i = 0; i < total; i++) {
        consulta = archivo.LeerConsultas(i);
        cout << consulta.toCSV() << std::endl;
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
        cout << "Consulta dada de baja exitosamente." << std::endl;
    } else {
        cout << "Error al dar de baja la consulta." << std::endl;
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
            cout << consulta.toCSV() << std::endl;
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
            cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron consultas en esa fecha." << std::endl;
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
            cout << consulta.toCSV() << std::endl;
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
            cout << consulta.toCSV() << std::endl;
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
            cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }
    */

    if (!encontrado) cout << "No se encontraron consultas para ese cliente.\n";
}

int ConsultasManager::BuscarConsultaPorID(int idBuscado) {
    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    int total = archivo.CantidadRegistrosConsultas();

/*    for (int i = 0; i < archivo.CantidadRegistrosConsultas(; i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDConsultas() == idBuscado) return i;
    } */

    cout << "Consulta con ID " << idBuscado << " no encontrada.\n";
    return -1;
}

void ConsultasManager::imprimirEncabezadoListado() {
    cout << "ID Mascota | AAA | BBB | CCC";
}

bool ConsultasManager::confirmarVistaPrevia(Consultas consulta) {
    cout << " ------- Se dara de alta la siguiente consulta, porfavor confirme -------";
    cout << consulta.getIDMascotas();
    cout << consulta.getDiagnostico();
    cout << consulta.getEstado();
    cout << consulta.getFecha().toString();
    cout << consulta.getFechaproximavisita().toString();
    cout << consulta.getIDConsultas();
    cout << consulta.getIDSucursal();
    cout << consulta.getIDVeterinario();
    cout << consulta.getSintomas();
    cout << consulta.getTratamiento().getIDTratamiento();
}

bool ConsultasManager::validarNuevaConsulta(Consultas consulta) {
    cout << " ------- Verificando los datos ingresados... -------";
}


