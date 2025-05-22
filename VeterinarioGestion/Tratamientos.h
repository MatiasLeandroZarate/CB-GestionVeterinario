#pragma once
#include <iostream>
#include <string>

class Tratamientos
{private:
	int _IDTratamiento;
	char _NombreTratamiento[50];
	char _Descripcion[100];
	int _DuracionDias;
	float _Costo;

public:
	Tratamientos();
	Tratamientos(int IDtratamiento, std::string nombreTratamiento, std::string descripcion, int duracionDias, float costo);

	void setIDTratamiento(int IDTratamiento);
	void setNombreTratamiento(std::string nombreTratamiento);
	void setDescripcion(std::string descripcion);
	void setDuracionDias(int duracionDias);
	void setCosto(float costo);

	int getIDTratamiento();
	std::string getNombreTratamiento();
	std::string getDescripcion();
	int getDuracionDias();
	float getCosto();

	std::string toCSV();
};

