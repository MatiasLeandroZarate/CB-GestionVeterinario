#include "Vacunas.h"

Vacunas::Vacunas()
{
	_IDVacuna = 0;
	strcpy(_NombreVacuna, "");
	strcpy(_Descripcion, "");
	strcpy(_Serial, "");
}

Vacunas::Vacunas(int idvacuna, std::string nombrevacuna, std::string descripcion, std::string serial)
{
	setIDVacuna(idvacuna);
	setNombreVacuna(nombrevacuna);
	setDescripcion(descripcion);
	setSerial(serial);
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


std::string Vacunas::toCSV()
{
	return std::to_string(_IDVacuna) + "," + _NombreVacuna + "," + _Descripcion + "," + _Serial;
}