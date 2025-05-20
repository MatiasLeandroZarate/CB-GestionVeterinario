#include "Cliente.h"

Cliente::Cliente()
    : Persona()
{
    _IDCliente = 0;
    std::strcpy(_Telefono, "0");
    std::strcpy(_Email, "0");
}

Cliente::Cliente(int IDCliente, std::string DNI, std::string Nombre, std::string Apellido, std::string Telefono, std::string Email)
    :Persona(DNI, Nombre, Apellido)
{
    setIDCliente(IDCliente);
    setTelefono(Telefono);
    setEmail(Email);
}


void Cliente::setIDCliente(int IDCliente)
{
    _IDCliente = IDCliente;
}

void Cliente::setTelefono(std::string Telefono)
{
    std::strcpy(_Telefono, Telefono.c_str());
}
void Cliente::setEmail(std::string Email)
{
    std::strcpy(_Email, Email.c_str());
}

int Cliente::getIDCliente()
{
    return _IDCliente;
}

std::string Cliente::getTelefono()
{
    return _Telefono;
}

std::string Cliente::getEmail()
{
    return _Email;
}

std::string Cliente::toCSV()
{
    return std::to_string(_IDCliente) + "," + getDNI() + "," + getNombre() + "," + getApellido() + "," + std::string(_Telefono) + "," + std::string(_Email);
}
