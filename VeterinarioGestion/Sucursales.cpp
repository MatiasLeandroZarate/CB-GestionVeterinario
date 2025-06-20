#include "Sucursales.h"
#include <cstring>

Sucursales::Sucursales()
{
	_IDSucursal = 0;
	strcpy(_Nombre, "");
	strcpy(_Direccion, "");
	_Recaudacion = 0.0f;
}

Sucursales::Sucursales(int idSucursal, std::string nombre, std::string direccion,float recaudacion)
{
	setIDSucursal(idSucursal);
	setNombre(nombre);
	setDireccion(direccion);
	setRecaudacion(recaudacion);
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
void Sucursales::setRecaudacion(float recaudacion)
{
    _Recaudacion = recaudacion;
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
float Sucursales::getRecaudacion()
{
    return _Recaudacion;
}

std::string Sucursales::toCSV()
{
	return std::to_string(_IDSucursal) + "," + std::string(_Nombre) + "," + std::string(_Direccion) + "," + std::to_string(_Recaudacion);
}


std::string Sucursales::toCSVHeader(){
    return "id,nombre,direccion,recaudacion";
}
