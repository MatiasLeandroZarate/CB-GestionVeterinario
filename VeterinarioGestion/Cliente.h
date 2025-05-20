#pragma once
#include <iostream>
#include <cstring>
#include "Persona.h"

class Cliente : public Persona
{
private:
    int _IDCliente;
    char _Telefono[20];
    char _Email[50];

public:
    Cliente();
    Cliente(int IDCliente, std::string DNI, std::string Nombre, std::string Apellido, std::string Telefono, std::string Email);

    int getIDCliente();
    std::string getTelefono();
    std::string getEmail();

    void setIDCliente(int IDCliente);
    void setTelefono(std::string Telefono);
    void setEmail(std::string Email);

    std::string toCSV();

};
