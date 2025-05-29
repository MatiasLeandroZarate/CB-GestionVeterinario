#include "Mascotas.h"

Mascotas::Mascotas()
{
	_IDMascota = 0;
	strcpy(_Nombre, "0");
	strcpy(_Especie, "0");
	strcpy(_Raza, "0");
	_Edad = 0;
	_Peso = 0.0;
	strcpy(_Sexo, "0");
	_FechaNacimiento = Fecha();
	_IDCliente = 0;
}

Mascotas::Mascotas(int IDMascota, std::string Nombre, std::string Especie, std::string Raza, int Edad, float Peso, std::string Sexo, Fecha FechaNacimiento, int IDCliente)
{
	setIDMascota(IDMascota);
	setNombre(Nombre);
	setEspecie(Especie);
	setRaza(Raza);
	setEdad(Edad);
	setPeso(Peso);
	setSexo(Sexo);
	setFechaNacimiento(FechaNacimiento);
	setIDCliente(IDCliente);
}

void Mascotas::setIDMascota(int IDMascota)
{
	_IDMascota = IDMascota;
}
void Mascotas::setNombre(std::string Nombre)
{
	strcpy(_Nombre, Nombre.c_str());
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
void Mascotas::setEspecie(std::string Especie)
{
	strcpy(_Especie, Especie.c_str());
}
void Mascotas::setRaza(std::string Raza)
{
	strcpy(_Raza, Raza.c_str());
}
void Mascotas::setPeso(float Peso)
{
	_Peso = Peso;
}
void Mascotas::setSexo(std::string Sexo)
{
	strcpy(_Sexo, Sexo.c_str());
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
std::string Mascotas::getEspecie()
{
	return _Especie;
}
std::string Mascotas::getRaza()
{
	return _Raza;
}
float Mascotas::getPeso()
{
	return _Peso;
}
std::string Mascotas::getSexo()
{
	return _Sexo;
}







std::string Mascotas::toCSV()
{
	return std::to_string(_IDMascota) + "," + getNombre() + "," + getEspecie() + "," + getRaza() + "," + std::to_string(_Edad) + "," + std::to_string(_Peso) + "," + getSexo() + "," + _FechaNacimiento.toString() + "," + std::to_string(_IDCliente);
}