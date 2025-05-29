#include "VeterinariosManager.h"


void VeterinariosManager::CargarVeterinarios()
{
	Veterinarios veterinarios;
	Especialidades especialidad;
	EspecialidadManager eManager;

	
	GestorArchivo eArchivo("especialidades.dat");
	int idveterinario = 0, matricula, idespecialidad;
	std::string DNI, Nombre, Apellido; 
	bool activo, confirmar = false , buscaDNI = false;
	
	std::cout << "Ingrese N° DNI: ";
	std::cin.ignore();
	DNI = validarNUMenString();
	
	buscaDNI = BuscarVeterinarioPorDNI(DNI);
	if (buscaDNI) 
	{
		std::cout << std::endl  << "Ya existe un Veterinario con el DNI ingresado." << std::endl;
		confirmar = true;
	}
	else {
		do {

			idveterinario = SiguienteID();
			std::cout << "Ingrese la Matricula del Veterinario: ";
			matricula = validarNumero();
			std::cout << "Ingrese el ID especialidad: ";
			idespecialidad = validarNumero();
			std::cout << "Ingrese el Nombre: ";
			Nombre = validarNombre();
			std::cout << "Ingrese el Apellido: ";
			Apellido = validarNombre();
			std::cout << "Ingrese 1 si esta Activo o 0 para inactivo): ";

			std::cin >> activo;
			/*while (activo != 1 || activo != 0)
			{
			std::cout << "Dato invalido, ingrese 1 si esta Activo o 0 para inactivo): ";
			std::cin >> activo;
			}*/

			int posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);
			if (posEspecialidad == -1)
			{
				bool crear;
				std::cout << "No se encontro la especialidad." << std::endl;
				std::cout << "Desea agregar una especialidad? 1- Si . 0 - No: ";
				std::cin >> crear;
				if (crear == 1)
				{
					eManager.CargarEspecialidad();
					//especialidad = Especialidades();
				}
				else
				{
					std::cout << "No se cargo ninguna especialidad." << std::endl;
					especialidad = Especialidades(0, "Sin especialidad", "Sin Datos");
				}
			}
			else
			{
				especialidad = eArchivo.LeerEspecialidad(posEspecialidad);
			}
			limpiarPantalla();
			veterinarios = Veterinarios(idveterinario, matricula, DNI, Nombre, Apellido, especialidad, activo);
		
			confirmar = ConfirmarIngreso(veterinarios, confirmar);

		} while (!confirmar);
		Guardar(veterinarios);
	}

}

void VeterinariosManager::MostrarVeterinarioInforme()
{
	Veterinarios veterinario;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Veterinarioss registrados." << std::endl;
	}
	std::cout << "VETERINARIO: " << std::endl;
	std::cout << "IDVeterinario | MatriculaVete | DNIVete | NombreVete | ApellidoVete | IDEspe. | NombreEspe. | Descripcion \t | Activo" << std::endl;

	for (int i = 0; i < cantidadregistros; i++)
	{
		veterinario = vArchivo.LeerVeterinario(i);

		std::cout << veterinario.toInforme() << std::endl;
	}
}

void VeterinariosManager::MostrarVeterinarioExportable()
{
	Veterinarios veterinario;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Veterinarioss registrados." << std::endl;
	}
	std::cout << "VETERINARIO: " << std::endl;
	std::cout << "IDVeterinario,MatriculaVete,DNIVete,NombreVete,ApellidoVete,IDEspe.,NombreEspe.,Descripcion,Activo" << std::endl;

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
	std::cout << "No se encontro el ID del Veterinarios." << std::endl;
	return -1;
}

bool VeterinariosManager::ConfirmarIngreso(Veterinarios veterinario, bool confirmar)
{
	std::cout << "Veterinario Ingresado: " << std::endl;
	std::cout << "ID Veterinario:" << "\t" + std::to_string(veterinario.getIDVeterinario()) << std::endl;
	std::cout << "Matricula: " << "\t" + std::to_string(veterinario.getMatricula()) << std::endl;
	std::cout << "DNI: " << "\t\t" + veterinario.getDNI() << std::endl;
	std::cout << "Nombre: " << "\t" + veterinario.getNombre() << std::endl;
	std::cout << "Apellido: " << "\t" + veterinario.getApellido() << std::endl;
	std::cout << "IDEspecialidad: " << std::to_string(veterinario.getEspecialidad().getIDEspecialidad()) << std::endl;
	std::cout << "Especialidad: " << "\t" + veterinario.getEspecialidad().getNombre() << std::endl;
	std::cout << "Descripcion: " << "\t" + veterinario.getEspecialidad().getDescripcion() << std::endl;
	std::cout << "Activo: " << "\t" + std::to_string(veterinario.getActivo()) << std::endl;
	
	
	std::cout << "Confirma los datos ingresados? 1-Si, 0-No: " << std::endl;
	std::cin >> confirmar;

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

bool VeterinariosManager::BuscarVeterinarioPorDNI(std::string dniBuscado)
{
	Veterinarios veterinarios;
	bool VeteEncontrado = false;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		veterinarios = vArchivo.LeerVeterinario(i);
		if (veterinarios.getDNI() == dniBuscado)
		{
			VeteEncontrado= true;
			std::cout << "IDVeterinario | MatriculaVete | DNIVete | NombreVete | ApellidoVete | IDEspe. | NombreEspe. | Descripcion \t | Activo" << std::endl;

			std::cout << veterinarios.toInforme() << std::endl;
			return VeteEncontrado;
		}
	}
	if (!VeteEncontrado)
	{
		std::cout << "No se encontro el Veterinario con el DNI: " << dniBuscado << std::endl;
		return VeteEncontrado;
	}
}

void VeterinariosManager::Guardar(Veterinarios veterinarios) 
{
	GestorArchivo vArchivo("veterinarios.dat");
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

int VeterinariosManager::SiguienteID()
{
	Veterinarios ultimoveterinario;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosClientes();
	if (cantidadRegistros == 0)
	{
		return 1;
	}
	ultimoveterinario = vArchivo.LeerVeterinario(cantidadRegistros - 1);
	return ultimoveterinario.getIDVeterinario() + 1;
}

bool VeterinariosManager::BajaVeterinario()
{
	std::string dni;
	Veterinarios veterinarios;
	bool baja = 0;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();
	std::cout << "Ingrese el DNI del Veterinario que desea dar de baja: ";
	std::cin.ignore();
	std::getline(std::cin, dni);


	for (int i = 0; i < cantidadRegistros; i++)
	{
		veterinarios = vArchivo.LeerVeterinario(i);
		if (veterinarios.getDNI() == dni && veterinarios.getActivo() == true)
		{
			std::cout << "El Veterinario se dio de Baja. ";
			veterinarios.setActivo(baja);
			return veterinarios.getActivo();
		}
	}

}

void VeterinariosManager::ListarVeterinariosActivos()
{
	Veterinarios veterinario;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Veterinarioss registrados." << std::endl;
	}
		std::cout << "VETERINARIOS ACTIVOS: " << std::endl;
		std::cout << "IDVeterinario | MatriculaVete | DNIVete | NombreVete | ApellidoVete | IDEspe. | NombreEspe. | Descripcion \t | Activo" << std::endl;
	for (int i = 0; i < cantidadregistros; i++)
	{
		veterinario = vArchivo.LeerVeterinario(i);
		if (veterinario.getActivo() == true)
		{
			std::cout << veterinario.toInforme() << std::endl;
		}
	}
	
}

std::string VeterinariosManager::validarNombre()
{
	std::string str;
	bool strValido = false;

	while (!strValido)
	{
		int i = 0;
		strValido = true;

		//std::cout << "Ingrese el Nombre: ";
		std::getline(std::cin, str);

		while (str[i])
		{
			char c = str[i];
			if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
			{
				strValido = false;
			}
			i++;
		}

		if (!strValido)
		{
			std::cout << "Dato Invalido, Ingresar Nuevamente." << std::endl;
		}
	}
	return str;
}
int VeterinariosManager::validarNumero()
{
	std::string numIngresado;
	bool numValido = false;
	int Num;

	while (!numValido)
	{
		//std::cout << "Ingrese la Edad: ";
		
		std::getline(std::cin, numIngresado);
		numValido = true;
		int i = 0;

		while (numIngresado[i] != '\0')  // Validacion de que todos los caracteres sean numeros y no letras o caracteres
		{
			if (numIngresado[i] < '0' || numIngresado[i] > '9')
			{
				numValido = false;
			}
			i++;
		}

		if (numValido)
		{
			Num = 0;
			i = 0;
			while (numIngresado[i] != '\0')
			{
				Num = Num * 10 + (numIngresado[i] - '0');
				i++;
			}
		}
		//if (Num < 0)
		//{
		//	numValido= false;

		//}
		if (!numValido)
		{
			std::cout << "Dato inválido, Ingrese de nuevo." << std::endl;
		}
	}
	return Num;
}

std::string VeterinariosManager::validarNUMenString()
{
	std::string str;
	bool strValido = false;

	while (!strValido)
	{
		int i = 0;
		strValido = true;

		//std::cout << "Ingrese el Nombre: ";
		std::getline(std::cin, str);

		while (str[i])
		{
			char c = str[i];
			if (!((c >= '0' && c <= '9') || c == ' '))
			{
				strValido = false;
			}
			i++;
		}

		if (!strValido)
		{
			std::cout << "Dato Invalido, Ingresar Nuevamente." << std::endl;
		}
	}
	return str;
}