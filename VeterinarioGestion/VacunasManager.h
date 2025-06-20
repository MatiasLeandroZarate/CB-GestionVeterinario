#pragma once
#include <iostream>
#include <string>
#include "GestorArchivo.h"
#include "Vacunas.h"
#include "rlutil.h"

class VacunasManager
{private:
public:
	void CargarVacunas();
	void MostrarVacunas();

	int BuscarVacunasPorID(int idBuscado);
	int SiguienteID();
	int procesarEntradaMenu(int opcionMinima, int opcionMaxima);

	bool BuscarVacunaPorNombre(std::string NombreVacuna);
	bool ConfirmarIngreso(Vacunas vacuna, bool confirmar);
	bool BajaVacuna();

	void ModificarVacunas();
	void TituloLocate();
	void MostrarVacunasExportable();

};

