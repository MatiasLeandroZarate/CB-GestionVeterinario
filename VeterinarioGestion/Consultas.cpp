#include "Consultas.h"
#include <cstring>

Consultas::Consultas()
{
	_IDConsultas =0;
	_IDMascota = 0;
	_Fecha = Fecha();
	std::strcpy(_Sintomas,"");
	std::strcpy(_Diagnostico,"");
	_IDTratamiento = 0;
	_FechaProximaVisita = Fecha();
	_IDVeterinario = 0;
	_IDSucursal = 0;
	_Estado = true;
}

Consultas::Consultas(int idconsultas, int idmascotas, Fecha fecha, std::string sintomas, std::string diagnostico, int idtratamiento, Fecha fechaproximavisita, int idveterinario, int idsucursal)
{
	setIDConsultas(idconsultas);
	setIDMascotas(idmascotas);
	setFecha(fecha);
	setSintomas(sintomas);
	setDiagnostico(diagnostico);
	setIDTratamiento(idtratamiento);
	setFechaproximavisita(fechaproximavisita);
	setIDVeterinario(idveterinario);
	setIDSucursal(idsucursal);
    _Estado = true;
}
void Consultas::setIDConsultas(int idconsultas)
{
	_IDConsultas = idconsultas;
}
void Consultas::setIDMascotas(int idmascotas)
{
	_IDMascota = idmascotas;
}
void Consultas::setFecha(Fecha fecha)
{
	_Fecha = fecha;
}
void Consultas::setSintomas(std::string sintomas)
{
	std::strcpy(_Sintomas, sintomas.c_str());
}
void Consultas::setDiagnostico(std::string diagnostico)
{
	std::strcpy(_Diagnostico, diagnostico.c_str());
}
void Consultas::setIDTratamiento(int idtratamiento)
{
	_IDTratamiento = idtratamiento;
}
void Consultas::setFechaproximavisita(Fecha fechaproximavisita)
{
	_FechaProximaVisita = fechaproximavisita;
}
void Consultas::setIDVeterinario(int idveterinario)
{
	_IDVeterinario = idveterinario;
}
void Consultas::setIDSucursal(int idsucursal)
{
	_IDSucursal = idsucursal;
}
void Consultas::setEstado(bool estado)
{
	_Estado = estado;
}

//------------------------
int Consultas::getIDConsultas()
{
	return _IDConsultas;
}
int Consultas::getIDMascotas()
{
	return _IDMascota;
}
Fecha Consultas::getFecha()
{
	return _Fecha;
}
std::string Consultas::getSintomas()
{
	return _Sintomas;
}
std::string Consultas::getDiagnostico()
{
	return _Diagnostico;
}
int Consultas::getIDTratamiento()
{
	return _IDTratamiento;
}
Fecha Consultas::getFechaproximavisita()
{
	return _FechaProximaVisita;
}
int Consultas::getIDVeterinario()
{
	return _IDVeterinario;
}
int Consultas::getIDSucursal()
{
	return _IDSucursal;
}
bool Consultas::getEstado()
{
	return _Estado;
}

std::string Consultas::toCSV()
{
	return std::to_string(_IDConsultas) + "," + std::to_string(_IDMascota) + "," + _Fecha.toString()
	+ "," + _Sintomas + "," + _Diagnostico + "," + std::to_string(_IDTratamiento)
	+ "," + _FechaProximaVisita.toString() + "," + std::to_string(_IDVeterinario) + "," + std::to_string(_IDSucursal)
	+ "," + std::to_string(_Estado);
}

std::string Consultas::toCSVHeader(){
    return "id,idMascota,fechaConsulta,sintomas,diagnostico,idTratamiento,fechaProximaVisita,idVeterinario,idSucursal,estado";
}
