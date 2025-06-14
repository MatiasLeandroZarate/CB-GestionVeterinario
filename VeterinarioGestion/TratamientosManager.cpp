#include "TratamientosManager.h"

void TratamientosManager::CargarTratamiento()
{
	Validaciones validar;
	Tratamientos tratamiento;
	GestorArchivo tArchivo("tratamientos.dat");
	int IDTratamiento, DuracionDias;
	std::string NombreTratamiento, Descripcion;
	float Costo = 0.0f;
	bool Activo = true, confirmar = false, ComparaNombre = false, guardardato;

	std::cout << "Ingrese el Nombre del Tratamiento: ";
	std::cin.ignore();
	NombreTratamiento = validar.validarLetra();
	
	do {
		ComparaNombre = BuscarTratamientoPorNombre(NombreTratamiento);
		if (ComparaNombre)
		{
			std::cout << std::endl << "Ya existe un Tratamiento con el Nombre ingresado." << std::endl;
			confirmar = true;
			guardardato = false;
		}
		else
		{
		
		IDTratamiento = SiguienteID();

		std::cout << "Ingrese la Descripcion: ";
		Descripcion = validar.validarLetra();
		std::cout << "Ingrese la Duracion en Dias: ";
		DuracionDias = validar.validarNumero();
		std::cout << "Ingrese el Monto: ";
		Costo = validar.validarFloat();
		std::cout << std::endl;
		limpiarPantalla();
		
		tratamiento = Tratamientos(IDTratamiento, NombreTratamiento, Descripcion, DuracionDias, Costo, Activo);
		confirmar = ConfirmarIngreso(tratamiento, confirmar);
		guardardato = true;
		}

	} while (!confirmar);
	
	if(guardardato){
	if (tArchivo.GuardarTratamientos(tratamiento))
		{
			std::cout << "Tratamiento guardado correctamente." << std::endl;
		}
		else
		{
			std::cout << "Error al guardar el tratamiento." << std::endl;
		}
	}
}

void TratamientosManager::MostrarTratamiento()
{
	Validaciones validar;
	Tratamientos tratamiento;
	GestorArchivo tArchivo("tratamientos.dat");
	int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();
	bool crear;
	int y = 4;
	if (cantidadRegistros == 0)
	{
		std::cout << "No hay Tratamiento registrado." << std::endl;
		std::cout << "Desea agregar un tratamiento? 1- Si . 2- No: ";
		crear = validar.validarBool();
		if (crear == 1)
		{
			CargarTratamiento();
		}
		else
		{
			std::cout << "No se cargó ningun tratamiento." << std::endl;
		}
	}
	//std::cout << "TRATAMIENTO:" << std::endl;
	//std::cout << "IDTrat.|NombreTrat. | Descripcion \t | DuracionDias | Costo | Activo" << std::endl;
	TituloLocate();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		tratamiento = tArchivo.LeerTratamientos(i);
		rlutil::locate(1, i + y);
		std::cout << tratamiento.getIDTratamiento();
		rlutil::locate(11, i + y);
		std::cout << tratamiento.getNombreTratamiento();
		rlutil::locate(33, i + y);
		std::cout << tratamiento.getDescripcion();
		rlutil::locate(70, i + y);
		std::cout << tratamiento.getDuracionDias();
		rlutil::locate(80, i + y);
		std::cout << tratamiento.getCosto();
		rlutil::locate(89, i + y);
		std::cout << tratamiento.getActivo();
		//std::cout << tratamiento.toInforme() << std::endl;
	}
}

void TratamientosManager::MostrarTratamientoExportable()
{
	Validaciones validar;
	Tratamientos tratamiento;
	GestorArchivo tArchivo("tratamientos.dat");
	int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();
	bool crear;
	if (cantidadRegistros == 0)
	{
		std::cout << "No hay Tratamiento registrado." << std::endl;
		std::cout << "Desea agregar un tratamiento? 1- Si . 2- No: ";
		crear = validar.validarBool();
		if (crear == 1)
		{
			CargarTratamiento();
		}
		else
		{
			std::cout << "No se cargó ningun tratamiento." << std::endl;
		}
	}
	std::cout << "TRATAMIENTO:" << std::endl;
	std::cout << "IDTrat.,NombreTrat.,Descripcion,DuracionDias,Costo,Activo" << std::endl;
	for (int i = 0; i < cantidadRegistros; i++)
	{
		tratamiento = tArchivo.LeerTratamientos(i);
		std::cout << tratamiento.toCSV() << std::endl;
	}
}

int TratamientosManager::BuscarTratamientoPorID(int idBuscado)
{
	Tratamientos tratamiento;
	GestorArchivo tArchivo("tratamientos.dat");
	int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		tratamiento = tArchivo.LeerTratamientos(i);
		if (tratamiento.getIDTratamiento() == idBuscado)
		{
			return i;
		}
	}
	return -1;
}

int TratamientosManager::SiguienteID()
{
	Tratamientos ultimotratamiento;
	GestorArchivo tArchivo("tratamientos.dat");
	int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();

	return cantidadRegistros + 1;
}

bool TratamientosManager::BajaTratamiento()
{
	Validaciones validar;
	int IDTratamiento;
	Tratamientos tratamiento;

	GestorArchivo tArchivo("tratamientos.dat");
	int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();
	std::cout << "Ingrese el ID del Tratamiento que desea dar de baja: ";
	std::cin.ignore();
	IDTratamiento = validar.validarNumero();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		tratamiento = tArchivo.LeerTratamientos(i);
		if (tratamiento.getIDTratamiento() == IDTratamiento && tratamiento.getActivo())
		{
			tratamiento.setActivo(false);
			if (tArchivo.ModificarTratamiento(i, tratamiento))
			{
				std::cout << "El Tratamiento fue dado de baja exitosamente." << std::endl;
				return true;
			}
			else
			{
				std::cout << "Error baja." << std::endl;
				return false;
			}
		}
	}

	std::cout << "Tratamiento no encontrado o ya dado de baja." << std::endl;
	return false;
}

bool TratamientosManager::ConfirmarIngreso(Tratamientos tratamiento, bool confirmar)
{
	Validaciones validar;
	std::cout << "Tratamiento Ingresado: " << std::endl;
	std::cout << "ID Tratamiento:" << std::endl;
	std::cout << "Nombre Tratamiento: "<< std::endl;
	std::cout << "Descripcion: " << std::endl;
	std::cout << "Costo: " << std::endl;
	std::cout << "Activo: " << std::endl;
	rlutil::locate(21, 2);
	std::cout << tratamiento.getIDTratamiento();
	rlutil::locate(21, 3);
	std::cout << tratamiento.getNombreTratamiento();
	rlutil::locate(21, 4);
	std::cout << tratamiento.getDescripcion();
	rlutil::locate(21, 5);
	std::cout << tratamiento.getCosto();
	rlutil::locate(21, 6);
	std::cout << tratamiento.getActivo();
	
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

bool TratamientosManager::BuscarTratamientoPorNombre(std::string NombreTratamiento)
{
	Tratamientos tratamiento;
	bool TratEncontrado = false;
	GestorArchivo tArchivo("tratamientos.dat");
	
	int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();
	int y = 4;
	for (int i = 0; i < cantidadRegistros; i++)
	{
		tratamiento = tArchivo.LeerTratamientos(i);
		if (tratamiento.getNombreTratamiento() == NombreTratamiento)
		{
			TratEncontrado = true;
			//std::cout << "IDTrat.|NombreTrat. | Descripcion \t | DuracionDias | Costo | Activo" << std::endl;
			TituloLocate();
			rlutil::locate(1,  y);
			std::cout << tratamiento.getIDTratamiento();
			rlutil::locate(11,  y);
			std::cout << tratamiento.getNombreTratamiento();
			rlutil::locate(33,  y);
			std::cout << tratamiento.getDescripcion();
			rlutil::locate(70,  y);
			std::cout << tratamiento.getDuracionDias();
			rlutil::locate(79,  y);
			std::cout << tratamiento.getCosto();
			rlutil::locate(90,  y);
			std::cout << tratamiento.getActivo();
			//std::cout << tratamiento.toInforme() << std::endl;
			return TratEncontrado;
		}
	}
	if (!TratEncontrado)
	{
		std::cout << "No se encontro el Nombre del Tratamiento: " << NombreTratamiento << std::endl;
		return TratEncontrado;
	}
}

void TratamientosManager::ModificarTratamientos()
{
	const static std::string OPCION_NOMBRE_TRATAMIENTO = "Nombre Tratamiento";
	const static std::string OPCION_DESCRIPCION = "Descripcion";
	const static std::string OPCION_DIAS = "Duracion Dias";
	const static std::string OPCION_COSTO = "Costo";
	const static std::string OPCION_ACTIVO = "Activo";
	const static std::string OPCION_SALIR = "Salir";


	const int OPC_NOMBRE_TRATAMIENTO = 1;
	const int OPC_DESCRIPCION = 2;
	const int OPC_DIAS = 3;
	const int OPC_COSTO = 4;
	const int OPC_ACTIVO = 5;
	const int OPC_ATRAS_SALIR = 0;


	Validaciones validar;
	Tratamientos tratamiento;
	int Idtratamiento, dias, opcion, modifico = 1;
	std::string NombreTratamiento, descripcion;
	float costo;
	bool activo;

	GestorArchivo tArchivo("tratamientos.dat");
	int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();

	std::cout << "Ingrese el Nombre del Tratamiento a modificar: ";
	std::cin.ignore();
	MostrarTratamiento();
	rlutil::locate(47, 1);
	NombreTratamiento = validar.validarLetra();
	limpiarPantalla();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		tratamiento = tArchivo.LeerTratamientos(i);

		if (tratamiento.getNombreTratamiento() == NombreTratamiento)
		{
			do {
				std::cout << std::endl << "Datos actuales:" << std::endl;
				//std::cout << "IDTrat.|NombreTrat. | Descripcion \t | DuracionDias | Costo | Activo" << std::endl;
				TituloLocate();

				rlutil::locate(1, 4);
				std::cout << tratamiento.getIDTratamiento();
				rlutil::locate(11, 4);
				std::cout << tratamiento.getNombreTratamiento();
				rlutil::locate(33, 4);
				std::cout << tratamiento.getDescripcion();
				rlutil::locate(70, 4);
				std::cout << tratamiento.getDuracionDias();
				rlutil::locate(79, 4);
				std::cout << tratamiento.getCosto();
				rlutil::locate(90, 4);
				std::cout << tratamiento.getActivo();
				//std::cout << tratamiento.toInforme();
				//-----------------------------------------------------------------------------------------------------------------------

				
				std::cout << std::endl << std::endl << std::endl << "-----------------------------------------" << std::endl;
				
				std::cout << OPC_NOMBRE_TRATAMIENTO << ". " << OPCION_NOMBRE_TRATAMIENTO<< std::endl;
				std::cout << OPC_DESCRIPCION << ". " << OPCION_DESCRIPCION << std::endl;
				std::cout << OPC_DIAS<< ". " << OPCION_DIAS<< std::endl;
				std::cout << OPC_COSTO << ". " << OPCION_COSTO << std::endl;
				std::cout << OPC_ACTIVO << ". " << OPCION_ACTIVO << std::endl;
				std::cout << OPC_ATRAS_SALIR << ". " << OPCION_SALIR << std::endl;

				opcion = procesarEntradaMenu(OPC_ATRAS_SALIR, OPC_ACTIVO);
				std::cin.ignore();

				switch (opcion)
				{
				case OPC_NOMBRE_TRATAMIENTO:
					
					std::cout << std::endl << "Nombre actual del Tratamiento: " << tratamiento.getNombreTratamiento();
					std::cout << std::endl << "Ingrese nuevo Nombre del Tratamiento: ";
					NombreTratamiento = validar.validarLetra();
										
					tratamiento.setNombreTratamiento(NombreTratamiento);
					limpiarPantalla();
					modifico++;
					break;

				case OPC_DESCRIPCION:
					std::cout << std::endl << "Descripcion actual: " << tratamiento.getDescripcion();
					std::cout << std::endl << "Ingrese la nueva Descripcion: ";
					descripcion = validar.validarLetra();
					
					tratamiento.setDescripcion(descripcion);
					limpiarPantalla();
					modifico++;
					break;
				case OPC_DIAS:
					std::cout << std::endl << "Duracion de Dias actual: " << tratamiento.getDuracionDias();
					std::cout << std::endl << "Ingrese los Dias de duracion: ";
					dias = validar.validarNumero();

					tratamiento.setDuracionDias(dias);
					limpiarPantalla();
					modifico++;
					break;

				case OPC_COSTO:
					std::cout << std::endl << "Costo actual: " << tratamiento.getCosto();
					std::cout << std::endl << "Ingrese el nuevo Costo: ";
					costo = validar.validarFloat();

					tratamiento.setCosto(costo);
					limpiarPantalla();
					modifico++;
					break;

				case OPC_ACTIVO:
					std::cout << std::endl << "Status actual: " << tratamiento.getActivo();
					std::cout << std::endl << "Activo (1: Si / 0: No): ";
					activo = validar.validarBool();
					tratamiento.setActivo(activo);
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
				if (tArchivo.ModificarTratamiento(i, tratamiento))
				{
					std::cout << "El tratamiento se ha guardado correctamente." << std::endl;
				}
				else
				{
					std::cout << "Error al guardar el Tratamiento." << std::endl;
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

	std::cout << "No se encontró el Tratamiento con ese Nombre." << std::endl;
}



int TratamientosManager::procesarEntradaMenu(int opcionMinima, int opcionMaxima)
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

void TratamientosManager::TituloLocate()
{
	rlutil::locate(1, 3);
	std::cout << "IDTrat.";
	rlutil::locate(9, 3);
	std::cout << "| Nombre Trat.";
	rlutil::locate(32, 3);
	std::cout << "| Descripcion";
	rlutil::locate(65, 3);
	std::cout << "| Dur. Dias";
	rlutil::locate(77, 3);
	std::cout << "| Costo ";
	rlutil::locate(86, 3);
	std::cout << "| Activo";
	
}