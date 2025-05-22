#pragma once
#include <iostream>
#include <string>
#include "Animal.h"
#include "Fecha.h"


class Mascotas : public Animal
{
private:
	int _IDMascota;
	char _Nombre[50];
	int _Edad;
	Fecha _FechaNacimiento;
	int _IDCliente;

public:
	Mascotas();
	Mascotas(int IDMascota, std::string Nombre, std::string Especie, std::string Raza, int Edad, float Peso, std::string Sexo, Fecha FechaNacimiento, int IDCliente);

	void setIDMascota(int IDMascota);
	void setNombre(std::string Nombre);
	void setEdad(int Edad);
	void setFechaNacimiento(Fecha FechaNacimiento);
	void setIDCliente(int IDCliente);
	
	int getIDMascota();
	std::string getNombre();
	int getEdad();
	Fecha getFechaNacimiento();
	int getIDCliente();
	
	std::string toCSV();
};

