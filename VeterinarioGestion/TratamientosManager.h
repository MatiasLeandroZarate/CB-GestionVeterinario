#pragma once
#include "GestorArchivo.h"
#include "Tratamientos.h"
#include <cstring>
#include <iostream>
#include "Validaciones.h"
#include "rlutil.h"
#include <cctype>
#include "optional"

class TratamientosManager
{private:
public:
	void CargarTratamiento();
	void MostrarTratamiento();
	void MostrarTratamientoExportable();
	void ModificarTratamientos();

	int BuscarTratamientoPorID(int idBuscado);
    std::optional<Tratamientos> obtenerTratamientoPorId(int idBuscado);
	int SiguienteID();
	int procesarEntradaMenu(int opcionMinima, int opcionMaxima);

	bool BajaTratamiento();
	bool ConfirmarIngreso(Tratamientos tratamientos, bool confirmar);
	bool BuscarTratamientoPorNombre(std::string Nombretratamiento);

	void TituloLocate();
};

