#include "Sucursales.h"

Sucursales::Sucursales()
{
	_IDSucursal = 0;
	strcpy(_Nombre, "");
	strcpy(_Direccion, "");
}

Sucursales::Sucursales(int idSucursal, std::string nombre, std::string direccion)
{
	setIDSucursal(idSucursal);
	setNombre(nombre);
	setDireccion(direccion);
}

void Sucursales::setIDSucursal(int IDSucursal) 
{
	_IDSucursal = IDSucursal;
}
void Sucursales::setNombre(std::string nombre)
{
	strcpy(_Nombre, nombre.c_str());
}
void Sucursales::setDireccion(std::string direccion) 
{
	strcpy(_Direccion, direccion.c_str());	
}

int Sucursales::getIDSucursal()
{
	return _IDSucursal;
}
std::string Sucursales::getNombre()
{
	return _Nombre;
}
std::string Sucursales::getDireccion()
{
	return _Direccion;
}


std::string Sucursales::toCSV() 
{
	return std::to_string(_IDSucursal) + "," + std::string(_Nombre) + "," + std::string(_Direccion);
}