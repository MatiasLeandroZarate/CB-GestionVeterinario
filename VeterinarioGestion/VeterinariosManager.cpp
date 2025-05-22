#include "VeterinariosManager.h"


void VeterinariosManager::CargarVeterinarios()
{
	Veterinarios veterinarios;
	Especialidades especialidad(0, "", "");
	EspecialidadManager eManager;

	GestorArchivo vArchivo("veterinarios.dat");
	GestorArchivo eArchivo("especialidades.dat");
	int idveterinario, matricula, idespecialidad;
	std::string DNI = "", Nombre, Apellido; 
	bool activo;

	std::cout << "Ingrese el ID del Veterinario: ";
	std::cin >> idveterinario;
	std::cout << "Ingrese la Matricula del Veterinario: ";
	std::cin >> matricula;
	std::cout << "Ingrese el ID especialidad: ";
	std::cin >> idespecialidad;
	std::cout << "Ingrese el Nombre: ";
	std::cin.ignore();
	std::getline(std::cin, Nombre);
	std::cout << "Ingrese el Apellido: ";
	std::getline(std::cin, Apellido);
	std::cout << "Ingrese 1 si esta Activo o 0 para inactivo): ";
	std::cin >> activo;

	int posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);
	if (posEspecialidad == -1)
	{
		bool crear;
		std::cout << "No se encontro la especialidad." << std::endl;
		std::cout << "Desea agregar una especialidad? 1- Si . 2- No: ";
		std::cin >> crear;
		if (crear == 1)
		{
			eManager.CargarEspecialidad();
		}
		else
		{
			std::cout << "No se cargo ninguna especialidad." << std::endl;
		}	
	}
	else
	{
		
		especialidad = eArchivo.LeerEspecialidad(posEspecialidad);
	}

	
	 veterinarios = Veterinarios(idveterinario, matricula, DNI, Nombre, Apellido, especialidad, activo);
	 if (vArchivo.GuardarVeterinario(veterinarios))
	 {
	 	std::cout << std::endl;
	 	std::cout << "Veterinario guardado correctamente." << std::endl;
	 }
	 else
	 {
	 	std::cout << "Error al guardar el Veterinario." << std::endl;
	 }
}

void VeterinariosManager::MostrarVeterinario()
{
	Veterinarios veterinario;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Veterinarioss registrados." << std::endl;
	}

	for (int i = 0; i < cantidadregistros; i++)
	{
		veterinario = vArchivo.LeerVeterinario(i);
		std::cout << veterinario.toCSV() << std::endl;
	}
}

int VeterinariosManager::BuscarVeterinariosPorID(int idBuscado)
{
	Veterinarios veterinarios;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		veterinarios = vArchivo.LeerVeterinario(i);
		if (veterinarios.getIDVeterinario() == idBuscado)
		{
			return i;
		}
	}
	std::cout << "No se encontró el ID del Veterinarios." << std::endl;
	return -1;
}
