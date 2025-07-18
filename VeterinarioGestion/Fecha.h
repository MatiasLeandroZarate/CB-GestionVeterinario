#pragma once
#include <iostream>
#include <string>
#include "Validaciones.h"

class Fecha{
    private:
    int _dia, _mes, _anio;

    public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    std::string toString();

    Fecha ValidacionFecha(Fecha validar);
    bool equals(Fecha fecha);
    bool isBetween(Fecha desde,Fecha hasta);
};
