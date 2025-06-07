#pragma once
#include <iostream>
#include <string>
#include "Consultas.h"
#include "GestorArchivo.h"
#include "TratamientosManager.h"
#include "Fecha.h"

class ConsultasManager
{
private:
public:
	void altaConsulta();
	void modificarConsulta();
	void listarConsultas();
	void bajaConsulta();
	void consultarPorMascota();
	void consultarPorFecha();
	void consultarPorSucursal();
	void consultarPorVeterinario();
	void consultarPorCliente();
	int BuscarConsultaPorID(int idBuscado);
};

