#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
#include "Consultas.h"
#include "GestorArchivo.h"
#include "MascotaManager.h"
#include "SucursalManager.h"
#include "VeterinariosManager.h"
#include "TratamientosManager.h"

class ConsultasManager
{
private:
	MascotaManager mascotasManager;
	SucursalManager sucursalesManager;
	VeterinariosManager veterinariosManager;
	TratamientosManager tratamientosManager;

    void imprimirListado();
    void imprimirConsulta(Consultas consulta);
    bool validarNuevaConsulta(Consultas consulta);
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
	int obtenerProximoId();
};

