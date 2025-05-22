#pragma once
#include <iostream>
#include "Pagos.h"
#include "GestorArchivo.h"

class PagosManager
{
private:
public:
	void CargarPagos();
	void MostrarPagos();
	int BuscarPagosPorID(int idBuscado);
	void FacturacionPorAnio();
	
};

