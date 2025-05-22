#pragma once
#include <iostream>
#include <string>
#include "Vacunas.h"
#include "Fecha.h"
#include "Mascotas.h"
#include "Veterinarios.h"

class Vacunaciones
{
private:
	int _IDVacunaciones;
	Vacunas _Vacuna;
	Mascotas _Mascota;
	Fecha _FechaAplicacion;
	Veterinarios _VeterinarioAplicador;

public:
	Vacunaciones();
	Vacunaciones(int idvacunaciones,Vacunas vacuna, Mascotas mascota, Fecha fechaaplicacion, Veterinarios veterinarioaplicador);

	int getIDVacunaciones();
	Vacunas getVacuna();
	Mascotas getMascota();
	Fecha getFechaAplicacion();
	Veterinarios getVeterinarioAplicador();

	void setIDVacunaciones(int idvacunaciones);
	void setVacuna(Vacunas vacuna);
	void setMascota(Mascotas mascota);
	void setFechaAplicacion(Fecha fechaaplicacion);
	void setVeterinarioAplicador(Veterinarios veterinarioaplicador);

	std::string toCSV();

};

