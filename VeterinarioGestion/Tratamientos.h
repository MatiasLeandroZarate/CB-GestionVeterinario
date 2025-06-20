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
	bool _Activo;

public:
	Tratamientos();
	Tratamientos(int IDtratamiento, std::string nombreTratamiento, std::string descripcion, int duracionDias, float costo,bool activo);

	void setIDTratamiento(int IDTratamiento);
	void setNombreTratamiento(std::string nombreTratamiento);
	void setDescripcion(std::string descripcion);
	void setDuracionDias(int duracionDias);
	void setCosto(float costo);
	void setActivo(bool activo);

	int getIDTratamiento();
	std::string getNombreTratamiento();
	std::string getDescripcion();
	int getDuracionDias();
	float getCosto();
	bool getActivo();

	std::string toCSV();
    std::string toCSVHeader();
	std::string toInforme();
};

