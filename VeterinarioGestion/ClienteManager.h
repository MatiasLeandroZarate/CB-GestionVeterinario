#pragma once
#include "GestorArchivo.h"
#include "Cliente.h"
#include "Validaciones.h"
#include <string>
#include <iostream>
#include <optional>
#include "rlutil.h"


class ClienteManager
{
private:
public:
	void CargarCliente();
	void MostrarClientes();
	void TituloLocate();
	void BuscarCliporDni();
	void MostrarClienteporID();
	void MostrarClienteporTEL();
	void ModificarClientes();

	int BuscarClientePorID(int idBuscado);
	int SiguienteID();
	int procesarEntradaMenu(int opcionMinima, int opcionMaxima);
  
	bool BuscarClientePorDNI(std::string dniBuscado);
	bool ConfirmarIngreso(Cliente cliente, bool confirmar);
	bool BajaCliente();

	std::optional<Cliente> obtenerClientePorId(int idBuscado);
};
