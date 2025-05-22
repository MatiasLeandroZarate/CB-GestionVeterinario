#include "VacunacionesManager.h"

void VacunacionesManager::CargarVacunaciones()
{
	Vacunaciones vacunaciones;
	GestorArchivo vacunacionesArchivo("vacunaciones.dat");
	
	Vacunas vacuna;
	VacunasManager vacuManager;
	GestorArchivo vacuArchivo("vacunas.dat");
	
	Mascotas mascota;
	MascotaManager masManager;
	GestorArchivo masArchivo("mascotas.dat");
	
	Fecha fechaaplicacion, fechavalidar;
	
	Veterinarios veterinarioaplicador;
	VeterinariosManager veteManager;
	GestorArchivo veteArchivo("veterinarios.dat");

	int idvacunaciones , idvacuna , idmascota, idveterinario;
	
	std::cout << "Ingrese el ID de la Vacunacion: ";
	std::cin >> idvacunaciones;
	std::cout << "Ingrese el ID de la Vacuna: ";
	std::cin >> idvacuna;
	
	int posVacuna = vacuManager.BuscarVacunasPorID(idvacuna);
	if (posVacuna == -1)
	{
		bool crear;
		std::cout << "No se encontró la Vacuna." << std::endl;
		std::cout << "Desea agregar una Vacuna? 1- Si . 2- No: ";
		std::cin >> crear;
		if (crear == 1)
		{
			vacuManager.CargarVacunas();
		}
		else
		{
			std::cout << "No se cargó ninguna Vacuna." << std::endl;
		}
	}
	else
	{
	vacuna = vacuArchivo.LeerVacunas(posVacuna);
	}

	
	std::cout << "Ingrese el ID de la Mascota: ";
	std::cin >> idmascota;
	
	int posMascota = masManager.BuscarMascotaPorID(idmascota);
	if (posMascota == -1)
	{
		bool crear;
		std::cout << "No se encontro la Mascota." << std::endl;
		std::cout << "Desea agregar una Mascota? 1- Si . 2- No: ";
		std::cin >> crear;
		if (crear == 1)
		{
			masManager.CargarMascota();
		}
		else
		{
			std::cout << "No se cargo ninguna Mascota." << std::endl;
		}
	}
	else
	{
		mascota = masArchivo.LeerMascota(posMascota);
	}

	std::cout << "Ingrese la fecha de aplicacion: " << std::endl;

	fechaaplicacion = fechavalidar.ValidacionFecha(fechavalidar);

	std::cout << "Ingrese el Id del Veterinario aplicacion: " << std::endl;
	std::cin >> idveterinario;

	int posVeterinario = veteManager.BuscarVeterinariosPorID(idveterinario);
	if (posVeterinario == -1)
	{
		bool crear;
		std::cout << "No se encontró el Veterinario." << std::endl;
		std::cout << "Desea agregar un Veterinario? 1- Si . 2- No: ";
		std::cin >> crear;
		if (crear == 1)
		{
			veteManager.CargarVeterinarios();
		}
		else
		{
			std::cout << "No se cargó ningun Veterinario." << std::endl;
		}
	}
	else
	{
		veterinarioaplicador = veteArchivo.LeerVeterinario(posVeterinario);
	}


	vacunaciones = Vacunaciones(idvacunaciones, vacuna, mascota, fechaaplicacion, veterinarioaplicador);
	if (vacunacionesArchivo.GuardarVacunaciones(vacunaciones))
	{
		std::cout << std::endl;
		std::cout << "La informacion de la Vacunacion fue guardada correctamente." << std::endl;
	}
	else
	{
		std::cout << "Error al guardar la informacion de la Vacunacion." << std::endl;
	}
}


void VacunacionesManager::MostrarVacunaciones()
{
	Vacunaciones vacuna;
	GestorArchivo vacunacionesArchivo("vacunaciones.dat");
	int cantidadregistros = vacunacionesArchivo.CantidadRegistrosVacunaciones();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Vacunaciones registradas." << std::endl;
	}

	for (int i = 0; i < cantidadregistros; i++)
	{
		vacuna = vacunacionesArchivo.LeerVacunaciones(i);
		std::cout << vacuna.toCSV() << std::endl;
	}
}


int VacunacionesManager::BuscarVacunacionesPorID(int idBuscado)
{
	Vacunaciones vacunaciones;
	GestorArchivo vacunacionesArchivo("vacunaciones.dat");
	int cantidadRegistros = vacunacionesArchivo.CantidadRegistrosVacunaciones();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		vacunaciones = vacunacionesArchivo.LeerVacunaciones(i);
		if (vacunaciones.getIDVacunaciones() == idBuscado)
		{
			return i;
		}
	}
	std::cout << "No se encontró el ID de la Vacunacion." << std::endl;
	return -1;
}
