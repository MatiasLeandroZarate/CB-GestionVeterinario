#pragma once
#include "GestorArchivo.h"
#include "Mascotas.h"
#include <string>
#include <iostream>

class MascotaManager
{
private:
public:
	void CargarMascota();
	void MostrarMascota();
	int BuscarMascotaPorID(int idBuscado);
	//int ObtenerSiguienteID();

};
