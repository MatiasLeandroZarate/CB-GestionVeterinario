#pragma once
#include "GestorArchivo.h"
#include "Cliente.h"
#include <string>
#include <iostream>
#include "optional"

class ClienteManager
{
private:
public:
	void CargarCliente();
	void MostrarClientes();
	int BuscarClientePorID(int idBuscado);
	int ObtenerSiguienteID();
	void BuscarClientePorDNI(std::string dniBuscado);
    std::optional<Cliente> obtenerClientePorId(int idBuscado);
};
