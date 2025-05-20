#include "SucursalManager.h"

void SucursalManager::CargarSucursal()
{
    Sucursales sucursal;
    GestorArchivo sArchivo("sucursales.dat");

    int Idsucursal;
    std::string Nombre, Direccion;

    std::cout << "Ingrese el ID de la Sucursal: ";
    std::cin >> Idsucursal;
    std::cout << "Ingrese el Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, Nombre);
    std::cout << "Ingrese la Direccion: ";
    std::getline(std::cin, Direccion);

    sucursal = Sucursales(Idsucursal, Nombre, Direccion);

    if (sArchivo.GuardarSucursal(sucursal))
        {
            std::cout << std::endl;
            std::cout << "La sucursal se guardo correctamente." << std::endl;
        }
    else
        {
            std::cout << "Error al guardar la sucursal." << std::endl;
        }

}

void SucursalManager::MostrarSucursal()
{
    Sucursales sucursal;
    GestorArchivo sArchivo("sucursales.dat");
    int cantidadRegistros = sArchivo.CantidadRegistrosSucursales();
    if (cantidadRegistros == 0)
        {
            std::cout << "No hay Sucursales registrados." << std::endl;
        }

    for (int i = 0; i < cantidadRegistros; i++)
        {
            sucursal = sArchivo.LeerSucursal(i);
            std::cout << sucursal.toCSV() << std::endl;
        }
}

int SucursalManager::BuscarSucursalPorID(int idBuscado)
{
    Sucursales sucursal;
    GestorArchivo sArchivo("sucursales.dat");
    int cantidadRegistros = sArchivo.CantidadRegistrosSucursales();
    for (int i = 0; i < cantidadRegistros; i++)
        {
            sucursal = sArchivo.LeerSucursal(i);
            if (sucursal.getIDSucursal() == idBuscado)
                {
                    return i;
                }
        }
    std::cout << "No se encontró el ID de la Sucursal." << std::endl;
    return -1;
}
