#include "Veterinarios.h"
#include <cstring>

Veterinarios::Veterinarios()
: Persona(){
	_IDVeterinario = 0;
	_Matricula = 0;
	strcpy(_DNI, "0");
	strcpy(_Nombre, "0");
	strcpy(_Apellido, "0");
}

Veterinarios::Veterinarios(int IDVeterinario, int Matricula, std::string DNI, std::string Nombre, std::string Apellido, Especialidades especialidad, bool Activo)
:Persona(DNI,Nombre,Apellido,Activo){
	setIDVeterinario(IDVeterinario);
	setMatricula(Matricula);
	setEspecialidad(especialidad);

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



std::string Veterinarios::toCSV()
{
	return std::to_string(_IDVeterinario) + "," + std::to_string(_Matricula) + "," + getDNI() + "," + getNombre() + "," + getApellido() + "," + _Especialidad.toCSV() + "," + std::to_string(_Activo);
}

std::string Veterinarios::toInforme()
{
	return std::to_string(_IDVeterinario) + "\t\t" + std::to_string(_Matricula) + "\t\t" + getDNI()+ " " + getNombre() + "\t\t" + getApellido() + "\t\t" + _Especialidad.toInforme() + "\t" + std::to_string(getActivo());
}

std::string Veterinarios::toCSVHeader(){
    return "id,matricula,dni,nombre,apellido,idEspecialidad,estado";
}


