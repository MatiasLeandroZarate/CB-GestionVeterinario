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

public:
	Vacunas();
	Vacunas(int idvacuna, std::string nombrevacuna, std::string descripcion, std::string serial);

	int getIDVacuna();
	std::string getNombreVacuna();
	std::string getDescripcion();
	std::string getSerial();

	void setIDVacuna(int idvacuna);
	void setNombreVacuna(std::string nombrevacuna);
	void setDescripcion(std::string descripcion);
	void setSerial(std::string serial);

	std::string toCSV();
};

