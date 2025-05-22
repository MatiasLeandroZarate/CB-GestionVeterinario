#include "Vacunaciones.h"

Vacunaciones::Vacunaciones()
{
	_IDVacunaciones = 0;
	_Vacuna = Vacunas();
	_Mascota = Mascotas();
	_FechaAplicacion = Fecha();
	_VeterinarioAplicador = Veterinarios();
}

Vacunaciones::Vacunaciones(int vacunaciones,Vacunas vacuna, Mascotas mascota, Fecha fechaaplicacion, Veterinarios veterinarioaplicador)
{	
	setIDVacunaciones(vacunaciones);
	setVacuna(vacuna);
	setMascota(mascota);
	setFechaAplicacion(fechaaplicacion);
	setVeterinarioAplicador(veterinarioaplicador);
}

int Vacunaciones::getIDVacunaciones()
{
	return _IDVacunaciones;
}
Vacunas Vacunaciones::getVacuna()
{
	return _Vacuna;
}
Mascotas Vacunaciones::getMascota()
{
	return _Mascota;
}
Fecha Vacunaciones::getFechaAplicacion()
{
	return _FechaAplicacion;
}
Veterinarios Vacunaciones::getVeterinarioAplicador()
{
	return _VeterinarioAplicador;
}

void Vacunaciones::setIDVacunaciones(int idvacunaciones)
{
	_IDVacunaciones = idvacunaciones;
}
void Vacunaciones::setVacuna(Vacunas vacuna)
{
	_Vacuna = vacuna;
}
void Vacunaciones::setMascota(Mascotas mascota)
{
	_Mascota = mascota;
}
void Vacunaciones::setFechaAplicacion(Fecha fechaaplicacion)
{
	_FechaAplicacion = fechaaplicacion;
}

void Vacunaciones::setVeterinarioAplicador(Veterinarios veterinarioaplicador)
{
	_VeterinarioAplicador = veterinarioaplicador;
}

std::string Vacunaciones::toCSV()
{	
	return std::to_string(_IDVacunaciones)+ "," + _Vacuna.toCSV() + "," + _Mascota.toCSV() + "," + _FechaAplicacion.toString() + "," + _VeterinarioAplicador.toCSV();
}