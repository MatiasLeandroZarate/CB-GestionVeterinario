#pragma once
#include <iostream>
#include <string>
#include "Vacunaciones.h"
#include "GestorArchivo.h"
#include "VacunasManager.h"
#include "MascotaManager.h"
#include "VeterinariosManager.h"
#include "Fecha.h"

class VacunacionesManager
{private:
public:
	void CargarVacunaciones();
	void MostrarVacunaciones();
	int BuscarVacunacionesPorID(int idBuscado);
};

