#include "ClienteManager.h"


void ClienteManager::CargarCliente()
{
	Validaciones validar;
	Cliente cliente;
	GestorArchivo gArchivo("clientes.dat");
	std::string DNI, Nombre, Apellido, Telefono, Email;
	bool Activo = true, confirmar = false, buscaDNI = false, guardardato;

	
	std::cin.ignore();
	std::cout << "Ingrese el DNI: ";
	DNI = validar.validarNUMenString();
	
	do {
		buscaDNI = BuscarClientePorDNI(DNI);
		if (buscaDNI)
		{
			std::cout << std::endl << "Ya existe un Cliente con el DNI ingresado." << std::endl;
			confirmar = true;
			guardardato = false;
		}
		else
		{
			std::cout << "Ingrese el Nombre: ";
			//std::cin.ignore();
			Nombre = validar.validarTexto();
			std::cout << "Ingrese el Apellido: ";
			Apellido = validar.validarTexto();
			std::cout << "Ingrese el Telefono: ";
			Telefono = validar.validarNUMenString();
			std::cout << "Ingrese el Email: ";
			//std::cin.ignore();
			std::getline(std::cin, Email) ;

			int ID = SiguienteID();

			cliente = Cliente(ID, DNI, Nombre, Apellido, Telefono, Email,Activo);
			guardardato = true;
			limpiarPantalla();
			confirmar = ConfirmarIngreso(cliente,confirmar);
		}

	} while (!confirmar);
	if (guardardato)
	{
		if (gArchivo.GuardarClientes(cliente))
		{
			std::cout << std::endl;
			std::cout << "Cliente guardado correctamente." << std::endl;
		}
		else
		{
			std::cout << "Error al guardar el cliente." << std::endl;
		}
	}
}

void ClienteManager::MostrarClientes()
{
	Cliente cliente;
	GestorArchivo gArchivo("clientes.dat");
	int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
	if (cantidadRegistros == 0)
	{
		std::cout << "No hay clientes registrados." << std::endl;
	}
	
	TituloLocate();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		cliente = gArchivo.LeerClientes(i);
		rlutil::locate(3, i + 4);
		std::cout << std::to_string(cliente.getIDCliente());
		rlutil::locate(10, i + 4);
		std::cout << cliente.getDNI();
		rlutil::locate(20, i + 4);
		std::cout << cliente.getNombre();
		rlutil::locate(43, i + 4);
		std::cout << cliente.getApellido();
		rlutil::locate(65, i + 4);
		std::cout << cliente.getTelefono();
		rlutil::locate(85, i + 4);
		std::cout << cliente.getEmail();
		rlutil::locate(110, i + 4);
		std::cout << std::to_string(cliente.getActivo());
		
	}
}
void ClienteManager::BuscarCliporDni()
{
	Validaciones validar;
	std::string DNI;
	bool buscaDNI;

	std::cin.ignore();
	std::cout << "Ingrese el DNI: ";
	DNI = validar.validarNUMenString();
	
	buscaDNI = BuscarClientePorDNI(DNI);

}

int ClienteManager::BuscarClientePorID(int idBuscado)
{
	Cliente cliente;
    GestorArchivo gArchivo("clientes.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
    for (int i = 0; i < cantidadRegistros; i++)
    {
        cliente = gArchivo.LeerClientes(i);
        if (cliente.getIDCliente() == idBuscado)
        {
            return i;
        }
    }
	std::cout << "No se encontró el ID del Cliente." << std::endl;
    return -1;
}

int ClienteManager::SiguienteID()
{
	GestorArchivo cArchivo("clientes.dat");
	int cantidadRegistros = cArchivo.CantidadRegistrosClientes();

	return cantidadRegistros + 1;
}

bool ClienteManager::BuscarClientePorDNI(std::string dniBuscado)
{
	Cliente cliente;
	int clientes = 0;
	bool clienteencontrado = false;
	GestorArchivo gArchivo("clientes.dat");
	int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		cliente = gArchivo.LeerClientes(i);
		if (cliente.getDNI() == dniBuscado)
		{
			TituloLocate();

			rlutil::locate(3 ,clientes + 4);
			std::cout << std::to_string(cliente.getIDCliente());
			rlutil::locate(10,clientes + 4);
			std::cout << cliente.getDNI();
			rlutil::locate(20,clientes + 4);
			std::cout << cliente.getNombre();
			rlutil::locate(43,clientes + 4);
			std::cout << cliente.getApellido();
			rlutil::locate(65,clientes + 4);
			std::cout << cliente.getTelefono();
			rlutil::locate(85,clientes + 4);
			std::cout << cliente.getEmail();
			rlutil::locate(110,clientes + 4);
			std::cout << std::to_string(cliente.getActivo());

			clientes++;

			clienteencontrado = true;
			return clienteencontrado;
		}
	}
		if (!clienteencontrado)
		{
		std::cout << "No se encontró el Cliente con el DNI: " << dniBuscado << std::endl;
		return clienteencontrado;
		}
}

bool ClienteManager::BajaCliente()
{
	Validaciones validar;
	std::string dni;
	Cliente cliente;

	GestorArchivo cArchivo("clientes.dat");
	int cantidadRegistros = cArchivo.CantidadRegistrosClientes();
	std::cout << "Ingrese el DNI del Veterinario que desea dar de baja: ";
	std::cin.ignore();
	dni = validar.validarNUMenString();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		cliente = cArchivo.LeerClientes(i);
		if (cliente.getDNI() == dni && cliente.getActivo())
		{
			cliente.setActivo(false);
			if (cArchivo.ModificarClientes(i, cliente))
			{
				std::cout << "Cliente dado de baja exitosamente." << std::endl;
				return true;
			}
			else
			{
				std::cout << "Error baja." << std::endl;
				return false;
			}
		}
	}

	std::cout << "Veterinario no encontrado o ya dado de baja." << std::endl;
	return false;
}

void ClienteManager::MostrarClienteporID()
{
	Validaciones validar;
	Cliente cliente;
	GestorArchivo cArchivo("clientes.dat");
	int cantidadRegistros = cArchivo.CantidadRegistrosClientes();
	int idBuscado;
	int clientes = 0;
	bool encontrado = false;


	std::cout << "Ingrese el ID del Cliente: ";
	idBuscado = validar.validarNumero();

	for (int i = 0; i < cantidadRegistros; i++)
	{
		cliente = cArchivo.LeerClientes(i);
		if (cliente.getIDCliente() == idBuscado)
		{
			TituloLocate();
			rlutil::locate(3, clientes + 4);
			std::cout << std::to_string(cliente.getIDCliente());
			rlutil::locate(10, clientes + 4);
			std::cout << cliente.getDNI();
			rlutil::locate(20, clientes + 4);
			std::cout << cliente.getNombre();
			rlutil::locate(43, clientes + 4);
			std::cout << cliente.getApellido();
			rlutil::locate(65, clientes + 4);
			std::cout << cliente.getTelefono();
			rlutil::locate(85, clientes + 4);
			std::cout << cliente.getEmail();
			rlutil::locate(110, clientes + 4);
			std::cout << std::to_string(cliente.getActivo());

			clientes++;
			encontrado = true;
		}
	}

	if (!encontrado)
	{
		std::cout << "No se encontro Cliente." << std::endl;
	}
}


std::optional<Cliente> ClienteManager::obtenerClientePorId(int idBuscado){
  	Cliente cliente;
	GestorArchivo archivoClientes("clientes.dat");
	int cantidadRegistros = archivoClientes.CantidadRegistrosClientes();

	for (int i = 0; i < cantidadRegistros; i++)
        {
		cliente = archivoClientes.LeerClientes(i);

		if (cliente.getIDCliente() == idBuscado){
            return cliente;
        }
    }

    return std::nullopt;
}

bool ClienteManager::ConfirmarIngreso(Cliente cliente, bool confirmar) 
{
	Validaciones validar;
	std::cout << "Cliente Ingresado: " << std::endl;
	std::cout << "ID Cliente:" << std::endl;
	std::cout << "DNI: " << std::endl;
	std::cout << "Nombre: " << std::endl;
	std::cout << "Apellido: " << std::endl;
	std::cout << "Telefono: " << std::endl;
	std::cout << "Email: " << std::endl;
	std::cout << "Activo: " << std::endl;
	
	rlutil::locate(20, 2);
	std::cout << std::to_string(cliente.getIDCliente());
	rlutil::locate(20, 3);
	std::cout << cliente.getDNI();
	rlutil::locate(20, 4);
	std::cout << cliente.getNombre();
	rlutil::locate(20, 5);
	std::cout << cliente.getApellido();
	rlutil::locate(20, 6);
	std::cout << cliente.getTelefono();
	rlutil::locate(20, 7);
	std::cout << cliente.getEmail();
	rlutil::locate(20, 8);
	std::cout << std::to_string(cliente.getActivo());

	std::cout << std::endl << "Confirma los datos ingresados? 1-Si, 0-No: " << std::endl;
	confirmar = validar.validarBool();
	limpiarPantalla();

	if (confirmar)
	{
		std::cout << "Datos confirmados." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Datos no confirmados, vuelva a ingresar." << std::endl;
		return false;
	}
}
void ClienteManager::MostrarClienteporTEL()
{
	Validaciones validar;
	Cliente cliente;
	GestorArchivo cArchivo("clientes.dat");
	int cantidadRegistros = cArchivo.CantidadRegistrosClientes();
	
	std::string telefonoBuscado;
	int clientes = 0;
	bool encontrado = false;
	
	std::cout << "Ingrese el Telefono del Cliente: ";
	std::cin.ignore();
	telefonoBuscado = validar.validarNUMenString();
	
	for (int i = 0; i < cantidadRegistros; i++)
	{
		cliente = cArchivo.LeerClientes(i);
		if (cliente.getTelefono() == telefonoBuscado)
		{
			TituloLocate();
			rlutil::locate(3, clientes + 4);
			std::cout << std::to_string(cliente.getIDCliente());
			rlutil::locate(10, clientes + 4);
			std::cout << cliente.getDNI();
			rlutil::locate(20, clientes + 4);
			std::cout << cliente.getNombre();
			rlutil::locate(43, clientes + 4);
			std::cout << cliente.getApellido();
			rlutil::locate(65, clientes + 4);
			std::cout << cliente.getTelefono();
			rlutil::locate(85, clientes + 4);
			std::cout << cliente.getEmail();
			rlutil::locate(110, clientes + 4);
			std::cout << std::to_string(cliente.getActivo());
			clientes++;
			encontrado = true;
		}
	}
	if (!encontrado)
	{
		std::cout << "No se encontro el Telefono del Cliente." << std::endl;
	}
}

void ClienteManager::ModificarClientes()
{
	const static std::string OPCION_DNI = "DNI";
	const static std::string OPCION_NOMBRE = "Nombre";
	const static std::string OPCION_APELLIDO = "Apellido";
	const static std::string OPCION_TELEFONO = "Telefono";
	const static std::string OPCION_EMAIL = "Email";
	const static std::string OPCION_ACTIVO = "Activo";
	const static std::string OPCION_SALIR = "Salir";

	const int OPC_DNI = 1;
	const int OPC_NOMBRE = 2;
	const int OPC_APELLIDO = 3;
	const int OPC_TELEFONO = 4;
	const int OPC_EMAIL = 5;
	const int OPC_ACTIVO = 6;
	const int OPC_ATRAS_SALIR = 0;

	Validaciones validar;
	Cliente cliente;
	int opcion, modifico = 1;
	std::string nombre, apellido, dni, telefono, email;
	bool activo;
//------------------------------------------------------
	GestorArchivo cArchivo("clientes.dat");
	int cantidadRegistros = cArchivo.CantidadRegistrosClientes();

	std::cout << "Ingrese el DNI del Cliente a modificar: ";
	std::cin.ignore();
	dni = validar.validarNUMenString();
	for (int i = 0; i < cantidadRegistros; i++)
	{
		cliente = cArchivo.LeerClientes(i);


		if (cliente.getDNI() == dni)
		{
	
			do {
				limpiarPantalla();
				std::cout << "Datos actuales:";
				TituloLocate();
				rlutil::locate(3, 4);
				std::cout << std::to_string(cliente.getIDCliente());
				rlutil::locate(10,  4);
				std::cout << cliente.getDNI();
				rlutil::locate(20,  4);
				std::cout << cliente.getNombre();
				rlutil::locate(43,  4);
				std::cout << cliente.getApellido();
				rlutil::locate(65,  4);
				std::cout << cliente.getTelefono();
				rlutil::locate(85,  4);
				std::cout << cliente.getEmail();
				rlutil::locate(110,  4);
				std::cout << std::to_string(cliente.getActivo());
				

				std::cout << std::endl << "-----------------------------------------" << std::endl;
				std::cout << OPC_DNI << ". " << OPCION_DNI << std::endl;
				std::cout << OPC_NOMBRE << ". " << OPCION_NOMBRE << std::endl;
				std::cout << OPC_APELLIDO << ". " << OPCION_APELLIDO << std::endl;
				std::cout << OPC_TELEFONO << ". " << OPCION_TELEFONO << std::endl;
				std::cout << OPC_EMAIL << ". " << OPCION_EMAIL << std::endl;
				std::cout << OPC_ACTIVO << ". " << OPCION_ACTIVO << std::endl;
				std::cout << OPC_ATRAS_SALIR << ". " << OPCION_SALIR << std::endl;

				opcion = procesarEntradaMenu(OPC_ATRAS_SALIR, OPC_ACTIVO);
				std::cin.ignore();

				switch (opcion)
				{
				case OPC_DNI:
					std::cout << std::endl << "DNI del Cliente actual: " << cliente.getDNI();
					std::cout << std::endl << "Ingrese nuevo DNI: ";
					dni = validar.validarNUMenString();
					cliente.setDNI(dni);
					modifico++;
					break;
				case OPC_NOMBRE:
					std::cout << std::endl << "Nombre actual: " << cliente.getNombre();
					std::cout << std::endl << "Ingrese nuevo Nombre: ";
					nombre = validar.validarTexto();
					cliente.setNombre(nombre);
					modifico++;
					break;

				case OPC_APELLIDO:
					std::cout << std::endl << "Apellido actual: " << cliente.getApellido();
					std::cout << std::endl << "Ingrese nuevo Apellido: ";
					apellido = validar.validarTexto();
					cliente.setApellido(apellido);
					modifico++;
					break;

				case OPC_TELEFONO:
					std::cout << std::endl << "Telefono actual: " << cliente.getTelefono();
					std::cout << std::endl << "Ingrese el Nuevo Tel: ";
					telefono = validar.validarNUMenString();
					cliente.setTelefono(telefono);
					modifico++;
					break;

				case OPC_EMAIL:
					int posEspecialidad;
					std::cout << std::endl << "Email actual: " << cliente.getEmail();
					std::cout << std::endl << "Ingrese nuevo Email: ";
					std::getline(std::cin,email);
					
					modifico++;
					break;

				case OPC_ACTIVO:
					std::cout << std::endl << "Status actual: " << cliente.getActivo();
					std::cout << std::endl << "Activo (1: Si / 0: No): ";
					activo = validar.validarBool();
					cliente.setActivo(activo);
					modifico++;
					break;

				case OPC_ATRAS_SALIR:
					modifico--;
					limpiarPantalla();
					break;
				}

			} while (opcion != OPC_ATRAS_SALIR);


			if (modifico != 0)
			{
				if (cArchivo.ModificarClientes(i, cliente))
				{
					std::cout << "el Cliente se ha guardado correctamente." << std::endl;
				}
				else
				{
					std::cout << "Error al guardar." << std::endl;
				}
				return;
			}
			else
			{
				std::cout << "No ha modificado ningun dato." << std::endl;
				return;
			}
		}
	}

	std::cout << "No se encontró el Cliente con ese DNI." << std::endl;
}


int ClienteManager::procesarEntradaMenu(int opcionMinima, int opcionMaxima)
{
	int opcion;

	while (true)
	{
		std::cout << std::endl << "Seleccione que dato quiere Modificar: ";

		if (std::cin >> opcion)
		{
			if (opcion >= opcionMinima && opcion <= opcionMaxima)
			{
				limpiarPantalla();
				return opcion;
			}
			else
			{
				std::cout << "ERROR: Debe ingresar un numero entre " << opcionMinima << " y " << opcionMaxima << "." << std::endl;
			}
		}
		else
		{
			std::cout << "ERROR: Debe ingresar solamente numeros enteros, con valores entre el " << opcionMinima << " y el " << opcionMaxima << "." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}

void ClienteManager::TituloLocate()
{
	int y = 3;
	rlutil::locate(1, y);
	std::cout << "ID Cl. ";
	rlutil::locate(8, y);
	std::cout << "| DNI: ";
	rlutil::locate(19, y);
	std::cout << "| Nombre";
	rlutil::locate(41, y);
	std::cout << "| Apellido";
	rlutil::locate(63, y);
	std::cout << "| Telefono";
	rlutil::locate(82, y);
	std::cout << "| Email";
	rlutil::locate(108, y);
	std::cout << "| Activo";
}