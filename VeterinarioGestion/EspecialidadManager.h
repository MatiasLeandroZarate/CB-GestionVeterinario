#pragma once
#include "Especialidades.h"
#include "GestorArchivo.h"
#include <iostream>
#include <string>


class EspecialidadManager
{private:
public:
	void CargarEspecialidad();
	void MostrarEspecialidades();
	int BuscarEspecialidadPorID(int idBuscado);
};

