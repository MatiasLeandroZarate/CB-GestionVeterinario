#include "TratamientosManager.h"

void TratamientosManager::CargarTratamiento()
{
    Tratamientos tratamiento;
    GestorArchivo tArchivo("tratamientos.dat");
    int IDTratamiento, DuracionDias;
    std::string NombreTratamiento, Descripcion;
    float Costo;

    std::cout << "Ingrese el ID del Tratamiento: ";
    std::cin >> IDTratamiento;
    std::cout << "Ingrese el Nombre del Tratamiento: ";
    std::cin.ignore();
    std::getline(std::cin, NombreTratamiento);
    std::cout << "Ingrese la Descripcion: ";
    std::getline(std::cin, Descripcion);
    std::cout << "Ingrese la Duracion en Dias: ";
    std::cin >> DuracionDias;
    std::cout << "Ingrese el Monto: ";
    std::cin >> Costo;

    tratamiento = Tratamientos(IDTratamiento, NombreTratamiento, Descripcion, DuracionDias, Costo);
    if (tArchivo.GuardarTratamientos(tratamiento))
        {
            std::cout << "Tratamiento guardado correctamente." << std::endl;
        }
    else
        {
            std::cout << "Error al guardar el tratamiento." << std::endl;
        }
}

void TratamientosManager::MostrarTratamiento()
{
    Tratamientos tratamiento;
    GestorArchivo tArchivo("tratamientos.dat");
    int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();
    bool crear;
    if (cantidadRegistros == 0)
        {
            std::cout << "No hay Tratamiento registrado." << std::endl;
            std::cout << "Desea agregar un tratamiento? 1- Si . 2- No: ";
            std::cin >> crear;
            if (crear == 1)
                {
                    CargarTratamiento();
                }
            else
                {
                    std::cout << "No se cargó ningun tratamiento." << std::endl;
                }
        }
    for (int i = 0; i < cantidadRegistros; i++)
        {
            tratamiento = tArchivo.LeerTratamientos(i);
            std::cout << tratamiento.toCSV() << std::endl;
        }

}

int TratamientosManager::BuscarTratamientoPorID(int idBuscado)
{
    Tratamientos tratamiento;
    GestorArchivo tArchivo("tratamientos.dat");
    int cantidadRegistros = tArchivo.CantidadRegistrosTratamientos();
    for (int i = 0; i < cantidadRegistros; i++)
        {
            tratamiento = tArchivo.LeerTratamientos(i);
            if (tratamiento.getIDTratamiento() == idBuscado)
                {
                    return i;
                }
        }
    return -1;
}
