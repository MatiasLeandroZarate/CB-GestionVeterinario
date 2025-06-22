#include "SucursalManager.h"

void SucursalManager::CargarSucursal()
{
	Sucursales sucursal;
	GestorArchivo sArchivo("sucursales.dat");
	Validaciones validar;

	int Idsucursal;
	std::string Nombre, Direccion;
    float recaudacion = 0;

	Idsucursal = GenerarIdAutomatico();
	std::cout << "Ingrese el Nombre: ";
	Nombre = validar.validarLetra();

	std::cout << "Ingrese la Direccion: ";
	Direccion = validar.validarLetra();


	sucursal = Sucursales(Idsucursal, Nombre, Direccion,recaudacion);

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

	  LocateTitulo();
    std::cout << std::endl;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        sucursal = sArchivo.LeerSucursal(i);

        rlutil::locate(3, i + 3);
        std::cout << sucursal.getIDSucursal();

        rlutil::locate(14, i + 3);
        std::cout << sucursal.getNombre();

        rlutil::locate(37, i + 3);
        std::cout << sucursal.getDireccion();

        rlutil::locate(57, i + 3);
        std::cout << sucursal.getRecaudacion();




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


std::optional<Sucursales> SucursalManager::obtenerSucursalPorId(int idBuscado){
    Sucursales sucursal;
	GestorArchivo sArchivo("sucursales.dat");

	int cantidadRegistros = sArchivo.CantidadRegistrosSucursales();

    for (int i = 0; i < cantidadRegistros; i++) {
		sucursal = sArchivo.LeerSucursal(i);
        if (sucursal.getIDSucursal() == idBuscado) {
            return sucursal;
        }
    }

    return std::nullopt;
}

int SucursalManager::GenerarIdAutomatico()
{

    GestorArchivo gArchivo("sucursales.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosSucursales();

    return cantidadRegistros + 1;
}
void SucursalManager::LocateTitulo()
{

    rlutil::locate(1, 2);
    std::cout << "IDSucursal ";

    rlutil::locate(12, 2);
    std::cout << "| Nombre";

    rlutil::locate(35, 2);
    std::cout << "| Direccion";

    rlutil::locate(55, 2);
    std::cout << "| Recaudacion";

}
void SucursalManager::ModificarSucursal()
{
    const static std::string OPCION_NOMBRE = "Nombre";
    const static std::string OPCION_DIRECCION = "Direccion";
    const static std::string OPCION_SALIR = "Salir";

    const int OPC_NOMBRE = 1;
    const int OPC_DIRECCION = 2;
    const int OPC_ATRAS_SALIR = 0;

    Validaciones validar;
    Sucursales sucursal;
    int ID, opcion, modifico = 1;
    std::string Nombre, Direccion;


    GestorArchivo sArchivo("sucursales.dat");
    int cantidadRegistros = sArchivo.CantidadRegistrosSucursales();

    std::cout << "Ingrese el ID de la Sucursal a modificar: ";
    std::cin.ignore();
    ID = validar.validarNumero();

    for (int i = 0; i < cantidadRegistros; i++)
    {
        sucursal = sArchivo.LeerSucursal(i);
        if (sucursal.getIDSucursal() == ID)
        {
            do
            {
                limpiarPantalla();
                std::cout << "Datos actuales:" << std::endl;
                LocateTitulo();

                rlutil::locate(3, i + 3);
                std::cout << sucursal.getIDSucursal();
                rlutil::locate(14, i + 3);
                std::cout << sucursal.getNombre();
                rlutil::locate(37, i + 3);
                std::cout << sucursal.getDireccion();
                rlutil::locate(57, i + 3);
                std::cout << sucursal.getRecaudacion();


                std::cout << std::endl << "-----------------------------------------" << std::endl;
                std::cout << OPC_NOMBRE << ". " << OPCION_NOMBRE << std::endl;
                std::cout << OPC_DIRECCION << ". " << OPCION_DIRECCION << std::endl;
                std::cout << OPC_ATRAS_SALIR << ". " << OPCION_SALIR << std::endl;

                opcion = procesarEntradaMenu(OPC_ATRAS_SALIR, OPC_DIRECCION);
                std::cin.ignore();

                switch (opcion)
                {
                case OPC_NOMBRE:
                    std::cout << "Nombre actual: " << sucursal.getNombre() << std::endl;
                    std::cout << "Ingrese nuevo nombre: ";
                    Nombre = validar.validarLetra();
                    sucursal.setNombre(Nombre);
                    modifico++;
                    break;

                case OPC_DIRECCION:
                    std::cout << "Direccion actual: " << sucursal.getDireccion() << std::endl;
                    std::cout << "Ingrese nueva direccion: ";
                    Direccion = validar.validarLetra();
                    sucursal.setDireccion(Direccion);
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
                if (sArchivo.ModificarSucursal(i, sucursal))
                {
                    std::cout << "Sucursal modificada correctamente." << std::endl;
                }
                else
                {
                    std::cout << "Error al guardar la sucursal." << std::endl;
                }
                return;
            }
            else
            {
                std::cout << "No ha modificado ningún dato." << std::endl;
                return;
            }
        }
    }

    std::cout << "No se encontró una sucursal con ese ID." << std::endl;
}
int SucursalManager::procesarEntradaMenu(int opcionMinima, int opcionMaxima)
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

