#pragma once
#include "GestorArchivo.h"
#include "Sucursales.h"

class SucursalManager
{
private:
public:
	void CargarSucursal();
	void MostrarSucursal();
	int BuscarSucursalPorID(int idBuscado);
	
};

