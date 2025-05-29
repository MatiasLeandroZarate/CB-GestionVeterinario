#include "MascotaManager.h"

void MascotaManager::CargarMascota()
{
    Mascotas mascota;
    GestorArchivo gArchivo("mascotas.dat");
    int IDMascota, Edad, IDCliente;
    std::string Nombre, Especie, Raza, Sexo;
    float Peso;
    Fecha FechaNacimiento, fechavalidar;

    std::cout << "Ingrese el ID de la Mascota: "; // falta hacer ID automatico (se muestra al final el ID que le toco a la mascota)
    std::cin >> IDMascota;

    std::cin.ignore();
    Nombre = validarNombre();

    Especie = validarEspecie();

    Raza = validarRaza();

    Edad = validarEdad();

    Peso = validarPeso();

    std::cout << "Ingrese el Sexo 1.- Hembra 2.- Macho: ";
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

int MascotaManager::validarEdad()
{
    std::string edadIngresada;
    bool edadValida = false;
    int Edad;

    while (!edadValida)
    {

        std::cout << "Ingrese la Edad: ";
        std::getline(std::cin, edadIngresada);
        edadValida = true;
        int i = 0;


        while (edadIngresada[i] != '\0')  // Validacion de que todos los caracteres sean numeros y no letras o caracteres
        {
            if (edadIngresada[i] < '0' || edadIngresada[i] > '9')
            {
                edadValida = false;
            }
            i++;
        }


        if (edadValida)
        {
            Edad = 0;
            i = 0;
            while (edadIngresada[i] != '\0')
            {
                Edad = Edad * 10 + (edadIngresada[i] - '0');
                i++;
            }
        }
        if(Edad < 0)
        {
            edadValida = false;

        }
        if (!edadValida)
        {
            std::cout << "Edad inválida, Ingrese de nuevo." << std::endl;

        }

    }
    return Edad;
}

std::string MascotaManager::validarNombre()
{
    std::string Nombre;
    bool nombreValido = false;

    while(!nombreValido)
    {
        int i = 0;
        nombreValido = true;

        std::cout << "Ingrese el Nombre: ";
        std::getline(std::cin, Nombre);

        while (Nombre[i])
        {

            char c = Nombre[i];
            if (!((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') ||c == ' '))
            {
                nombreValido = false;
            }
            i++;
        }

        if(!nombreValido)
        {
            std::cout << "Nombre Invalido, Ingresar Nuevamente." << std::endl;
        }

    }

    return Nombre;


}
std::string MascotaManager::validarEspecie()
{
    std::string Especie;
    bool especieValido = false;

    while(!especieValido)
    {
        int i = 0;
        especieValido = true;

        std::cout << "Ingrese Especie: ";
        std::getline(std::cin, Especie);

        while (Especie[i])
        {

            char c = Especie[i];
            if (!((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') ||c == ' '))
            {
                especieValido = false;
            }
            i++;
        }

        if(!especieValido)
        {
            std::cout << "Especie Invalido, Ingresar Nuevamente." << std::endl;
        }

    }

    return Especie;


}

std::string MascotaManager::validarRaza()
{
    std::string Raza;
    bool razaValido = false;

    while(!razaValido)
    {
        int i = 0;
        razaValido = true;

        std::cout << "Ingrese el Raza: ";
        std::getline(std::cin, Raza);

        while (Raza[i])
        {

            char c = Raza[i];
            if (!((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') ||c == ' '))
            {
                razaValido = false;
            }
            i++;
        }

        if(!razaValido)
        {
            std::cout << "Raza Invalida, Ingresar Nuevamente." << std::endl;
        }

    }

    return Raza;


}

int MascotaManager::validarPeso()
{
    std::string pesoIngresado;
    bool pesoValido = false;
    float Peso = 0;

    while (!pesoValido)
    {
        pesoValido = true;
        std::cout << "Ingrese el Peso: ";
        std::getline(std::cin, pesoIngresado);

        int i = 0;
        int puntos = 0;

        while (pesoIngresado[i] != '\0')
        {
            char c = pesoIngresado[i];

            if (c == '.')
            {
                puntos++;
                if (puntos > 1)
                {
                    pesoValido = false;

                }
            }
            else if (c < '0' || c > '9')
            {
                pesoValido = false;

            }

            i++;
        }

        if (pesoValido)
        {
            Peso = std::stof(pesoIngresado); // stof significa string to float, convierte el numero de formato string a float de forma mas facil

            if (Peso <= 0)

                pesoValido = false;
        }
    }

    if (!pesoValido)
    {
        std::cout << "Peso inválido, Ingrese de nuevo" << std::endl;
    }

    return Peso;

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

