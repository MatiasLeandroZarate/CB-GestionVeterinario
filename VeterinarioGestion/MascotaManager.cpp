#include "MascotaManager.h"

void MascotaManager::CargarMascota()
{
    Mascotas mascota;
    GestorArchivo gArchivo("mascotas.dat");
    int IDMascota, Edad, IDCliente;
    std::string Nombre, Especie, Raza, Sexo;
    float Peso;
    Fecha FechaNacimiento, fechavalidar;

    std::cout << "Ingrese el ID de la Mascota: ";
    std::cin >> IDMascota;
    std::cout << "Ingrese el Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, Nombre);
    std::cout << "Ingrese la Especie: ";
    std::getline(std::cin, Especie);
    std::cout << "Ingrese la Raza: ";
    std::getline(std::cin, Raza);
    std::cout << "Ingrese la Edad: ";
    std::cin >> Edad;
    std::cout << "Ingrese el Peso en Kg: ";
    std::cin >> Peso;
    std::cout << "Ingrese el Sexo: ";
    std::cin.ignore();
    std::getline(std::cin, Sexo);
    std::cout << "Ingrese la Fecha de Nacimiento: " << std::endl;

    FechaNacimiento = fechavalidar.ValidacionFecha(FechaNacimiento);

    std::cout << "Ingrese el ID del Cliente: ";
    std::cin >> IDCliente;


    mascota = Mascotas(IDMascota, Nombre, Especie, Raza, Edad, Peso, Sexo, FechaNacimiento, IDCliente);

    if (gArchivo.GuardarMascotas(mascota))
        {
            std::cout << std::endl;
            std::cout << "Mascota guardada correctamente." << std::endl;
        }
    else
        {
            std::cout << "Error al guardar la mascota." << std::endl;
        }
}

void MascotaManager::MostrarMascota()
{
    Mascotas mascotas;
    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();
    if (cantidadRegistros == 0)
        {
            std::cout << "No hay clientes registrados." << std::endl;
        }

    for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas = gArchivo.LeerMascota(i);
            std:: cout << mascotas.toInforme() << std::endl;
            //std::cout << mascotas.toCSV() << std::endl;
        }
}

int MascotaManager::BuscarMascotaPorID(int idBuscado)
{
    Mascotas mascotas;
    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();
    for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas= gArchivo.LeerMascota(i);
            if (mascotas.getIDMascota() == idBuscado)
                {
                    return i;
                }
        }
    std::cout << "No se encontró el ID de la Mascota." << std::endl;
    return -1;
}

//int ObtenerSiguienteID()
//{
//	GestorArchivo gArchivo("mascotas.dat");
//	int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
//	if (cantidadRegistros == 0)
//	{
//		return 1;
//	}
//	Cliente ultimoCliente = gArchivo.Leer(cantidadRegistros - 1);
//	return ultimoCliente.getIDCliente() + 1;
//}

