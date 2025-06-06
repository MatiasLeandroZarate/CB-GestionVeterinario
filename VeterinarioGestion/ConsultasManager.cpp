#include "ConsultasManager.h"

void ConsultasManager::altaConsulta() {
return;
}

void ConsultasManager::listarConsultas() {
return;
}

void ConsultasManager::modificarConsulta() {
    int id;
    std::cout << "Ingrese el ID de la consulta a modificar: ";
    std::cin >> id;

    GestorArchivo cArchivo("consultas.dat");
    int pos = BuscarConsultaPorID(id);
    if (pos == -1) return;

    Consultas consulta = cArchivo.LeerConsultas(pos);

    std::string nuevoDiagnostico;
    std::cout << "Diagnóstico actual: " << consulta.getDiagnostico() << std::endl;
    std::cout << "Ingrese el nuevo diagnóstico: ";
    std::cin.ignore();
    std::getline(std::cin, nuevoDiagnostico);

    consulta.setDiagnostico(nuevoDiagnostico);

    if (cArchivo.GuardarConsultas(consulta)) {
        std::cout << "Consulta modificada exitosamente." << std::endl;
    } else {
        std::cout << "Error al modificar la consulta." << std::endl;
    }
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
    std::cout << "Ingrese el ID de la mascota: ";
    std::cin >> idMascota;

    GestorArchivo cArchivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < cArchivo.CantidadRegistrosConsultas(); i++) {
        consulta = cArchivo.LeerConsultas(i);
        if (consulta.getIDMascotas() == idMascota) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron consultas para esa mascota." << std::endl;
    }
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
    int idSucursal;
    std::cout << "Ingrese el ID de la sucursal: ";
    std::cin >> idSucursal;

    GestorArchivo cArchivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < cArchivo.CantidadRegistrosConsultas(); i++) {
        consulta = cArchivo.LeerConsultas(i);
        if (consulta.getIDSucursal() == idSucursal) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron consultas para esa sucursal." << std::endl;
    }
}

void ConsultasManager::consultarPorVeterinario() {
    int idVet;
    std::cout << "Ingrese el ID del veterinario: ";
    std::cin >> idVet;

    GestorArchivo cArchivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;

    for (int i = 0; i < cArchivo.CantidadRegistrosConsultas(); i++) {
        consulta = cArchivo.LeerConsultas(i);
        if (consulta.getIDVeterinario() == idVet) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron consultas para ese veterinario." << std::endl;
    }
}

void ConsultasManager::consultarPorCliente() {
    int idCliente;
    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> idCliente;

    GestorArchivo cArchivo("consultas.dat");
    Consultas consulta;
    bool encontrado = false;
    /*
    for (int i = 0; i < cArchivo.CantidadRegistrosConsultas(); i++) {
        consulta = cArchivo.LeerConsultas(i);
        if (consulta.getI() == idCliente) {
            std::cout << consulta.toCSV() << std::endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron consultas para ese cliente." << std::endl;
    }
    */
}

int ConsultasManager::BuscarConsultaPorID(int idBuscado) {
    Consultas consulta;
    GestorArchivo cArchivo("consultas.dat");
    int cantidadRegistros = cArchivo.CantidadRegistrosConsultas();

    for (int i = 0; i < cantidadRegistros; i++) {
        consulta = cArchivo.LeerConsultas(i);
        if (consulta.getIDConsultas() == idBuscado) {
            return i;
        }
    }

    std::cout << "No se encontró el ID de la Consulta." << std::endl;
    return -1;
}
