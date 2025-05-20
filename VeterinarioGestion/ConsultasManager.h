#pragma once
#include <iostream>
#include <string>
#include "Consultas.h"
#include "GestorArchivo.h"
#include "TratamientosManager.h"

class ConsultasManager
{
private:
public:
    void CargarConsulta();
    void MostrarConsulta();
    int BuscarConsultaPorID(int idBuscado);

};

