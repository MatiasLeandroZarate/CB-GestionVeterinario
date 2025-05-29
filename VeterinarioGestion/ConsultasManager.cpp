#include "ConsultasManager.h"

void ConsultasManager::CargarConsulta()
{	
	Consultas consulta;
	GestorArchivo cArchivo("consultas.dat");
	GestorArchivo tArchivo("tratamientos.dat");
	TratamientosManager tManager;
	Tratamientos Tratamiento;

	int IDTratamiento;
	int IDMascota,IDConsulta,IDVeterinario, IDSucursal;
	std::string Sintomas, Diagnostico;
	Fecha Fechaconsulta, FechaProximaVisita , fechavalidar;
	int dia, mes, anio;

	std::cout << "Ingrese el ID de la Consulta: ";
	std::cin >> IDConsulta;
	std::cout << "Ingrese el ID de la Mascota: ";
	std::cin >> IDMascota;
	std::cout << "Ingrese la Fecha de la Consulta: " << std::endl;
	
	Fechaconsulta = fechavalidar.ValidacionFecha(Fechaconsulta);
	std::cout << "Ingrese los Sintomas: ";
	std::cin.ignore();
	std::getline(std::cin, Sintomas);
	std::cout << "Ingrese el Diagnostico: ";
	std::getline(std::cin, Diagnostico);
	std::cout << "Ingrese el ID del Tratamiento: ";
	std::cin >> IDTratamiento;

	int posTratamiento = tManager.BuscarTratamientoPorID(IDTratamiento);
	if (posTratamiento == -1)
	{
		bool crear;
		std::cout << "No se encontró la especialidad." << std::endl;
		std::cout << "Desea agregar una especialidad? 1- Si . 2- No: ";
		std::cin >> crear;
		if (crear == 1)
		{
			tManager.CargarTratamiento();
		}
		else
		{
			std::cout << "No se cargó ningun Tratamiento con ese ID." << std::endl;
		}
	}
	else
	{
		// Leer la especialidad desde el archivo
		Tratamiento = tArchivo.LeerTratamientos(posTratamiento);
	}

	std::cout << "Ingrese la Fecha de la Proxima Visita: " << std::endl;
	/*
	std::cout << "Dia: ";
	std::cin >> dia;
	std::cout << "Mes: ";
	std::cin >> mes;
	std::cout << "Anio: ";
	std::cin >> anio;*/

	FechaProximaVisita = fechavalidar.ValidacionFecha(FechaProximaVisita);
	std::cout << "Ingrese el ID del Veterinario: ";
	std::cin >> IDVeterinario;
	std::cout << "Ingrese el ID de la Sucursal: ";
	std::cin >> IDSucursal;


	consulta = Consultas(IDConsulta, IDMascota, Fechaconsulta, Sintomas, Diagnostico, Tratamiento, FechaProximaVisita, IDVeterinario, IDSucursal);

	if (cArchivo.GuardarConsultas(consulta))
	{
		std::cout << std::endl;
		std::cout << "La consulta fue guardada correctamente." << std::endl;
	}
	else
	{
		std::cout << "Error al guardar la Consulta." << std::endl;
	}
}

void ConsultasManager::MostrarConsulta()
{
	Consultas consulta;
	GestorArchivo cArchivo("consultas.dat");
	int cantidadregistros = cArchivo.CantidadRegistrosConsultas();
	if (cantidadregistros == 0)
	{
		std::cout << "No hay Consultas registradas." << std::endl;
	}

	for (int i = 0; i < cantidadregistros; i++)
	{
		consulta = cArchivo.LeerConsultas(i);
		std::cout << consulta.toCSV() << std::endl;
	}
}

int ConsultasManager::BuscarConsultaPorID(int idBuscado)
{
	Consultas consulta;
	GestorArchivo cArchivo("consultas.dat");
	int cantidadRegistros = cArchivo.CantidadRegistrosVeterinario();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		consulta = cArchivo.LeerConsultas(i);
		if (consulta.getIDConsultas() == idBuscado)
		{
			return i;
		}
	}
	std::cout << "No se encontró el ID de la Consulta." << std::endl;
	return -1;
}