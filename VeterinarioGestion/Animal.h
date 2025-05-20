#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
#include "Cliente.h"

class Animal
{
protected:
    char _Especie[50];
    char _Raza[50];
    float _Peso;
    char _Sexo[10];


public:
    Animal();
    Animal(std::string Especie, std::string Raza,float Peso, std::string Sexo);

    std::string getEspecie();
    std::string getRaza();
    float getPeso();
    std::string getSexo();

    void setEspecie(std::string Especie);
    void setRaza(std::string Raza);
    void setPeso(float Peso);
    void setSexo(std::string Sexo);


};

