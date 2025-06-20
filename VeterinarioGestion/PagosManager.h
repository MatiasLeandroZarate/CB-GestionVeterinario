#pragma once
#include <iostream>
#include "Pagos.h"
#include "GestorArchivo.h"
#include "Validaciones.h"
#include "Consultas.h"
#include "Sucursales.h"

class PagosManager
{
private:
public:
	void CargarPagos();
	void MostrarPagos();
	int BuscarPagosPorID(int idBuscado);
	void FacturacionPorAnio();
	void RecaudacionPorCliente();
	void RecaudacionPorSucursal();
};

