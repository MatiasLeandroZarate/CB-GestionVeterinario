#include "Mascotas.h"

Mascotas::Mascotas()
    :Animal()
{
    _IDMascota = 0;
    strcpy(_Nombre, "0");
    _Edad = 0;
    _FechaNacimiento = Fecha();
    _IDCliente = 0;
}

Mascotas::Mascotas(int IDMascota, std::string Nombre, std::string Especie, std::string Raza, int Edad, float Peso, std::string Sexo, Fecha FechaNacimiento, int IDCliente)
    :Animal(Especie,Raza,Peso,Sexo)
{
    setIDMascota(IDMascota);
    setNombre(Nombre);
    setEdad(Edad);
    setFechaNacimiento(FechaNacimiento);
    setIDCliente(IDCliente);
}

void Mascotas::setIDMascota(int IDMascota)
{
    _IDMascota = IDMascota;
}
void Mascotas::setNombre(std::string Nombre)
{
    std::strcpy(_Nombre, Nombre.c_str());
}
void Mascotas::setEdad(int Edad)
{
    _Edad = Edad;
}
void Mascotas::setFechaNacimiento(Fecha FechaNacimiento)
{
    _FechaNacimiento = FechaNacimiento;
}
void Mascotas::setIDCliente(int IDCliente)
{
    _IDCliente = IDCliente;
}

int Mascotas::getIDMascota()
{
    return _IDMascota;
}
std::string Mascotas::getNombre()
{
    return _Nombre;
}
int Mascotas::getEdad()
{
    return _Edad;
}
Fecha Mascotas::getFechaNacimiento()
{
    return _FechaNacimiento;
}
int Mascotas::getIDCliente()
{
    return _IDCliente;
}

std::string Mascotas::toCSV()
{
    return std::to_string(_IDMascota) + "," + getNombre() + "," + getEspecie() + "," + getRaza() + "," + std::to_string(_Edad) + "," + std::to_string(_Peso) + "," + getSexo() + "," + _FechaNacimiento.toString() + "," + std::to_string(_IDCliente);
}
