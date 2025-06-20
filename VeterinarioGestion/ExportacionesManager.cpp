#include "ExportacionesManager.h"

using namespace std;

void ExportacionesManager::mostrarMensajeNoRegistros(){
    cout << "No existen ningun registro para la opcion seleccionada..." << endl;
}

void ExportacionesManager::exportarClientes(){
	GestorArchivo archivo("clientes.dat");

	int cantidadRegistros = archivo.CantidadRegistrosClientes();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Cliente entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerClientes(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarConsultas(){
    GestorArchivo archivo("consultas.dat");

	int cantidadRegistros = archivo.CantidadRegistrosConsultas();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Consultas entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerConsultas(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarEspecialidades(){
    GestorArchivo archivo("especialidades.dat");

	int cantidadRegistros = archivo.CantidadRegistrosEspecialidades();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Especialidades entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerEspecialidad(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarMascotas(){
    GestorArchivo archivo("mascotas.dat");

	int cantidadRegistros = archivo.CantidadRegistrosMascotas();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Mascotas entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerMascota(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarPagos(){
    GestorArchivo archivo("pagos.dat");

	int cantidadRegistros = archivo.CantidadRegistrosPagos();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Pagos entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerPagos(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarSucursales(){
    GestorArchivo archivo("sucursales.dat");

	int cantidadRegistros = archivo.CantidadRegistrosSucursales();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Sucursales entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerSucursal(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarTratamientos(){
    GestorArchivo archivo("tratamientos.dat");

	int cantidadRegistros = archivo.CantidadRegistrosTratamientos();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Tratamientos entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerTratamientos(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarVacunaciones(){
    GestorArchivo archivo("vacunaciones.dat");

	int cantidadRegistros = archivo.CantidadRegistrosVacunaciones();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Vacunaciones entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerVacunaciones(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarVacunas(){
    GestorArchivo archivo("vacunas.dat");

	int cantidadRegistros = archivo.CantidadRegistrosVacunas();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Vacunas entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerVacunas(i);
        cout << entidad.toCSV() << endl;
    }
}

void ExportacionesManager::exportarVeterinarios(){
    GestorArchivo archivo("veterinarios.dat");

	int cantidadRegistros = archivo.CantidadRegistrosVeterinario();

	if(cantidadRegistros <= 0){
        mostrarMensajeNoRegistros();
        return;
	}

    Veterinarios entidad;
    cout << entidad.toCSVHeader() << endl;

	for (int i = 0; i < cantidadRegistros; i++)
        {
		entidad = archivo.LeerVeterinario(i);
        cout << entidad.toCSV() << endl;
    }
}
