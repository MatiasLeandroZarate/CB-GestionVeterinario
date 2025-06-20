#pragma once
#include <iostream>
#include <string>
class Sucursales
{private:
	int _IDSucursal;
	char _Nombre[50];
	char _Direccion[100];
    float _Recaudacion;

public:
	Sucursales();
	Sucursales(int idSucursal, std::string nombre, std::string direccion,float recaudacion);

	void setIDSucursal(int IDSucursal);
	void setNombre(std::string nombre);
	void setDireccion(std::string direccion);
    void setRecaudacion(float recaudacion);

	int getIDSucursal();
	std::string getNombre();
	std::string getDireccion();
	float getRecaudacion();

	std::string toCSV();
    std::string toCSVHeader();
};

