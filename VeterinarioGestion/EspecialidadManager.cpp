#include "EspecialidadManager.h"

void EspecialidadManager::CargarEspecialidad()
{
    Especialidades especialidad;
    GestorArchivo eArchivo("especialidades.dat");
    int IDespecialidad;
    std::string Nombre, Descripcion;

    std::cout << "Ingrese el ID de la especialidad: ";
    std::cin >> IDespecialidad;
    std::cout << "Ingrese el Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, Nombre);
    std::cout << "Ingrese la Descripcion: ";
    std::getline(std::cin, Descripcion);

    especialidad = Especialidades(IDespecialidad, Nombre, Descripcion);

    if (eArchivo.GuardarEspecialidad(especialidad))
        {
            std::cout << std::endl;
            std::cout << "Especialidad guardada correctamente." << std::endl;
        }
    else
        {
            std::cout << "Error al guardar la especialidad." << std::endl;
        }
}

void EspecialidadManager::MostrarEspecialidades()
{
    Especialidades especialidad;
    GestorArchivo eArchivo("especialidades.dat");
    int cantidadRegistros = eArchivo.CantidadRegistrosEspecialidades();
    bool crear;
    if (cantidadRegistros == 0)
        {
            std::cout << "No hay Especialidad registrada." << std::endl;
            std::cout << "Desea agregar una especialidad? 1- Si . 2- No: ";
            std::cin >> crear;
            if (crear == 1)
                {
                    CargarEspecialidad();
                }
            else
                {
                    std::cout << "No se cargó ninguna especialidad." << std::endl;
                }
        }

    for (int i = 0; i < cantidadRegistros; i++)
        {
            especialidad = eArchivo.LeerEspecialidad(i);
            std::cout << especialidad.toCSV() << std::endl;
        }
}

int	EspecialidadManager::BuscarEspecialidadPorID(int idBuscado)
{
    Especialidades especialidad;
    GestorArchivo eArchivo("especialidades.dat");
    int cantidadRegistros = eArchivo.CantidadRegistrosEspecialidades();
    for (int i = 0; i < cantidadRegistros; i++)
        {
            especialidad = eArchivo.LeerEspecialidad(i);
            if (especialidad.getIDEspecialidad() == idBuscado)
                {
                    ;
                    return i;
                }
        }
    std::cout << "No se encontró el ID de la especialidad." << std::endl;
    return -1;
}
