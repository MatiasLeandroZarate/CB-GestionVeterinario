#pragma once
#include "GestorArchivo.h"
#include "EspecialidadManager.h"
#include "Veterinarios.h"


class VeterinariosManager
{
private:
public:
    void CargarVeterinarios();
    void MostrarVeterinario();
    int BuscarVeterinariosPorID(int idBuscado);

};

