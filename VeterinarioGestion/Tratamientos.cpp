#include "Tratamientos.h"
#include <cstring>

Tratamientos::Tratamientos()
{
    _IDTratamiento = 0;
    strcpy(_NombreTratamiento, "");
    strcpy(_Descripcion, "");
    _DuracionDias = 0;
    _Costo = 0.0f;
}

Tratamientos::Tratamientos(int IDtratamiento, std::string nombreTratamiento, std::string descripcion, int duracionDias, float costo)
{
    setIDTratamiento(IDtratamiento);
    setNombreTratamiento(nombreTratamiento);
    setDescripcion(descripcion);
    setDuracionDias(duracionDias);
    setCosto(costo);
}

void Tratamientos::setIDTratamiento(int IDTratamiento)
{
    _IDTratamiento = IDTratamiento;
}
void Tratamientos::setNombreTratamiento(std::string nombreTratamiento)
{
    strcpy(_NombreTratamiento,nombreTratamiento.c_str());
}
void Tratamientos::setDescripcion(std::string descripcion)
{
    strcpy(_Descripcion, descripcion.c_str());
}
void Tratamientos::setDuracionDias(int duracionDias)
{
    _DuracionDias = duracionDias;
}
void Tratamientos::setCosto(float costo)
{
    _Costo = costo;
}

int Tratamientos::getIDTratamiento()
{
    return _IDTratamiento;
}
std::string Tratamientos::getNombreTratamiento()
{
    return _NombreTratamiento;
}
std::string Tratamientos::getDescripcion()
{
    return _Descripcion;
}
int Tratamientos::getDuracionDias()
{
    return _DuracionDias;
}
float Tratamientos::getCosto()
{
    return _Costo;
}

std::string Tratamientos::toCSV()
{
    return std::to_string(_IDTratamiento) + "," + std::string(_NombreTratamiento) + "," + std::string(_Descripcion) + "," + std::to_string(_DuracionDias) + "," + std::to_string(_Costo);
}
