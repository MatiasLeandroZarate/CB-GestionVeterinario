#pragma once
#include <iostream>
#include <string>
#include "Vacunaciones.h"
#include "VacunasManager.h"
#include "GestorArchivo.h"
#include "MascotaManager.h"
#include "VeterinariosManager.h"
#include "Fecha.h"
#include "Validaciones.h"
#include "rlutil.h"


class VacunacionesManager
{private:
public:
	void CargarVacunaciones();
	void MostrarVacunaciones();
	int BuscarVacunacionesPorID(int idBuscado);

		int SiguienteID();
	bool ConfirmarIngreso(Vacunaciones vacunaciones, bool confirmar);
};

