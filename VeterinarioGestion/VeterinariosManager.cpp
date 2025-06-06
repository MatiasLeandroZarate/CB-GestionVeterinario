#include "VeterinariosManager.h"


void VeterinariosManager::CargarVeterinarios()
{
    Validaciones validar;
	Veterinarios veterinarios;
	Especialidades especialidad;
	EspecialidadManager eManager;


	GestorArchivo eArchivo("especialidades.dat");
	int idveterinario = 0,matricula, idespecialidad;
	std::string DNI, Nombre, Apellido;
	bool activo, confirmar = false , buscaDNI = false;

	std::cout << "Ingrese N� DNI: ";
	std::cin.ignore();
	DNI = validar.validarNUMenString();

do {
	buscaDNI = BuscarVeterinarioPorDNI(DNI);
	if (buscaDNI)
	{
		std::cout << std::endl  << "Ya existe un Veterinario con el DNI ingresado." << std::endl;
		confirmar = true;
	}
	else {
		idveterinario = SiguienteID();
		std::cout << "Ingrese la Matricula del Veterinario: ";
		matricula = validar.validarNumero();
		std::cout << "Ingrese el ID especialidad: ";
		idespecialidad = validar.validarNumero();
		std::cout << "Ingrese el Nombre: ";
		Nombre = validar.validarNombre();
		std::cout << "Ingrese el Apellido: ";
		Apellido = validar.validarNombre();
		std::cout << "Ingrese 1 si esta Activo o 0 para inactivo): ";
		activo = validar.validarBool();
	
		int posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);

		if (posEspecialidad == -1)
		{
			bool crear;
			std::cout << "No se encontro la especialidad." << std::endl;
			std::cout << "Desea agregar una especialidad? 1- Si . 0 - No: ";
			crear = validar.validarBool();


			if (crear == 1)
			{
				eManager.CargarEspecialidad();
				posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);
				especialidad = eArchivo.LeerEspecialidad(posEspecialidad);
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

		}
} while (!confirmar);
		Guardar(veterinarios);

}

void VeterinariosManager::MostrarVeterinarioInforme()
{
	Veterinarios veterinario;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Veterinarios registrados." << std::endl;
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
{   Validaciones validar;
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
	int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();
	if (cantidadRegistros == 0)
	{
		return 1;
	}

	ultimoveterinario = vArchivo.LeerVeterinario(cantidadRegistros - 1);
	return ultimoveterinario.getIDVeterinario() + 1;
}

bool VeterinariosManager::BajaVeterinario()
{   Validaciones validar;
	std::string dni;
	Veterinarios veterinarios;

	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();
	std::cout << "Ingrese el DNI del Veterinario que desea dar de baja: ";

	dni = validar.validarNUMenString();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		veterinarios = vArchivo.LeerVeterinario(i);
		if (veterinarios.getDNI() == dni && veterinarios.getActivo())
		{
			veterinarios.setActivo(false);
			if (vArchivo.ModificarVeterinarios(i, veterinarios))
			{
				std::cout << "Veterinario dado de baja exitosamente." << std::endl;
				return true;
			}
			else
				{
				std::cout << "Veterinario no encontrado o ya dado de baja." << std::endl;
				return false;
				}
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


void VeterinariosManager::ModificarVeterinarios()
{
	Validaciones validar;
	std::string dni;
	Veterinarios veterinario;
	Especialidades especialidad;
	EspecialidadManager eManager;
	GestorArchivo vArchivo("veterinarios.dat");
	int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();

	std::cout << "Ingrese el DNI del Veterinario a modificar: ";
	std::cin.ignore();
	dni = validar.validarNUMenString();

	for (int i = 0; i < cantidadRegistros; i++) {
		veterinario = vArchivo.LeerVeterinario(i);
		if (veterinario.getDNI() == dni) {
			std::cout << "Datos actuales:" << std::endl;
			std::cout << veterinario.toInforme() << std::endl;

			int matricula, idespecialidad;
			std::string nombre, apellido;
			bool activo;

			//idvete = veterinario.getIDVeterinario();
			std::cout << "Ingrese nueva Matricula: ";
			matricula = validar.validarNumero();

			std::cout << "Ingrese nuevo ID Especialidad: ";
			idespecialidad = validar.validarNumero();

			int posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);
			if (posEspecialidad == -1) {
				std::cout << "No se encontro la especialidad." << std::endl;
				especialidad = Especialidades(0, "Sin especialidad", "Sin datos");
			}
			else {
				especialidad = GestorArchivo("especialidades.dat").LeerEspecialidad(posEspecialidad);
			}

			std::cout << "Ingrese nuevo Nombre: ";
			nombre = validar.validarNombre();

			std::cout << "Ingrese nuevo Apellido: ";
			apellido = validar.validarNombre();

			std::cout << "Activo (1: Si / 0: No): ";
			activo = validar.validarBool();

			veterinario.setMatricula(matricula);
			veterinario.setEspecialidad(especialidad);
			veterinario.setNombre(nombre);
			veterinario.setApellido(apellido);
			veterinario.setActivo(activo);

			if (vArchivo.ModificarVeterinarios(i, veterinario)) {
				std::cout << "Veterinario modificado correctamente." << std::endl;
			}
			else {
				std::cout << "Error al modificar el Veterinario." << std::endl;
			}
			return;
		}
	}

	std::cout << "No se encontr� el Veterinario con ese DNI." << std::endl;
}