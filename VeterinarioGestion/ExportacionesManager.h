#pragma once
#include <iostream>
#include "Cliente.h"
#include "GestorArchivo.h"

class ExportacionesManager
{
private:
    void mostrarMensajeNoRegistros();
public:
	void exportarClientes();
	void exportarConsultas();
	void exportarEspecialidades();
	void exportarMascotas();
	void exportarPagos();
	void exportarSucursales();
	void exportarTratamientos();
	void exportarVacunaciones();
	void exportarVacunas();
	void exportarVeterinarios();
};

