#pragma once
#include <iostream>
#include "GestorArchivo.h"
#include "Cliente.h"
#include "Consultas.h"
#include "Especialidades.h"
#include "Mascotas.h"
#include "Pagos.h"
#include "Sucursales.h"
#include "Tratamientos.h"
#include "Vacunaciones.h"
#include "Vacunas.h"
#include "Veterinarios.h"

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

