#include "Animal.h"

Animal::Animal()
{
    std::strcpy(_Especie, "0");
    std::strcpy(_Raza, "0");
    _Peso = 0.0;
    std::strcpy(_Sexo, "0");
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
    std::strcpy(_Especie, Especie.c_str());
}
void Animal::setRaza(std::string Raza)
{
    std::strcpy(_Raza, Raza.c_str());
}
void Animal::setPeso(float Peso)
{
    _Peso = Peso;
}
void Animal::setSexo(std::string Sexo)
{
    std::strcpy(_Sexo, Sexo.c_str());
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

