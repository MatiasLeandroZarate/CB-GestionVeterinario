#include "Especialidades.h"
#include <cstring>

Especialidades::Especialidades()
{
    _IDEspecialidad = 0;
    strcpy(_Nombre, "");
    strcpy(_Descripcion, "");
}

Especialidades::Especialidades(int IDEspecialidad, std::string Nombre, std::string Descripcion)
{
    setIDEspecialidad(IDEspecialidad);
    setNombre(Nombre);
    setDescripcion(Descripcion);
}

int Especialidades::getIDEspecialidad()
{
    return _IDEspecialidad;
}
std::string Especialidades::getNombre()
{
    return std::string(_Nombre);
}
std::string Especialidades::getDescripcion()
{
    return std::string(_Descripcion);
}

void Especialidades::setIDEspecialidad(int IDEspecialidad)
{
    _IDEspecialidad = IDEspecialidad;
}
void Especialidades::setNombre(std::string Nombre)
{
    strcpy(_Nombre, Nombre.c_str());
}
void Especialidades::setDescripcion(std::string Descripcion)
{
    strcpy(_Descripcion, Descripcion.c_str());
}

std::string Especialidades::toCSV()
{
    return std::to_string(_IDEspecialidad) + "," + std::string(_Nombre) + "," + std::string(_Descripcion);
}
