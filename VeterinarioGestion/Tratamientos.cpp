#include "Tratamientos.h"
#include <cstring>

Tratamientos::Tratamientos()
{
	_IDTratamiento = 0;
	strcpy(_NombreTratamiento, "");
	strcpy(_Descripcion, "");
	_DuracionDias = 0;
	_Costo = 0.0f;
	_Activo = false;
}

Tratamientos::Tratamientos(int IDtratamiento, std::string nombreTratamiento, std::string descripcion, int duracionDias, float costo, bool activo)
{
	setIDTratamiento(IDtratamiento);
	setNombreTratamiento(nombreTratamiento);
	setDescripcion(descripcion);
	setDuracionDias(duracionDias);
	setCosto(costo);
	setActivo(activo);
}

void Tratamientos::setIDTratamiento(int IDTratamiento)
{
	_IDTratamiento = IDTratamiento;
}
void Tratamientos::setNombreTratamiento(std::string nombreTratamiento)
{
	strcpy(_NombreTratamiento,nombreTratamiento.c_str());
}
void Tratamientos::setDescripcion(std::string descripcion)
{
	strcpy(_Descripcion, descripcion.c_str());
}
void Tratamientos::setDuracionDias(int duracionDias)
{
	_DuracionDias = duracionDias;
}
void Tratamientos::setCosto(float costo)
{
	_Costo = costo;
}
void Tratamientos::setActivo(bool activo)
{
	_Activo = activo;
}

int Tratamientos::getIDTratamiento()
{
	return _IDTratamiento;
}
std::string Tratamientos::getNombreTratamiento()
{
	return _NombreTratamiento;
}
std::string Tratamientos::getDescripcion()
{
	return _Descripcion;
}
int Tratamientos::getDuracionDias()
{
	return _DuracionDias;
}
float Tratamientos::getCosto()
{
	return _Costo;
}
bool Tratamientos::getActivo()
{
	return _Activo;
}

std::string Tratamientos::toCSV()
{
	return std::to_string(_IDTratamiento) + "," + std::string(_NombreTratamiento) + "," + std::string(_Descripcion) + "," + std::to_string(_DuracionDias) + "," + std::to_string(_Costo) + "," + std::to_string(_Activo);
}

std::string Tratamientos::toInforme()
{
	return std::to_string(_IDTratamiento) + "\t" + std::string(_NombreTratamiento) + "\t" + std::string(_Descripcion) + "\t" + std::to_string(_DuracionDias) + "\t" + std::to_string(_Costo) + "\t" + std::to_string(_Activo);
}
