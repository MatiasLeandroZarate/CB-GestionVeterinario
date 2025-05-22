#include "Animal.h"

Animal::Animal()
{
	strcpy(_Especie, "0");
	strcpy(_Raza, "0");
	_Peso = 0.0;
	strcpy(_Sexo, "0");
}

Animal::Animal(std::string Especie, std::string Raza,float Peso, std::string Sexo)
{
	setEspecie(Especie);
	setRaza(Raza);
	setPeso(Peso);
	setSexo(Sexo);
	
}

void Animal::setEspecie(std::string Especie)
{
	strcpy(_Especie, Especie.c_str());
}
void Animal::setRaza(std::string Raza)
{
	strcpy(_Raza, Raza.c_str());
}
void Animal::setPeso(float Peso)
{
	_Peso = Peso;
}
void Animal::setSexo(std::string Sexo)
{
	strcpy(_Sexo, Sexo.c_str());
}



std::string Animal::getEspecie()
{
	return _Especie;
}
std::string Animal::getRaza()
{
	return _Raza;
}
float Animal::getPeso()
{
	return _Peso;
}
std::string Animal::getSexo()
{
	return _Sexo;
}

