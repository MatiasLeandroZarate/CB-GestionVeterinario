#pragma once
#include "GestorArchivo.h"
#include "Sucursales.h"
#include <optional>

class SucursalManager
{
private:
public:
	void CargarSucursal();
	void MostrarSucursal();
	int BuscarSucursalPorID(int idBuscado);
	std::optional<Sucursales> obtenerSucursalPorId(int idBuscado);
};

