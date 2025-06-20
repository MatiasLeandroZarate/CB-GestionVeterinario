#include "Cliente.h"

Cliente::Cliente(): Persona(){
    _IDCliente = 0;
	strcpy(_Telefono, "0");
	strcpy(_Email, "0");
}

Cliente::Cliente(int IDCliente, std::string DNI, std::string Nombre, std::string Apellido, std::string Telefono, std::string Email, bool Activo)
:Persona(DNI, Nombre, Apellido ,Activo){
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
	strcpy(_Telefono, Telefono.c_str());
}
void Cliente::setEmail(std::string Email)
{
	strcpy(_Email, Email.c_str());
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

std::string Cliente::toCSVHeader(){
    return "id,dni,nombre,apellido,telefono,email,activo";
}

std::string Cliente::toCSV()
{
	return std::to_string(_IDCliente) + "," + getDNI() + "," + getNombre() + "," + getApellido() + "," + std::string(_Telefono) + "," + std::string(_Email) + "," + (_Activo ? "1" : "0");
}

std::string Cliente::toInforme()
{
	return std::to_string(_IDCliente) + "\t" + getDNI() + "\t" + getNombre() + "\t" + getApellido() + "\t\t" + std::string(_Telefono) + "\t" + std::string(_Email);
}
