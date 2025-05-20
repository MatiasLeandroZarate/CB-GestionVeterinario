#pragma once
#include "GestorArchivo.h"
#include "Tratamientos.h"
#include <string>
#include <iostream>

class TratamientosManager
{
private:
public:
    void CargarTratamiento();
    void MostrarTratamiento();
    int BuscarTratamientoPorID(int idBuscado);

};

