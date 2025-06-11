#include "MascotaManager.h"
#include "Cliente.h"


void MascotaManager::CargarMascota()
{
    Mascotas mascota;
    GestorArchivo gArchivo("mascotas.dat");
    int IDMascota, Edad, IDCliente;
    std::string Nombre, Especie, Raza, Sexo;
    float Peso;
    bool Activo;
    Fecha FechaNacimiento, fechavalidar;

    IDMascota = GenerarIdAutomatico();
    std::cin.ignore();
    Nombre = validarNombre();

    Especie = validarEspecie();

    Raza = validarRaza();

    Edad = validarEdad();

    Peso = validarPeso();

    Sexo = validarSexo();

    IDCliente = ValidarIdCliente();

    Activo = true;

    std::cout << "Ingrese la Fecha de Nacimiento: " << std::endl;

    FechaNacimiento = fechavalidar.ValidacionFecha(FechaNacimiento);



    mascota = Mascotas(IDMascota, Nombre, Especie, Raza, Edad, Peso, Sexo, FechaNacimiento, IDCliente, Activo);

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
        std::cout << "No hay Macotas registradas." << std::endl;
    }
    std::cout << std::endl <<"--------------------" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "MASCOTA: " << std::endl;
    std::cout << "IDMascota|Nombre\t|Especie\t|Raza\t|EdadAños\t|Peso\t|Sexo\t|FechaNacimiento\t|IDCliente\t|Activo" << std::endl;
    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascotas = gArchivo.LeerMascota(i);
        std:: cout << mascotas.toInforme() << std::endl;
        //std::cout << mascotas.toCSV() << std::endl;
    }


}
void MascotaManager::MostrarMascotaPorRaza()
{
    Mascotas mascotas;
    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();
    std::string RazaBuscada;
    int ContEncontrados = 0;

    std::cout << "Ingrese Raza de la Mascota: ";
    std::cin >> RazaBuscada;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascotas = gArchivo.LeerMascota(i);
        if (mascotas.getRaza() == RazaBuscada)
        {

            ContEncontrados++;
        }

    }
    if(!ContEncontrados == 0)
    {
        std::cout << "IDMascota\t|Nombre\t|Especie\t|Raza\t|EdadAños\t|Peso\t|Sexo\t|FechaNacimiento\t|IDCliente\t|Activo" << std::endl;
        for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas = gArchivo.LeerMascota(i);
            if (mascotas.getRaza() == RazaBuscada)
            {
                std:: cout << mascotas.toInforme() << std::endl;

            }

        }

    }
    else
    {
        std::cout << "No se encontro ninguna Mascota." << std::endl;
    }

}
void MascotaManager::MostrarMascotaPorEspecie()
{

    Mascotas mascotas;
    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();
    std::string EspecieBuscada;
    int ContEncontrados = 0;

    std::cout << "Ingrese Especie de la Mascota: ";
    std::cin >> EspecieBuscada;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascotas = gArchivo.LeerMascota(i);
        if (mascotas.getEspecie() == EspecieBuscada)
        {

            ContEncontrados++;
        }

    }
    if(!ContEncontrados == 0)
    {
        std::cout << "IDMascota\t|Nombre\t|Especie\t|Raza\t|EdadAños\t|Peso\t|Sexo\t|FechaNacimiento\t|IDCliente\t|Activo" << std::endl;
        for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas = gArchivo.LeerMascota(i);
            if (mascotas.getEspecie() == EspecieBuscada)
            {
                std:: cout << mascotas.toInforme() << std::endl;

            }

        }

    }
    else
    {
        std::cout << "No se encontro ninguna Mascota." << std::endl;
    }

}
void MascotaManager::MostrarMascotaPorID()
{

    Mascotas mascotas;
    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();
    int idBuscado;
    int ContEncontrados = 0;

    std::cout << "Ingrese el ID de la Mascota: ";
    std::cin >> idBuscado;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascotas = gArchivo.LeerMascota(i);
        if (mascotas.getIDMascota() == idBuscado)
        {
            ContEncontrados++;
        }

    }


    if(!ContEncontrados == 0)
    {
        std::cout << "IDMascota\t|Nombre\t|Especie\t|Raza\t|EdadAños\t|Peso\t|Sexo\t|FechaNacimiento\t|IDCliente\t|Activo" << std::endl;
        for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas = gArchivo.LeerMascota(i);
            if (mascotas.getIDMascota() == idBuscado)
            {
                std:: cout << mascotas.toInforme() << std::endl;
            }

        }

    }
    else
    {
        std::cout << "No se encontro ninguna Mascota." << std::endl;
    }

}

int MascotaManager::BuscarMascotaPorID(int idBuscado)
{
    Mascotas mascotas;
    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();
    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascotas = gArchivo.LeerMascota(i);
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
int MascotaManager::ValidarIdCliente()
{

    std::string IDIngresado;
    bool IDValido = false;

    int ID;

    while (!IDValido)
    {

        std::cout << "Ingrese ID del Cliente: ";
        std::getline(std::cin, IDIngresado);
        IDValido = true;
        int i = 0;


        while (IDIngresado[i] != '\0')  // Validacion de que todos los caracteres sean numeros y no letras o caracteres
        {
            if (IDIngresado[i] < '0' || IDIngresado[i] > '9')
            {
                IDValido = false;
            }
            i++;
        }
        if (IDValido)
        {
            ID = 0;
            i = 0;
            while (IDIngresado[i] != '\0')
            {
                ID = ID * 10 + (IDIngresado[i] - '0');
                i++;
            }
        }

        IDValido = false;

        Cliente cliente;
        GestorArchivo gArchivo("clientes.dat");
        int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
        for (i = 0; i < cantidadRegistros; i++)
        {
            cliente = gArchivo.LeerClientes(i);
            if (cliente.getIDCliente() == ID)
            {
                IDValido = true;
            }
        }
        if (!IDValido)
        {
            std::cout << "ID invalido, Ingrese de nuevo." << std::endl;

        }

    }


    return ID;

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
std::string  MascotaManager::validarSexo()
{
    std::string Sexo;
    bool SexoValido = false;

    while(!SexoValido)
    {
        int i = 0;
        SexoValido = true;

        std::cout << "Ingrese el Sexo (1.- Hembra 0.- Macho): ";
        std::getline(std::cin, Sexo);

        while (Sexo[i] != '\0')  // Validacion de que todos los caracteres sean numeros y no letras o caracteres
        {
            if (Sexo[i] < '0' || Sexo[i] > '1')
            {
                SexoValido = false;
            }
            i++;
        }
        if (!SexoValido)
        {
            std::cout << "Sexo inválida, Ingrese de nuevo." << std::endl;

        }

    }
    if(Sexo[0] == 1)
    {
        Sexo = "Hembra";
    }
    else
    {
        Sexo = "Macho";
    }
    return Sexo;

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

float MascotaManager::validarPeso()
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



int MascotaManager::GenerarIdAutomatico()
{

    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();

    return cantidadRegistros + 1; // CONSULTAR SI ES POSIBLE BORRAR UN REGISTRO ENTERO EN UN ARCHIVO.

bool MascotaManager::DarDeBajaMascota()
{
    Validaciones validar;
    Mascotas mascotas;
    int ID;


    GestorArchivo vArchivo("mascotas.dat");
    int cantidadRegistros = vArchivo.CantidadRegistrosMascotas();
    std::cout << "Ingrese el ID de la Mascota que desea dar de baja: ";

    ID = validar.validarNumero();

    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascotas = vArchivo.LeerMascota(i);
        if (mascotas.getIDMascota() == ID && mascotas.getActivo())
        {
            mascotas.setActivo(false);
            if (vArchivo.ModificarMascota(i, mascotas))
            {
                std::cout << "Mascota dada de baja exitosamente." << std::endl;
                return true;
            }
            else
            {
                std::cout << "Mascota no encontrada o ya dada de baja." << std::endl;
                return false;
            }
        }
    }
}

void MascotaManager::ModificarMascota()
{
    Validaciones validar;
    int ID;
    Mascotas mascota;

    GestorArchivo vArchivo("mascotas.dat");
    int cantidadRegistros = vArchivo.CantidadRegistrosMascotas();

    std::cout << "Ingrese el ID de la Mascota a modificar: ";
    std::cin.ignore();
    ID = validar.validarNumero();

    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascota = vArchivo.LeerMascota(i);
        if (mascota.getIDMascota() == ID)
        {
            std::cout << "Datos actuales:" << std::endl;
            std::cout << mascota.toInforme() << std::endl;

            int IDMascota, Edad, IDCliente;
            std::string Nombre, Especie, Raza, Sexo;
            float Peso;
            bool Activo;
            Fecha FechaNacimiento, fechavalidar;

            Nombre = validarNombre();
            Especie = validarEspecie();
            Raza = validarRaza();
            Edad = validarEdad();
            Peso = validarPeso();
            Sexo = validarSexo();
            FechaNacimiento = fechavalidar.ValidacionFecha(FechaNacimiento);


            std::cout << "Activo (1: Si / 0: No): ";
            Activo = validar.validarBool();

            mascota.setNombre(Nombre);
            mascota.setEspecie(Especie);
            mascota.setRaza(Raza);
            mascota.setEdad(Edad);
            mascota.setPeso(Peso);
            mascota.setSexo(Sexo);
            mascota.setActivo(Activo);

            if (vArchivo.ModificarMascota(i, mascota))
            {
                std::cout << "Mascota modificada correctamente." << std::endl;
            }
            else
            {
                std::cout << "Error al modificar Mascota." << std::endl;
            }
            return;
        }
    }

    std::cout << "No se encontro Mascota con ese ID." << std::endl;
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

