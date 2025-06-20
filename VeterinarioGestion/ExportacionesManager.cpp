#include "ExportacionesManager.h"

using namespace std;

void ExportacionesManager::mostrarMensajeNoRegistros(){
    cout << "No existen ningun registro para la opcion seleccionada..." << endl;
}

void ExportacionesManager::exportarClientes(){
	GestorArchivo archivoClientes("clientes.dat");

	int cantidadRegistros = archivoClientes.CantidadRegistrosClientes();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Cliente cliente;
    cout << cliente.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		cliente = archivoClientes.LeerClientes(i);
        cout << cliente.toCSV() << endl;
    }
}

void ExportacionesManager::exportarConsultas(){

}

void ExportacionesManager::exportarEspecialidades(){
}

void ExportacionesManager::exportarMascotas(){

}

void ExportacionesManager::exportarPagos(){

}

void ExportacionesManager::exportarSucursales(){

}

void ExportacionesManager::exportarTratamientos(){

}

void ExportacionesManager::exportarVacunaciones(){

}

void ExportacionesManager::exportarVacunas(){

}

void ExportacionesManager::exportarVeterinarios(){

}
