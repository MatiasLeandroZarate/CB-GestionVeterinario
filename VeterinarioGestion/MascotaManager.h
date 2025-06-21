#pragma once
#include "GestorArchivo.h"
#include "Mascotas.h"
#include "Cliente.h"
#include "Validaciones.h"
#include "rlutil.h"
#include <string>
#include <iostream>
#include <optional>

class MascotaManager
{
private:
public:
	void CargarMascota();
	void MostrarMascota();
	void MostrarMascotaPorID();
	std::optional<Mascotas> obtenerMascotaPorId(int idBuscado);

	int BuscarMascotaPorID(int idBuscado);
	int GenerarIdAutomatico();
	int ValidarIdCliente();
    int procesarEntradaMenu(int opcionMinima, int opcionMaxima);

	void MostrarMascotaPorRaza();
	void MostrarMascotaPorEspecie();
	void ModificarMascota();
	void LocateTitulo();

	bool DarDeBajaMascota();
	std::string validarSexo();

};
