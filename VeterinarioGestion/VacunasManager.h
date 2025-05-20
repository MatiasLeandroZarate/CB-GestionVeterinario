#pragma once
#include <iostream>
#include <string>
#include "GestorArchivo.h"
#include "Vacunas.h"

class VacunasManager
{
private:
public:
    void CargarVacunas();
    void MostrarVacunas();
    int BuscarVacunasPorID(int idBuscado);
};

