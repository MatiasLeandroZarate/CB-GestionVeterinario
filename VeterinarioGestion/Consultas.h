#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
#include "Mascotas.h"
#include "Sucursales.h"
#include "Veterinarios.h"
#include "Tratamientos.h"

class Consultas
{
private:
    int _IDConsultas;
    int _IDMascota;
    Fecha _Fecha;
    char _Sintomas[100];
    char _Diagnostico[100];
    Tratamientos _Tratamiento;
    Fecha _FechaProximaVisita;
    int _IDVeterinario;
    int _IDSucursal;
public:
    Consultas();
    Consultas(int idconsultas, int idmascotas, Fecha fecha, std::string sintomas, std::string diagnostico, Tratamientos tratamiento, Fecha fechaproximavisita, int idveterinario, int idsucursal);

    void setIDConsultas(int idconsultas);
    void setIDMascotas(int idmascotas);
    void setFecha(Fecha fecha);
    void setSintomas(std::string sintomas);
    void setDiagnostico(std::string diagnostico);
    void setTratamiento(Tratamientos tratamiento);
    void setFechaproximavisita(Fecha fechaproximavisita);
    void setIDVeterinario(int idveterinario);
    void setIDSucursal(int idsucursal);

    int getIDConsultas();
    int getIDMascotas();
    Fecha getFecha();
    std::string getSintomas();
    std::string getDiagnostico();
    Tratamientos getTratamiento();
    Fecha getFechaproximavisita();
    int getIDVeterinario();
    int getIDSucursal();

    std::string toCSV();

};

