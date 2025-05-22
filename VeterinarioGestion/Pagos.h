#pragma once
#include <iostream>
#include <cstring>
#include "Fecha.h"

class Pagos
{
private:
	int _IDPago;
	int _IDConsulta;
	float _Monto;
	Fecha _FechaPago;
	char _MedioPago[20];

public:
	Pagos();
	Pagos(int idpago, int idconsulta, float monto, Fecha fechapago, std::string mediopago);
	void setIDPagos(int idpago);
	void setIDConsulta(int idconsulta);
	void setMonto(float monto);
	void setFechaPagos(Fecha fechapago);
	void setMedioPagos(std::string mediopago);

	int getIDPagos();
	int getIDConsulta();
	float getMonto();
	Fecha getFechaPagos();
	std::string getMedioPagos();

	std::string toInforme();
	std::string toCSV();
};

