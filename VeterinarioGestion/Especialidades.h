#pragma once
#include <iostream>
#include <string>
#include "Validaciones.h"


class Especialidades
{private:
	int _IDEspecialidad;
	char _Nombre[50];
	char _Descripcion[50];
public:
	Especialidades();
	Especialidades(int IDEspecialidad, std::string Nombre, std::string Descripcion);

	int getIDEspecialidad();
	std::string getNombre();
	std::string getDescripcion();

	void setIDEspecialidad(int IDEspecialidad);
	void setNombre(std::string Nombre);
	void setDescripcion(std::string Descripcion);

	std::string toCSV();
    std::string toCSVHeader();
	std::string toInforme();
};

