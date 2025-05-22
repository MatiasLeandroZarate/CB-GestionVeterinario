#pragma once
#include "GestorArchivo.h"
#include "Cliente.h"
#include <string>
#include <iostream>


class ClienteManager
{	
private:
public:
	void CargarCliente();
	void MostrarClientes();
	int BuscarClientePorID(int idBuscado);
	int ObtenerSiguienteID();
};

