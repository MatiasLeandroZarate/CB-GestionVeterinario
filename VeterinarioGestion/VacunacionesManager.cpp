#include "VacunacionesManager.h"

void VacunacionesManager::CargarVacunaciones()
{
	Vacunaciones vacunaciones;
	GestorArchivo vacunacionesArchivo("vacunaciones.dat");
	Validaciones validar;

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
	int idvacunaciones, idvacuna, idmascota, idveterinario;
	bool confirmar = false, guardardato; //, checkVacuna,checkMascota,checkVeterinario

		limpiarPantalla();
	do {
		//std::cin.clear();

		//---------------- VACUNA
		std::cout << "Ingrese el ID de la Vacuna: ";
		vacuManager.MostrarVacunas();
		rlutil::locate(30, 1);
		std::cin.ignore();
		idvacuna = validar.validarNumero();

		idvacunaciones = SiguienteID();
		limpiarPantalla();
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

		//---------------- MASCOTA
		std::cout << "Ingrese el ID de la Mascota: ";
		masManager.MostrarMascota();
		rlutil::locate(31, 1);
		idmascota = validar.validarNumero();

		limpiarPantalla();
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

		//---------------- FECHA
		std::cout << "Ingrese la fecha de aplicacion: " << std::endl;

		fechaaplicacion = fechavalidar.ValidacionFecha(fechavalidar);
		limpiarPantalla();

		//---------------- VETERINARIO
		std::cout << "Ingrese el Id del Veterinario aplicacion: " << std::endl;
		veteManager.MostrarVeterinarioInforme();
		rlutil::locate(43, 1);
		idveterinario = validar.validarNumero();

		limpiarPantalla();
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
		confirmar = ConfirmarIngreso(vacunaciones, confirmar);
		guardardato = true;

		std::cin.clear();
		limpiarPantalla();
	} while (!confirmar);

	if(guardardato)
	{
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

int VacunacionesManager::SiguienteID()
{
	GestorArchivo vacunacionesArchivo("vacunaciones.dat");
	int cantidadRegistros = vacunacionesArchivo.CantidadRegistrosVacunaciones();

	return cantidadRegistros + 1;
}

bool VacunacionesManager::ConfirmarIngreso(Vacunaciones vacunaciones, bool confirmar)
{
	Validaciones validar;

	std::cout << "Vacunacion Ingresada: " << std::endl;
	std::cout << "ID Vacunacion: " << std::endl;
	//---- Datos vacuna
	std::cout << "Vacuna Ingresada: " << std::endl;
	std::cout << "ID Vacuna:" << std::endl;
	std::cout << "Nombre Vacuna: " << std::endl;
	std::cout << "Descripcion: " << std::endl;
	std::cout << "N Serial: " << std::endl;
	std::cout << "Activo: " << std::endl;
	//---- Datos mascota
	std::cout << "Mascota Ingresada: " << std::endl;
	std::cout << "ID Mascota: " << std::endl;
	std::cout << "Nombre Mascota: " << std::endl;
	std::cout << "ID Cli.Mascota:" << std::endl;
	//---- Datos fecha aplicacion
	std::cout << "Fecha Ingresada: " << std::endl;
	std::cout << "Fecha de Aplicacion: " << std::endl;
	//---- Datos Veterinario
	std::cout << "Veterinario Ingresado: " << std::endl;
	std::cout << "ID Veterinario:" << std::endl;
	std::cout << "Matricula: " << std::endl;
	std::cout << "DNI: " << std::endl;
	std::cout << "Nombre y Apellido: " << std::endl;
	std::cout << "Activo: " << std::endl;
	int columna= 25;
	rlutil::locate(columna, 2);
	std::cout << vacunaciones.getIDVacunaciones();
	rlutil::locate(columna, 4);
	std::cout << vacunaciones.getVacuna().getIDVacuna();
	rlutil::locate(columna, 5);
	std::cout << vacunaciones.getVacuna().getNombreVacuna();
	rlutil::locate(columna, 6);
	std::cout << vacunaciones.getVacuna().getDescripcion();
	rlutil::locate(columna, 7);
	std::cout << vacunaciones.getVacuna().getSerial();
	rlutil::locate(columna, 8);
	std::cout << vacunaciones.getVacuna().getActivo();
	rlutil::locate(columna, 10);
	std::cout << vacunaciones.getMascota().getIDMascota();
	rlutil::locate(columna, 11);
	std::cout << vacunaciones.getMascota().getNombre();
	rlutil::locate(columna, 12);
	std::cout << vacunaciones.getMascota().getIDCliente();
	rlutil::locate(columna, 14);
	std::cout << vacunaciones.getFechaAplicacion().toString();
	rlutil::locate(columna, 16);
	std::cout << vacunaciones.getVeterinarioAplicador().getIDVeterinario();
	rlutil::locate(columna, 17);
	std::cout << vacunaciones.getVeterinarioAplicador().getMatricula();
	rlutil::locate(columna, 18);
	std::cout << vacunaciones.getVeterinarioAplicador().getDNI();
	rlutil::locate(columna, 19);
	std::cout << vacunaciones.getVeterinarioAplicador().getNombre() << " " << vacunaciones.getVeterinarioAplicador().getApellido();
	rlutil::locate(columna, 20);
	std::cout << vacunaciones.getVeterinarioAplicador().getActivo();

	std::cout << std::endl << "Confirma los datos ingresados? 1-Si, 0-No: " << std::endl;
	confirmar = validar.validarBool();


	if (confirmar)
	{
		std::cout << "Datos confirmados." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Datos no confirmados, vuelva a ingresar." << std::endl;
		return false;
	}

}
