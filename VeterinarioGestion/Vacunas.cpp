#include "Vacunas.h"
#include <cstring>

Vacunas::Vacunas()
{
	_IDVacuna = 0;
	strcpy(_NombreVacuna, "");
	strcpy(_Descripcion, "");
	strcpy(_Serial, "");
	_Activo = false;
}

Vacunas::Vacunas(int idvacuna, std::string nombrevacuna, std::string descripcion, std::string serial, bool activo)
{
	setIDVacuna(idvacuna);
	setNombreVacuna(nombrevacuna);
	setDescripcion(descripcion);
	setSerial(serial);
	setActivo(activo);
}

int Vacunas::getIDVacuna()
{
	return _IDVacuna;
}
std::string Vacunas::getNombreVacuna()
{
	return _NombreVacuna;
}
std::string Vacunas::getDescripcion()
{
	return _Descripcion;
}
std::string Vacunas::getSerial()
{
	return _Serial;
}
bool Vacunas::getActivo()
{
	return _Activo;
}


void Vacunas::setIDVacuna(int idvacuna)
{
	_IDVacuna = idvacuna;
}
void Vacunas::setNombreVacuna(std::string nombrevacuna)
{
	strcpy(_NombreVacuna, nombrevacuna.c_str());
}
void Vacunas::setDescripcion(std::string descripcion)
{
	strcpy(_Descripcion, descripcion.c_str());
}
void Vacunas::setSerial(std::string serial)
{
	strcpy(_Serial, serial.c_str());
}
void Vacunas::setActivo(bool activo)
{
	_Activo = activo;
}


std::string Vacunas::toCSV()
{
	return std::to_string(_IDVacuna) + "," + _NombreVacuna + "," + _Descripcion + "," + _Serial + "," + std::to_string(_Activo);
}
