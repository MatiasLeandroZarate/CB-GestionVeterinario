#pragma once
#include <iostream>
#include <string>
class Sucursales
{private:
	int _IDSucursal;
	char _Nombre[50];
	char _Direccion[100];
    float _Recaudacion;
    bool _Activo;

public:
	Sucursales();
	Sucursales(int idSucursal, std::string nombre, std::string direccion,float recaudacion, bool activo);

	void setIDSucursal(int IDSucursal);
	void setNombre(std::string nombre);
	void setDireccion(std::string direccion);
    void setRecaudacion(float recaudacion);
    void setActivo(bool activo);

	int getIDSucursal();
	std::string getNombre();
	std::string getDireccion();
	float getRecaudacion();
	bool getActivo();

	std::string toCSV();
    std::string toCSVHeader();
};

