#include "VacunasManager.h"

void VacunasManager::CargarVacunas()
{
	Vacunas vacuna;
	GestorArchivo vArchivo("vacunas.dat");

	int IDVacuna;
	std::string nombrevacuna, descripcion, serial; 
	
	std::cout << "Ingrese el ID de la Vacuna: ";
	std::cin >> IDVacuna;
	std::cout << "Ingrese el Nombre de la Vacuna: ";
	std::cin.ignore();
	std::getline(std::cin,nombrevacuna);
	std::cout << "Ingrese la Descripcion: ";
	std::getline(std::cin,descripcion);
	std::cout << "Ingrese el Serial: ";
	std::getline(std::cin, serial);


	vacuna = Vacunas(IDVacuna, nombrevacuna, descripcion, serial);

	if (vArchivo.GuardarVacunas(vacuna))
	{
		std::cout << std::endl;
		std::cout << "La Vacuna fue guardada correctamente." << std::endl;
	}
	else
	{
		std::cout << "Error al guardar la Vacuna." << std::endl;
	}
}


void VacunasManager::MostrarVacunas()
{
	Vacunas vacuna;
	GestorArchivo vArchivo("vacunas.dat");
	int cantidadregistros = vArchivo.CantidadRegistrosVacunas();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Pagos registrados." << std::endl;
	}

	for (int i = 0; i < cantidadregistros; i++)
	{
		vacuna = vArchivo.LeerVacunas(i);
		std::cout << vacuna.toCSV() << std::endl;
	}
}


int VacunasManager::BuscarVacunasPorID(int idBuscado)
{
	Vacunas vacuna;
	GestorArchivo vArchivo("vacunas.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVacunas();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		vacuna = vArchivo.LeerVacunas(i);
		if (vacuna.getIDVacuna() == idBuscado)
		{
			return i;
		}
	}
	std::cout << "No se encontró el ID de la Vacuna." << std::endl;
	return -1;
}
