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
	void MostrarMascotaPorID();
	int validarEdad();
	float validarPeso();
	int GenerarIdAutomatico();
	void MostrarMascotaPorRaza();
	void MostrarMascotaPorEspecie();
	int ValidarIdCliente();
	std::string validarNombre();
	std::string validarSexo();
	std::string validarEspecie();
	std::string validarRaza();
	//int ObtenerSiguienteID();


};
