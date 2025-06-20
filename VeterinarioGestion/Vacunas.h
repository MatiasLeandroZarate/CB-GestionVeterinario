#pragma once
#include <iostream>
#include <string>

class Vacunas
{
private:
	int _IDVacuna;
	char _NombreVacuna[50];
	char _Descripcion[50];
	char _Serial[50];
	bool _Activo;

public:
	Vacunas();
	Vacunas(int idvacuna, std::string nombrevacuna, std::string descripcion, std::string serial, bool activo);

	int getIDVacuna();
	std::string getNombreVacuna();
	std::string getDescripcion();
	std::string getSerial();
	bool getActivo();

	void setIDVacuna(int idvacuna);
	void setNombreVacuna(std::string nombrevacuna);
	void setDescripcion(std::string descripcion);
	void setSerial(std::string serial);
	void setActivo(bool activo);

	std::string toCSV();
};

