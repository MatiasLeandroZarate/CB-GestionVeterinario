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
	int validarEdad();
	int validarPeso();
	std::string validarNombre();
	std::string validarEspecie();
	std::string validarRaza();
	//int ObtenerSiguienteID();

};
