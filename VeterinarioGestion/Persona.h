#pragma once
#include <iostream>
#include <string>

class Persona {
protected:
    char _DNI[15];
    char _Nombre[50];
    char _Apellido[50];

public:
    Persona();
	Persona(std::string DNI, std::string Nombre, std::string Apellido);
    std::string getDNI();
    std::string getNombre();
    std::string getApellido();
    void setDNI(std::string DNI);
    void setNombre(std::string Nombre);
    void setApellido(std::string Apellido);

};

