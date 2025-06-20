#include "VacunasManager.h"

void VacunasManager::CargarVacunas()
{
	Vacunas vacuna;
	Validaciones validar;
	GestorArchivo vArchivo("vacunas.dat");
	int IDVacuna;
	std::string nombrevacuna, descripcion, serial;

	bool activo = true, ComparaNombre = false, confirmar = false, guardardato;


	std::cout << "Ingrese el Nombre de la Vacuna: ";
	std::cin.ignore();
	nombrevacuna = validar.validarLetra();

	do{
		ComparaNombre = BuscarVacunaPorNombre(nombrevacuna);
		if (ComparaNombre)
		{
			std::cout << std::endl << "Ya existe una Vacuna con el Nombre ingresado." << std::endl;
			confirmar = true;
			guardardato = false;
		}
		else
		{

	std::cout << "Ingrese la Descripcion: ";
	descripcion = validar.validarLetra();
	std::cout << "Ingrese el N Serial: ";
	serial = validar.validarNUMenString();

	limpiarPantalla();

	IDVacuna = SiguienteID();

	vacuna = Vacunas(IDVacuna, nombrevacuna, descripcion, serial,activo);
	guardardato = true;
	confirmar = ConfirmarIngreso(vacuna, confirmar);

		}
	} while (!confirmar);
	if(guardardato)
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

void VacunasManager::ModificarVacunas()
{
	const static std::string OPCION_NOMBRE_VACUNA = "Nombre Vacuna";
	const static std::string OPCION_DESCRIPCION = "Descripcion";
	const static std::string OPCION_SERIAL = "N Serial";
	const static std::string OPCION_ACTIVO = "Activo";
	const static std::string OPCION_SALIR = "Salir";


	const int OPC_NOMBRE_VACUNA = 1;
	const int OPC_DESCRIPCION = 2;
	const int OPC_SERIAL = 3;
	const int OPC_ACTIVO = 4;
	const int OPC_ATRAS_SALIR = 0;


	Validaciones validar;
	Vacunas vacuna;
	int opcion, modifico = 1;
	std::string NombreVacuna, descripcion, serial;
	float costo;
	bool activo;

	GestorArchivo vArchivo("vacunas.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVacunas();

	std::cout << "Ingrese el Nombre de la Vacuna a modificar: ";
	std::cin.ignore();
	MostrarVacunas();
	rlutil::locate(47, 1);
	NombreVacuna = validar.validarLetra();
	limpiarPantalla();


	std::string mayus, NombreMayus;
	NombreMayus = NombreVacuna;
	for (int i = 0; i < NombreMayus.length(); i++) {
		NombreMayus[i] = toupper(NombreMayus[i]);
	}

	for (int i = 0; i < cantidadRegistros; i++)
	{
		vacuna = vArchivo.LeerVacunas(i);

		mayus = vacuna.getNombreVacuna();
		for (int j = 0; j < mayus.length(); j++) {
			mayus[j] = toupper(mayus[j]);
		}

		if (mayus == NombreMayus)
		{
			do {
				std::cout << std::endl << "Datos actuales:" << std::endl;

				TituloLocate();

				rlutil::locate(1, 4);
				std::cout << vacuna.getIDVacuna();
				rlutil::locate(11, 4);
				std::cout << vacuna.getNombreVacuna();
				rlutil::locate(35, 4);
				std::cout << vacuna.getDescripcion();
				rlutil::locate(70, 4);
				std::cout << vacuna.getSerial();
				rlutil::locate(79, 4);
				std::cout << vacuna.getActivo();



				std::cout << std::endl << std::endl << std::endl << "-----------------------------------------" << std::endl;

				std::cout << OPC_NOMBRE_VACUNA << ". " << OPCION_NOMBRE_VACUNA << std::endl;
				std::cout << OPC_DESCRIPCION << ". " << OPCION_DESCRIPCION << std::endl;
				std::cout << OPC_SERIAL << ". " << OPCION_SERIAL << std::endl;
				std::cout << OPC_ACTIVO << ". " << OPCION_ACTIVO << std::endl;
				std::cout << OPC_ATRAS_SALIR << ". " << OPCION_SALIR << std::endl;

				opcion = procesarEntradaMenu(OPC_ATRAS_SALIR, OPC_ACTIVO);
				std::cin.ignore();

				switch (opcion)
				{
				case OPC_NOMBRE_VACUNA:

					std::cout << std::endl << "Nombre actual de la Vacuna: " << vacuna.getNombreVacuna();
					std::cout << std::endl << "Ingrese nuevo Nombre de la Vacuna: ";
					NombreVacuna = validar.validarLetra();

					vacuna.setNombreVacuna(NombreVacuna);
					limpiarPantalla();
					modifico++;
					break;

				case OPC_DESCRIPCION:
					std::cout << std::endl << "Descripcion actual: " << vacuna.getDescripcion();
					std::cout << std::endl << "Ingrese la nueva Descripcion: ";
					descripcion = validar.validarLetra();

					vacuna.setDescripcion(descripcion);
					limpiarPantalla();
					modifico++;
					break;
				case OPC_SERIAL:
					std::cout << std::endl << "N Serial actual: " << vacuna.getSerial();
					std::cout << std::endl << "Ingrese el nuevo N Serial: ";
					serial = validar.validarNUMenString();

					vacuna.setSerial(serial);
					limpiarPantalla();
					modifico++;
					break;

				case OPC_ACTIVO:
					std::cout << std::endl << "Status actual: " << vacuna.getActivo();
					std::cout << std::endl << "Activo (1: Si / 0: No): ";
					activo = validar.validarBool();
					vacuna.setActivo(activo);
					limpiarPantalla();
					modifico++;
					break;

				case OPC_ATRAS_SALIR:
					modifico--;
					limpiarPantalla();
					break;
				}
			} while (opcion != OPC_ATRAS_SALIR);


			if (modifico != 0)
			{
				if (vArchivo.ModificarVacuna(i, vacuna))
				{
					std::cout << "La Vacuna se ha guardado correctamente." << std::endl;
				}
				else
				{
					std::cout << "Error al guardar la Vacuna." << std::endl;
				}
				return;
			}
			else
			{
				std::cout << "No ha modificado ningun dato." << std::endl;
				return;
			}
		}
	}

	std::cout << "No se encontró la Vacuna con ese Nombre." << std::endl;
}

bool VacunasManager::BajaVacuna()
{
	Validaciones validar;
	int IDVacuna;
	Vacunas vacuna;

	GestorArchivo vArchivo("vacunas.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVacunas();
	std::cout << "Ingrese el ID de la vacuna que desea dar de baja: ";
	std::cin.ignore();
	IDVacuna = validar.validarNumero();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		vacuna = vArchivo.LeerVacunas(i);
		if (vacuna.getIDVacuna() == IDVacuna && vacuna.getActivo())
		{
			vacuna.setActivo(false);
			if (vArchivo.ModificarVacuna(i, vacuna))
			{
				std::cout << "La Vacuna fue dada de baja exitosamente." << std::endl;
				return true;
			}
			else
			{
				std::cout << "Error baja." << std::endl;
				return false;
			}
		}
	}

	std::cout << "Vacuna no encontrada o ya dado de baja." << std::endl;
	return false;
}





int VacunasManager::procesarEntradaMenu(int opcionMinima, int opcionMaxima)
{
	int opcion;

	while (true)
	{
		std::cout << std::endl << "Seleccione que dato quiere Modificar: ";

		if (std::cin >> opcion)
		{
			if (opcion >= opcionMinima && opcion <= opcionMaxima)
			{
				limpiarPantalla();
				return opcion;
			}
			else
			{
				std::cout << "ERROR: Debe ingresar un numero entre " << opcionMinima << " y " << opcionMaxima << "." << std::endl;
			}
		}
		else
		{
			std::cout << "ERROR: Debe ingresar solamente numeros enteros, con valores entre el " << opcionMinima << " y el " << opcionMaxima << "." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}


void VacunasManager::MostrarVacunas()
{
	Validaciones validar;
	Vacunas vacuna;
	GestorArchivo vArchivo("vacunas.dat");
	bool crear = false;
	int posicion =4;
	int cantidadregistros = vArchivo.CantidadRegistrosVacunas();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Vacunas registradas." << std::endl;
		std::cout << "Desa agregar una Vacuna? 1: Si . 0: No: ";
		crear = validar.validarBool();
		if (crear == 1)
		{
			CargarVacunas();
		}
		else
		{
			std::cout << "No se cargaron Vacunas." << std::endl;
		}
	}

	TituloLocate();

	for (int i = 0; i < cantidadregistros; i++)
	{
		vacuna = vArchivo.LeerVacunas(i);

		rlutil::locate(1, posicion+i);
		std::cout << vacuna.getIDVacuna();
		rlutil::locate(11, posicion+i);
		std::cout << vacuna.getNombreVacuna();
		rlutil::locate(35, posicion+i);
		std::cout << vacuna.getDescripcion();
		rlutil::locate(67, posicion+i);
		std::cout << vacuna.getSerial();
		rlutil::locate(80, posicion+i);
		std::cout << vacuna.getActivo();
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

int VacunasManager::SiguienteID()
{
	GestorArchivo vArchivo("vacunas.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVacunas();

	return cantidadRegistros + 1;
}


bool VacunasManager::BuscarVacunaPorNombre(std::string NombreVacuna)
{
	Vacunas vacuna;

	bool VacunaEncontrado = false;
	GestorArchivo vArchivo("vacunas.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVacunas();
	int y = 4;

	std::string mayus, NombreMayus;
	NombreMayus = NombreVacuna;
	for (int i = 0; i < NombreMayus.length(); i++) {
		NombreMayus[i] = toupper(NombreMayus[i]);
	}

	for (int i = 0; i < cantidadRegistros; i++)
	{
		vacuna = vArchivo.LeerVacunas(i);

		mayus = vacuna.getNombreVacuna();
		for (int j = 0; j < mayus.length(); j++) {
			mayus[j] = toupper(mayus[j]);
		}
		if (mayus == NombreMayus)
		{
			VacunaEncontrado = true;

			TituloLocate();
			rlutil::locate(1, y);
			std::cout << vacuna.getIDVacuna();
			rlutil::locate(11, y);
			std::cout << vacuna.getNombreVacuna();
			rlutil::locate(35, y);
			std::cout << vacuna.getDescripcion();
			rlutil::locate(70, y);
			std::cout << vacuna.getSerial();
			rlutil::locate(79, y);
			std::cout << vacuna.getActivo();

			return VacunaEncontrado;
		}
	}
	if (!VacunaEncontrado)
	{
		std::cout << "No se encontro el Nombre de la Vacuna: " << NombreVacuna << std::endl;
		return VacunaEncontrado;
	}
}

bool VacunasManager::ConfirmarIngreso(Vacunas vacuna, bool confirmar)
{
	Validaciones validar;
	std::cout << "Vacuna Ingresada: " << std::endl;
	std::cout << "ID Vacuna:" << std::endl;
	std::cout << "Nombre Vacuna: " << std::endl;
	std::cout << "Descripcion: " << std::endl;
	std::cout << "N Serial: " << std::endl;
	std::cout << "Activo: " << std::endl;
	rlutil::locate(21, 2);
	std::cout << vacuna.getIDVacuna();
	rlutil::locate(21, 3);
	std::cout << vacuna.getNombreVacuna();
	rlutil::locate(21, 4);
	std::cout << vacuna.getDescripcion();
	rlutil::locate(21, 5);
	std::cout << vacuna.getSerial();
	rlutil::locate(21, 6);
	std::cout << vacuna.getActivo();

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

void VacunasManager::MostrarVacunasExportable()
{
	Validaciones validar;
	Vacunas vacuna;
	GestorArchivo vArchivo("vacunas.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVacunas();
	bool crear;
	if (cantidadRegistros == 0)
	{
			std::cout << "No hay Vacunas registradas." << std::endl;
		std::cout << "Desa agregar una Vacuna? 1: Si . 0: No: ";
		crear = validar.validarBool();
		if (crear == 1)
		{
			CargarVacunas();
		}
		else
		{
			std::cout << "No se cargaron Vacunas." << std::endl;
		}
	}

	std::cout << "IDVacu.,NombreVacu.,Descripcion,NSerial,Activo" << std::endl;
	for (int i = 0; i < cantidadRegistros; i++)
	{
		vacuna = vArchivo.LeerVacunas(i);
		std::cout << vacuna.toCSV() << std::endl;
	}
}

void VacunasManager::TituloLocate()
{
	rlutil::locate(1, 3);
	std::cout << "IDVac.";
	rlutil::locate(9, 3);
	std::cout << "| Nombre Vac.";
	rlutil::locate(33, 3);
	std::cout << "| Descripcion";
	rlutil::locate(65, 3);
	std::cout << "| N Serial";
	rlutil::locate(77, 3);
	std::cout << "| Activo";
}
