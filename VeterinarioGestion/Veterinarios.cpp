#include "Veterinarios.h"
#include <cstring>

Veterinarios::Veterinarios()
    : Persona()
{
    _IDVeterinario = 0;
    _Matricula = 0;
    _Activo = false;
    strcpy(_DNI, "0");
    strcpy(_Nombre, "0");
    strcpy(_Apellido, "0");
}

Veterinarios::Veterinarios(int IDVeterinario, int Matricula, std::string DNI, std::string Nombre, std::string Apellido, Especialidades especialidad, bool Activo)
    :Persona(DNI,Nombre,Apellido)
{
    setIDVeterinario(IDVeterinario);
    setMatricula(Matricula);
    setEspecialidad(especialidad);
    setActivo(Activo);
}

int Veterinarios::getIDVeterinario()
{
    return _IDVeterinario;
}
int Veterinarios::getMatricula()
{
    return _Matricula;
}
Especialidades Veterinarios::getEspecialidad()
{
    return _Especialidad;
}
bool Veterinarios::getActivo()
{
    return _Activo;
}
void Veterinarios::setIDVeterinario(int IDVeterinario)
{
    _IDVeterinario = IDVeterinario;
}
void Veterinarios::setMatricula(int Matricula)
{
    _Matricula = Matricula;
}
void Veterinarios::setEspecialidad(Especialidades especialidad)
{
    _Especialidad = especialidad;
}
void Veterinarios::setActivo(bool Activo)
{
    _Activo = Activo;
}


std::string Veterinarios::toCSV()
{
    return std::to_string(_IDVeterinario) + "," + std::to_string(_Matricula) + "," + getNombre() + "," + getApellido() + "," + _Especialidad.toCSV() + "," + std::to_string(_Activo);
}
