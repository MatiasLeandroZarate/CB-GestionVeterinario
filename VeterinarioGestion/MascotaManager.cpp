#include "MascotaManager.h"
#include "Cliente.h"
#include <optional>

void MascotaManager::CargarMascota()
{
    Validaciones validar;
    Mascotas mascota;
    GestorArchivo gArchivo("mascotas.dat");
    int IDMascota, Edad, IDCliente;
    std::string Nombre, Especie, Raza, Sexo;
    float Peso;
    bool Activo;
    Fecha FechaNacimiento, fechavalidar;

    IDMascota = GenerarIdAutomatico();
    std::cin.ignore();
    std::cout << "Ingrese Nombre: ";
    Nombre = validar.validarLetra();
    std::cout << "Ingrese Especie: ";
    Especie = validar.validarLetra();
    std::cout << "Ingrese Raza: ";
    Raza = validar.validarLetra();
    std::cout << "Ingrese Edad: ";
    Edad = validar.validarNumero();
    std::cout << "Ingrese Peso: ";
    Peso = validar.validarFloat();

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

    LocateTitulo();
    std::cout << std::endl;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        mascotas = gArchivo.LeerMascota(i);

        rlutil::locate(3, i + 3);
        std::cout << mascotas.getIDMascota();
        rlutil::locate(14, i + 3);
        std::cout << mascotas.getNombre();
        rlutil::locate(25, i + 3);
        std::cout << mascotas.getEspecie();
        rlutil::locate(40, i + 3);
        std::cout << mascotas.getRaza();
        rlutil::locate(56, i + 3);
        std::cout << mascotas.getEdad();
        rlutil::locate(63, i + 3);
        std::cout << mascotas.getPeso();
        rlutil::locate(72, i + 3);
        std::cout << mascotas.getSexo();
        rlutil::locate(83, i + 3);
        std::cout << mascotas.getFechaNacimiento().toString();
        rlutil::locate(103, i + 3);
        std::cout << mascotas.getIDCliente();
        rlutil::locate(115, i + 3);
        std::cout << mascotas.getActivo();

    }

}
void MascotaManager::MostrarMascotaPorRaza()
{
    Mascotas mascotas;
    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();
    std::string RazaBuscada;
    int ContEncontrados = 0;
    int j=0;

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

        LocateTitulo();
        for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas = gArchivo.LeerMascota(i);
            if (mascotas.getRaza() == RazaBuscada)
            {
                rlutil::locate(3, j + 3);
                std::cout << mascotas.getIDMascota();
                rlutil::locate(14, j + 3);
                std::cout << mascotas.getNombre();
                rlutil::locate(25, j + 3);
                std::cout << mascotas.getEspecie();
                rlutil::locate(40, j + 3);
                std::cout << mascotas.getRaza();
                rlutil::locate(56, j + 3);
                std::cout << mascotas.getEdad();
                rlutil::locate(63, j + 3);
                std::cout << mascotas.getPeso();
                rlutil::locate(72, j + 3);
                std::cout << mascotas.getSexo();
                rlutil::locate(83, j + 3);
                std::cout << mascotas.getFechaNacimiento().toString();
                rlutil::locate(103, j + 3);
                std::cout << mascotas.getIDCliente();
                rlutil::locate(115, j + 3);
                std::cout << mascotas.getActivo();
                j++;

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
    int j=0;

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

        LocateTitulo();
        for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas = gArchivo.LeerMascota(i);
            if (mascotas.getEspecie() == EspecieBuscada)
            {
                rlutil::locate(3, j + 3);
                std::cout << mascotas.getIDMascota();
                rlutil::locate(14, j + 3);
                std::cout << mascotas.getNombre();
                rlutil::locate(25, j + 3);
                std::cout << mascotas.getEspecie();
                rlutil::locate(40, j + 3);
                std::cout << mascotas.getRaza();
                rlutil::locate(56, j + 3);
                std::cout << mascotas.getEdad();
                rlutil::locate(63, j + 3);
                std::cout << mascotas.getPeso();
                rlutil::locate(72, j + 3);
                std::cout << mascotas.getSexo();
                rlutil::locate(83, j + 3);
                std::cout << mascotas.getFechaNacimiento().toString();
                rlutil::locate(103, j + 3);
                std::cout << mascotas.getIDCliente();
                rlutil::locate(115, j + 3);
                std::cout << mascotas.getActivo();
                j++;

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
    int j = 0;

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

        LocateTitulo();
        for (int i = 0; i < cantidadRegistros; i++)
        {
            mascotas = gArchivo.LeerMascota(i);
            if (mascotas.getIDMascota() == idBuscado)
            {
                rlutil::locate(3, j + 3);
                std::cout << mascotas.getIDMascota();
                rlutil::locate(14, j + 3);
                std::cout << mascotas.getNombre();
                rlutil::locate(25, j + 3);
                std::cout << mascotas.getEspecie();
                rlutil::locate(40, j + 3);
                std::cout << mascotas.getRaza();
                rlutil::locate(56, j + 3);
                std::cout << mascotas.getEdad();
                rlutil::locate(63, j + 3);
                std::cout << mascotas.getPeso();
                rlutil::locate(72, j + 3);
                std::cout << mascotas.getSexo();
                rlutil::locate(83, j + 3);
                std::cout << mascotas.getFechaNacimiento().toString();
                rlutil::locate(103, j + 3);
                std::cout << mascotas.getIDCliente();
                rlutil::locate(115, j + 3);
                std::cout << mascotas.getActivo();
                j++;
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

std::optional<Mascotas> MascotaManager::obtenerMascotaPorId(int idBuscado) {
    Mascotas mascota;
    GestorArchivo archivoMascotas("mascotas.dat");

    int cantidadRegistros = archivoMascotas.CantidadRegistrosMascotas();

    for (int i = 0; i < cantidadRegistros; i++) {
        mascota = archivoMascotas.LeerMascota(i);
        if (mascota.getIDMascota() == idBuscado) {
            return mascota;
        }
    }

    return std::nullopt;
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



int MascotaManager::GenerarIdAutomatico()
{

    GestorArchivo gArchivo("mascotas.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosMascotas();

    return cantidadRegistros + 1;
}

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
       const static std::string OPCION_NOMBRE = "Nombre";
    const static std::string OPCION_ESPECIE = "Especie";
    const static std::string OPCION_RAZA = "Raza";
    const static std::string OPCION_EDAD = "Edad";
    const static std::string OPCION_PESO= "Peso";
    const static std::string OPCION_SEXO= "Sexo";
    const static std::string OPCION_FECHA_NACIMIENTO= "Fecha de Nacimiento";
    const static std::string OPCION_IDCLIENTE= "ID del Cliente";
    const static std::string OPCION_ACTIVO = "Activo";
    const static std::string OPCION_SALIR = "Salir";


    const int OPC_NOMBRE = 1;
    const int OPC_ESPECIE = 2;
    const int OPC_RAZA = 3;
    const int OPC_EDAD = 4;
    const int OPC_PESO = 5;
    const int OPC_SEXO = 6;
    const int OPC_FECHA_NACIMIENTO = 7;
    const int OPC_IDCLIENTE = 8;
    const int OPC_ACTIVO = 9;
    const int OPC_ATRAS_SALIR = 0;

    Validaciones validar;
    Mascotas mascota;
    int ID;
    int IDMascota, Edad, IDCliente, opcion, modifico = 1;
    std::string Nombre, Especie, Raza, Sexo;
    float Peso;
    bool Activo;
    Fecha FechaNacimiento, fechavalidar;

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
            int contador = 0;

            do
            {
                limpiarPantalla();
                std::cout << "Datos actuales:" << std::endl;
                LocateTitulo();

                rlutil::locate(3, i + 3);
                std::cout << mascota.getIDMascota();
                rlutil::locate(14, i + 3);
                std::cout << mascota.getNombre();
                rlutil::locate(25, i + 3);
                std::cout << mascota.getEspecie();
                rlutil::locate(40, i + 3);
                std::cout << mascota.getRaza();
                rlutil::locate(56, i + 3);
                std::cout << mascota.getEdad();
                rlutil::locate(63, i + 3);
                std::cout << mascota.getPeso();
                rlutil::locate(72, i + 3);
                std::cout << mascota.getSexo();
                rlutil::locate(83, i + 3);
                std::cout << mascota.getFechaNacimiento().toString();
                rlutil::locate(103, i + 3);
                std::cout << mascota.getIDCliente();
                rlutil::locate(115, i + 3);
                std::cout << mascota.getActivo();

                std::cout << std::endl <<"-----------------------------------------" << std::endl;
                std::cout << OPC_NOMBRE << ". " << OPCION_NOMBRE << std::endl;
                std::cout << OPC_ESPECIE << ". " << OPCION_ESPECIE << std::endl;
                std::cout << OPC_RAZA << ". " << OPCION_RAZA << std::endl;
                std::cout << OPC_EDAD << ". " << OPCION_EDAD << std::endl;
                std::cout << OPC_PESO << ". " << OPCION_PESO << std::endl;
                std::cout << OPC_SEXO << ". " << OPCION_SEXO << std::endl;
                std::cout << OPC_FECHA_NACIMIENTO << ". " << OPCION_FECHA_NACIMIENTO << std::endl;
                std::cout << OPC_IDCLIENTE << ". " << OPCION_IDCLIENTE << std::endl;
                std::cout << OPC_ACTIVO << ". " << OPCION_ACTIVO << std::endl;
                std::cout << OPC_ATRAS_SALIR << ". " << OPCION_SALIR << std::endl;

                opcion = procesarEntradaMenu(OPC_ATRAS_SALIR, OPC_ACTIVO);
                std::cin.ignore();

                switch(opcion)
                {
                case OPC_NOMBRE:
                    std::cout << std::endl << "Nombre Actual de la Mascota: " << mascota.getNombre();
                    std::cout << std::endl << "Ingrese nuevo Nombre: ";
                    Nombre = validar.validarLetra();
                    mascota.setNombre(Nombre);
                    modifico++;
                    break;

                case OPC_ESPECIE:
                    std::cout << std::endl << "Especie Actual de la Mascota: " << mascota.getEspecie();
                    std::cout << std::endl << "Ingrese nueva Especie: ";
                    Especie = validar.validarLetra();
                    mascota.setEspecie(Especie);
                    modifico++;
                    break;
                case OPC_RAZA:
                    std::cout << std::endl << "Raza Actual de la Mascota: " << mascota.getRaza();
                    std::cout << std::endl << "Ingrese nueva Raza: ";
                    Raza = validar.validarLetra();
                    mascota.setRaza(Raza);
                    modifico++;
                    break;
                case OPC_EDAD:
                    std::cout << std::endl << "Edad Actual de la Mascota: " << mascota.getEdad();
                    std::cout << std::endl << "Ingrese nueva Edad: ";
                    Edad = validar.validarNumero();
                    mascota.setEdad(Edad);
                    modifico++;
                    break;

                case OPC_PESO:
                    std::cout << std::endl << "Peso Actual de la Mascota: " << mascota.getPeso();
                    std::cout << std::endl << "Ingrese nuevo Peso: ";
                    Peso = validar.validarFloat();
                    mascota.setPeso(Peso);
                    modifico++;
                    break;
                case OPC_SEXO:
                    std::cout << std::endl << "Sexo Actual de la Mascota: " << mascota.getSexo();
                    Sexo = validarSexo();
                    mascota.setSexo(Sexo);
                    modifico++;
                    break;
                case OPC_FECHA_NACIMIENTO:
                    mascota.getFechaNacimiento();
                    FechaNacimiento = fechavalidar.ValidacionFecha(FechaNacimiento);
                    mascota.setFechaNacimiento(FechaNacimiento);
                    modifico++;
                    break;
                case OPC_IDCLIENTE:
                    std::cout << std::endl << "ID Cliente Ligado a Mascota: " << mascota.getIDCliente() << std::endl;
                    IDCliente = ValidarIdCliente();
                    mascota.setIDCliente(IDCliente);
                    modifico++;
                    break;

                case OPC_ACTIVO:
                    std::cout << std::endl << "Status actual: " << mascota.getActivo();
                    std::cout << std::endl << "Activo (1: Si / 0: No): ";
                    Activo = validar.validarBool();
                    mascota.setActivo(Activo);
                    modifico++;
                    break;

                case OPC_ATRAS_SALIR:
                    modifico--;
                    limpiarPantalla();
                    break;
                }
            }
            while(opcion!=OPC_ATRAS_SALIR);


            if(modifico!=0)
            {
                if (vArchivo.ModificarMascota(i, mascota))
                {
                    std::cout << "Mascota se ha guardado correctamente." << std::endl;
                }
                else
                {
                    std::cout << "Error al guardar Mascota." << std::endl;
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

    std::cout << "No se encontró Mascota con ese ID." << std::endl;

}

int MascotaManager::procesarEntradaMenu(int opcionMinima, int opcionMaxima)
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

void MascotaManager::LocateTitulo()
{

    rlutil::locate(1, 2);
    std::cout << "IDMascota ";
    rlutil::locate(12, 2);
    std::cout << "| Nombre";
    rlutil::locate(23, 2);
    std::cout << "| Especie";
    rlutil::locate(38, 2);
    std::cout << "| Raza";
    rlutil::locate(53, 2);
    std::cout << "| Edad";
    rlutil::locate(60, 2);
    std::cout << "| Peso";
    rlutil::locate(70, 2);
    std::cout << "| Sexo";
    rlutil::locate(78, 2);
    std::cout << "| FechaNacimiento";
    rlutil::locate(100, 2);
    std::cout << "| IDCliente";
    rlutil::locate(112, 2);
    std::cout << "| Activo";

}
