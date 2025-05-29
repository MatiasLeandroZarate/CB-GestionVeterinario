#include "Persona.h"
#include <cstring>

Persona::Persona()
{
	strcpy(_DNI, "0");
	strcpy(_Nombre, "0");
	strcpy(_Apellido, "0");
	_Activo = false;
}
Persona::Persona(std::string DNI, std::string Nombre, std::string Apellido, bool Activo)
{
	setDNI(DNI);
	setNombre(Nombre);
	setApellido(Apellido);
	setActivo(Activo);
}

void Persona::setDNI(std::string DNI)
{
	strcpy(_DNI, DNI.c_str());
}
void Persona::setNombre(std::string Nombre)
{
	strcpy(_Nombre, Nombre.c_str());
}
void Persona::setApellido(std::string Apellido)
{
	strcpy(_Apellido, Apellido.c_str());
}
void Persona::setActivo(bool Activo)
{
	_Activo = Activo;
}

//-------------------------SET
std::string Persona::getDNI()
{
	return _DNI;
}

std::string Persona::getNombre(
) {
	return _Nombre;
}

std::string Persona::getApellido()
{
	return _Apellido;
}
bool Persona::getActivo()
{
	return _Activo;
}