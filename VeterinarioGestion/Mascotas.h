#pragma once
#include <iostream>
#include <cstring>

#include "Fecha.h"


class Mascotas
{
private:
    int _IDMascota;
    char _Nombre[50];
    char _Especie[50];
    char _Raza[50];
    int _Edad;
    float _Peso;
    char _Sexo[10];
    Fecha _FechaNacimiento;
    int _IDCliente;
    bool _Activo;


public:
    Mascotas();
    Mascotas(int IDMascota, std::string Nombre, std::string Especie, std::string Raza, int Edad, float Peso, std::string Sexo, Fecha FechaNacimiento, int IDCliente, bool Activo);

    void setIDMascota(int IDMascota);
    void setNombre(std::string Nombre);
    void setEdad(int Edad);
    void setFechaNacimiento(Fecha FechaNacimiento);
    void setIDCliente(int IDCliente);
    void setEspecie(std::string Especie);
    void setRaza(std::string Raza);
    void setPeso(float Peso);
    void setSexo(std::string Sexo);
    void setActivo(bool Activo);

    std::string getEspecie();
    std::string getRaza();
    float getPeso();
    std::string getSexo();
    int getIDMascota();
    std::string getNombre();
    int getEdad();
    Fecha getFechaNacimiento();
    int getIDCliente();
    bool getActivo();

    std::string toInforme();
    std::string toCSV();
};

