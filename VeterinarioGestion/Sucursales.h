#pragma once
#include <iostream>
#include <string>
class Sucursales
{private:
	int _IDSucursal;
	char _Nombre[50];
	char _Direccion[100];

public:
	Sucursales();
	Sucursales(int idSucursal, std::string nombre, std::string direccion);
	
	void setIDSucursal(int IDSucursal);
	void setNombre(std::string nombre);
	void setDireccion(std::string direccion);

	int getIDSucursal();
	std::string getNombre();
	std::string getDireccion();

	std::string toCSV();
};

