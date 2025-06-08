#pragma once
#include <iostream>
#include <string>

class Persona {
protected:
    char _DNI[15];
    char _Nombre[50];
    char _Apellido[50];
    bool _Activo;

public:
    Persona();
	Persona(std::string DNI, std::string Nombre, std::string Apellido,bool Activo);
    std::string getDNI();
    std::string getNombre();
    std::string getApellido();
    bool getActivo();

    void setDNI(std::string DNI);
    void setNombre(std::string Nombre);
    void setApellido(std::string Apellido);
    void setActivo(bool Activo);

};

