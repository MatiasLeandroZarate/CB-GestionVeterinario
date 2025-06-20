#include "Fecha.h"

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
       _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

Fecha Fecha::ValidacionFecha(Fecha validar)
{   Validaciones valid;
	Fecha validacion;
	int dia, mes, anio;
	bool fechaok = false;
	while (!fechaok)
	{
		std::cout << "Dia: ";
		//std::cin >> dia;
dia = valid.validarNumero();
		while (dia < 1 || dia >31)
		{
			std::cout << "Dia invalido, por favor, ingrese un dia valido: ";
			dia = valid.validarNumero();
		}
		std::cout << "Mes: ";
		//std::cin >> mes;
mes = valid.validarNumero();
		while (mes < 1 || mes > 12)
		{
			std::cout << "Mes invalido, por favor, ingrese un mes valido: ";
			mes = valid.validarNumero();
		}
		std::cout << "Anio: ";
		anio = valid.validarNumero();
		while (anio < 2010 || anio > 2025)
		{
			std::cout << "Anio invalido, por favor, ingrese un anio valido: ";
			anio = valid.validarNumero();
		}
		// ES AÑO BISIESTO

		if (anio % 4 == 0)
		{
			while (mes == 2 && dia > 29)
			{
				std::cout << "Dia invalido, el Mes tiene 29 dias, ingrese Dia: ";
				dia = valid.validarNumero();
			}
			while ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
			{
				std::cout << "Dia invalido, El mes tiene 30 días, ingrese Dia: ";
				dia = valid.validarNumero();
			}
		}

		else
		{
			while (mes == 2 && dia > 28)
			{
				std::cout << "Dia invalido, el Mes tiene 28 dias, ingrese Dia: ";
				dia = valid.validarNumero();
			}
			while ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
			{
				std::cout << "Dia invalido, El mes tiene 30 días, ingrese Dia: ";
				dia = valid.validarNumero();
			}
		}

		fechaok = true;
	}
	validacion = Fecha(dia, mes, anio);
	return validacion;
}

bool Fecha::equals(Fecha fecha){
    if(_anio == fecha.getAnio() && _mes == fecha.getMes() && _dia == fecha.getDia()){
            return true;
    }

    return false;
}

bool Fecha::isBetween(Fecha desde,Fecha hasta) {
    int valorFechaParametro = _anio * 10000 + _mes * 100 + _dia;
    int valorDesde = desde.getAnio() * 10000 + desde.getMes() * 100 + desde.getDia();
    int valorHasta = hasta.getAnio() * 10000 + hasta.getMes() * 100 + hasta.getDia();

    return valorFechaParametro >= valorDesde && valorFechaParametro <= valorHasta;
}


