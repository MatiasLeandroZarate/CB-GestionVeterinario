#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
#include "Especialidades.h"

class Veterinarios : public Persona
{
private:
    int _IDVeterinario;
    int _Matricula;
    Especialidades _Especialidad;
    bool _Activo;
public:
    Veterinarios();
    Veterinarios(int IDVeterinario, int Matricula, std::string DNI, std::string Nombre, std::string Apellido, Especialidades especialidad, bool Activo);

    int getIDVeterinario();
    int getMatricula();
    Especialidades getEspecialidad();
    bool getActivo();

    void setIDVeterinario(int IDVeterinario);
    void setMatricula(int Matricula);
    void setEspecialidad(Especialidades especialidad);
    void setActivo(bool Activo);

    std::string toCSV();

};

