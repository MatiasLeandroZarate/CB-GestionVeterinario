#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
#include "Mascotas.h"
#include "Sucursales.h"
#include "Veterinarios.h"
#include "Tratamientos.h"

class Consultas
{
private:
	Fecha _Fecha;
    Fecha _FechaProximaVisita;
	char _Sintomas[100];
	char _Diagnostico[100];
    int _IDConsultas;
    int _IDMascota;
	int _IDVeterinario;
	int _IDSucursal;
    int _IDTratamiento;
	bool _Estado;
public:
	Consultas();

	Consultas(int idconsultas, int idmascotas, Fecha fecha, std::string sintomas, std::string diagnostico, int idTratamiento, Fecha fechaproximavisita, int idveterinario, int idsucursal);
	void setIDConsultas(int idconsultas);
	void setFecha(Fecha fecha);
	void setSintomas(std::string sintomas);
	void setDiagnostico(std::string diagnostico);
	void setFechaproximavisita(Fecha fechaproximavisita);
    void setIDMascotas(int idmascotas);
	void setIDVeterinario(int idveterinario);
	void setIDSucursal(int idsucursal);
    void setIDTratamiento(int idTratamiento);
	void setEstado(bool estado);

	Fecha getFecha();
    Fecha getFechaproximavisita();
	std::string getSintomas();
	std::string getDiagnostico();
    int getIDConsultas();
	int getIDMascotas();
	int getIDTratamiento();
	int getIDVeterinario();
	int getIDSucursal();
	bool getEstado();

	std::string toCSV();
    std::string toCSVHeader();
};

