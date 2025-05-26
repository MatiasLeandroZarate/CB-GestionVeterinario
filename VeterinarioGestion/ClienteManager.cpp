#include "ClienteManager.h"


void ClienteManager::CargarCliente()
{
    Cliente cliente;
    GestorArchivo gArchivo("clientes.dat");
    int ID = ObtenerSiguienteID();


    std::string DNI, Nombre, Apellido, Telefono, Email;

    std::cout << "Ingrese el DNI: ";
    std::getline(std::cin,DNI);
    std::cout << "Ingrese el Nombre: ";
    //std::cin.ignore();
    std::getline(std::cin, Nombre);
    std::cout << "Ingrese el Apellido: ";
    std::getline(std::cin, Apellido);
    std::cout << "Ingrese el Telefono: ";
    std::cin.ignore();
    std::getline(std::cin, Telefono);
    std::cout << "Ingrese el Email: ";
    std::getline(std::cin, Email);



    cliente = Cliente(ID, DNI, Nombre, Apellido, Telefono, Email);

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

void ClienteManager::MostrarClientes()
{
    Cliente cliente;
    GestorArchivo gArchivo("clientes.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
    if (cantidadRegistros == 0)
        {
            std::cout << "No hay clientes registrados." << std::endl;
        }

    for (int i = 0; i < cantidadRegistros; i++)
        {
            cliente = gArchivo.LeerClientes(i);
            //std::cout << cliente.toCSV() << std::endl;
            std::cout << cliente.toInforme() << std::endl;
        }
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

int ClienteManager::ObtenerSiguienteID()
{
    GestorArchivo gArchivo("clientes.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
    if (cantidadRegistros == 0)
        {
            return 1;
        }
    Cliente ultimoCliente = gArchivo.LeerClientes(cantidadRegistros - 1);
    return ultimoCliente.getIDCliente() + 1;
}
