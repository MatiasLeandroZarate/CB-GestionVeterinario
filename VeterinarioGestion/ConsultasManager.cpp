#include "ConsultasManager.h"

void ConsultasManager::altaConsulta() {
    Consultas consulta;
    GestorArchivo cArchivo("consultas.dat");
    GestorArchivo tArchivo("tratamientos.dat");
    TratamientosManager tManager;
    Tratamientos tratamiento;

    Fecha fechaConsulta, fechaProximaVisita, validadorFecha;
    int idConsulta, idMascota, idTratamiento, idVeterinario, idSucursal;
    std::string sintomas, diagnostico;
    std::cout << "Ingrese el ID de la Mascota: ";
    std::cin >> idMascota;
    std::cout << "Ingrese la Fecha de la Consulta:\n";
    fechaConsulta = validadorFecha.ValidacionFecha(fechaConsulta);

    std::cin.ignore();
    std::cout << "Ingrese los Sintomas: ";
    std::getline(std::cin, sintomas);
    std::cout << "Ingrese el Diagnostico: ";
    std::getline(std::cin, diagnostico);

    std::cout << "Ingrese el ID del Tratamiento: ";
    std::cin >> idTratamiento;

    int posTrat = tManager.BuscarTratamientoPorID(idTratamiento);
    if (posTrat == -1) {
        int opcion;
        std::cout << "Tratamiento no encontrado. ¿Desea darlo de alta? (1=Sí, 2=No): ";
        std::cin >> opcion;
        if (opcion == 1) {
            tManager.CargarTratamiento();
        } else {
            std::cout << "No se cargó tratamiento.\n";
            return;
        }
    } else {
        tratamiento = tArchivo.LeerTratamientos(posTrat);
    }

    std::cout << "Ingrese la Fecha de la Próxima Visita:\n";
    fechaProximaVisita = validadorFecha.ValidacionFecha(fechaProximaVisita);

    std::cout << "Ingrese el ID del Veterinario: ";
    std::cin >> idVeterinario;
    std::cout << "Ingrese el ID de la Sucursal: ";
    std::cin >> idSucursal;

    idConsulta = 1;
    consulta = Consultas(idConsulta, idMascota, fechaConsulta, sintomas, diagnostico, tratamiento, fechaProximaVisita, idVeterinario, idSucursal);

    if (cArchivo.GuardarConsultas(consulta)) {
        std::cout << "\nConsulta registrada exitosamente.\n";
    } else {
        std::cout << "\nError al guardar la consulta.\n";
    }
}

void ConsultasManager::listarConsultas() {
    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    int total = archivo.CantidadRegistrosConsultas();

    if (total == 0) {
        std::cout << "No hay consultas registradas.\n";
        return;
    }

    std::cout << "\nIDConsulta,IDMascota,Fecha,Sintomas,Diagnostico,IDTratamiento,NombreTratamiento,DescTratamiento,Duracion,Costo,FechaProximaVisita,IDVeterinario,IDSucursal\n";
    for (int i = 0; i < total; i++) {
        consulta = archivo.LeerConsultas(i);
        std::cout << consulta.toCSV() << std::endl;
    }
}

void ConsultasManager::modificarConsulta() {
    int id;
    std::cout << "Ingrese el ID de la consulta a modificar: ";
    std::cin >> id;

    GestorArchivo archivo("consultas.dat");
    int pos = BuscarConsultaPorID(id);
    if (pos == -1) return;

    Consultas consulta = archivo.LeerConsultas(pos);

    std::string nuevoDiagnostico;
    std::cout << "Diagnóstico actual: " << consulta.getDiagnostico() << "\n";
    std::cout << "Nuevo diagnóstico: ";
    std::cin.ignore();
    std::getline(std::cin, nuevoDiagnostico);

    consulta.setDiagnostico(nuevoDiagnostico);
    archivo.GuardarConsultas(consulta);

    std::cout << "Consulta modificada con éxito.\n";
}

void ConsultasManager::bajaConsulta() {
    int id;
    std::cout << "Ingrese el ID de la consulta a dar de baja: ";
    std::cin >> id;

    GestorArchivo cArchivo("consultas.dat");
    int pos = BuscarConsultaPorID(id);
    if (pos == -1) return;

    Consultas consulta = cArchivo.LeerConsultas(pos);
    consulta.setEstado(false);

    if (cArchivo.GuardarConsultas(consulta)) {
        std::cout << "Consulta dada de baja exitosamente." << std::endl;
    } else {
        std::cout << "Error al dar de baja la consulta." << std::endl;
    }
}

void ConsultasManager::consultarPorMascota() {
    int idMascota;
    std::cout << "Ingrese ID de la mascota: ";
    std::cin >> idMascota;

    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDMascotas() == idMascota) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) std::cout << "No se encontraron consultas para la mascota indicada.\n";
}

void ConsultasManager::consultarPorFecha() {
    Fecha f;
    f = f.ValidacionFecha(f);

    GestorArchivo cArchivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < cArchivo.CantidadRegistrosConsultas(); i++) {
        consulta = cArchivo.LeerConsultas(i);
        if (consulta.getFecha().getAnio() == f.getAnio()
            && consulta.getFecha().getMes() == f.getMes()
            && consulta.getFecha().getAnio() == f.getAnio()) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron consultas en esa fecha." << std::endl;
    }
}

void ConsultasManager::consultarPorSucursal() {
    int id;
    std::cout << "Ingrese el ID de la sucursal: ";
    std::cin >> id;

    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDSucursal() == id) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) std::cout << "No se encontraron consultas para esa sucursal.\n";
}

void ConsultasManager::consultarPorVeterinario() {
    int id;
    std::cout << "Ingrese el ID del veterinario: ";
    std::cin >> id;

    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDVeterinario() == id) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) std::cout << "No se encontraron consultas para ese veterinario.\n";
}

void ConsultasManager::consultarPorCliente() {
    int id;
    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> id;

    GestorArchivo archivo("consultas.dat");
    GestorArchivo archivoMascotas("mascotas.dat");

    Consultas consulta;
    bool encontrado = false;

    /*
    for (int i = 0; i < archivo.CantidadRegistrosConsultas(); i++) {
        consulta = archivo.LeerConsultas(i);
        consulta.getIDMascotas()
        if (consulta.getIDMascotas() == id) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }
    */

    if (!encontrado) std::cout << "No se encontraron consultas para ese cliente.\n";
}

int ConsultasManager::BuscarConsultaPorID(int idBuscado) {
    GestorArchivo archivo("consultas.dat");
    Consultas consulta;
    int total = archivo.CantidadRegistrosConsultas();

    for (int i = 0; i < total; i++) {
        consulta = archivo.LeerConsultas(i);
        if (consulta.getIDConsultas() == idBuscado) return i;
    }

    std::cout << "Consulta con ID " << idBuscado << " no encontrada.\n";
    return -1;
}
