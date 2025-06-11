#include "VeterinariosManager.h"


void VeterinariosManager::CargarVeterinarios()
{
    Validaciones validar;
    Veterinarios veterinarios;
    Especialidades especialidad;
    EspecialidadManager eManager;


    GestorArchivo eArchivo("especialidades.dat");
    int idveterinario = 0,matricula, idespecialidad;
    std::string DNI, Nombre, Apellido;
    bool activo, confirmar = false, buscaDNI = false;

    std::cout << "Ingrese N° DNI: ";
    std::cin.ignore();
    DNI = validar.validarNUMenString();

    do
        {
            buscaDNI = BuscarVeterinarioPorDNI(DNI);
            if (buscaDNI)
                {
                    std::cout << std::endl  << "Ya existe un Veterinario con el DNI ingresado." << std::endl;
                    confirmar = true;
                }
            else
                {
                    idveterinario = SiguienteID();
                    std::cout << "Ingrese la Matricula del Veterinario: ";
                    matricula = validar.validarNumero();
                    std::cout << "Ingrese el ID especialidad: ";
                    idespecialidad = validar.validarNumero();
                    std::cout << "Ingrese el Nombre: ";
                    Nombre = validar.validarLetra();
                    std::cout << "Ingrese el Apellido: ";
                    Apellido = validar.validarLetra();
                    std::cout << "Ingrese 1 si esta Activo o 0 para inactivo): ";
                    activo = validar.validarBool();

                    int posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);

                    if (posEspecialidad == -1)
                        {
                            bool crear;
                            std::cout << "No se encontro la especialidad." << std::endl;
                            std::cout << "Desea agregar una especialidad? 1- Si . 0 - No: ";
                            crear = validar.validarBool();


                            if (crear == 1)
                                {
                                    eManager.CargarEspecialidad();
                                    posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);
                                    especialidad = eArchivo.LeerEspecialidad(posEspecialidad);
                                }
                            else
                                {
                                    std::cout << "No se cargo ninguna especialidad." << std::endl;
                                    especialidad = Especialidades(0, "Sin especialidad", "Sin Datos");
                                }
                        }
                    else
                        {
                            especialidad = eArchivo.LeerEspecialidad(posEspecialidad);
                        }
                    limpiarPantalla();
                    veterinarios = Veterinarios(idveterinario, matricula, DNI, Nombre, Apellido, especialidad, activo);

                    confirmar = ConfirmarIngreso(veterinarios, confirmar);

                }
        }
    while (!confirmar);
    Guardar(veterinarios);

}

void VeterinariosManager::MostrarVeterinarioInforme()
{
    Veterinarios veterinario;
    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
    if (cantidadregistros == 0)
        {
            std::cout << "No hay Veterinarios registrados." << std::endl;
        }
    std::cout << "VETERINARIO: " << std::endl;
    std::cout << "IDVeterinario | MatriculaVete | DNIVete | NombreVete | ApellidoVete | IDEspe. | NombreEspe. | Descripcion \t | Activo" << std::endl;

    for (int i = 0; i < cantidadregistros; i++)
        {
            veterinario = vArchivo.LeerVeterinario(i);

            std::cout << veterinario.toInforme() << std::endl;
        }
}

void VeterinariosManager::MostrarVeterinarioExportable()
{
    Veterinarios veterinario;
    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
    if (cantidadregistros == 0)
        {
            std::cout << "No hay Veterinarioss registrados." << std::endl;
        }
    std::cout << "VETERINARIO: " << std::endl;
    std::cout << "IDVeterinario,MatriculaVete,DNIVete,NombreVete,ApellidoVete,IDEspe.,NombreEspe.,Descripcion,Activo" << std::endl;

    for (int i = 0; i < cantidadregistros; i++)
        {
            veterinario = vArchivo.LeerVeterinario(i);

            std::cout << veterinario.toCSV() << std::endl;
        }
}

int VeterinariosManager::BuscarVeterinariosPorID(int idBuscado)
{
    Veterinarios veterinarios;
    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();
    for (int i = 0; i < cantidadRegistros; i++)
        {
            veterinarios = vArchivo.LeerVeterinario(i);
            if (veterinarios.getIDVeterinario() == idBuscado)
                {
                    return i;
                }
        }
    std::cout << "No se encontro el ID del Veterinarios." << std::endl;
    return -1;
}

bool VeterinariosManager::ConfirmarIngreso(Veterinarios veterinario, bool confirmar)
{
    Validaciones validar;
    std::cout << "Veterinario Ingresado: " << std::endl;
    std::cout << "ID Veterinario:" << "\t" + std::to_string(veterinario.getIDVeterinario()) << std::endl;
    std::cout << "Matricula: " << "\t" + std::to_string(veterinario.getMatricula()) << std::endl;
    std::cout << "DNI: " << "\t\t" + veterinario.getDNI() << std::endl;
    std::cout << "Nombre: " << "\t" + veterinario.getNombre() << std::endl;
    std::cout << "Apellido: " << "\t" + veterinario.getApellido() << std::endl;
    std::cout << "IDEspecialidad: " << std::to_string(veterinario.getEspecialidad().getIDEspecialidad()) << std::endl;
    std::cout << "Especialidad: " << "\t" + veterinario.getEspecialidad().getNombre() << std::endl;
    std::cout << "Descripcion: " << "\t" + veterinario.getEspecialidad().getDescripcion() << std::endl;
    std::cout << "Activo: " << "\t" + std::to_string(veterinario.getActivo()) << std::endl;


    std::cout << "Confirma los datos ingresados? 1-Si, 0-No: " << std::endl;
    confirmar = validar.validarBool();


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

bool VeterinariosManager::BuscarVeterinarioPorDNI(std::string dniBuscado)
{
    Veterinarios veterinarios;
    bool VeteEncontrado = false;
    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();

    for (int i = 0; i < cantidadRegistros; i++)
        {
            veterinarios = vArchivo.LeerVeterinario(i);
            if (veterinarios.getDNI() == dniBuscado)
                {
                    VeteEncontrado= true;
                    std::cout << "IDVeterinario | MatriculaVete | DNIVete | NombreVete | ApellidoVete | IDEspe. | NombreEspe. | Descripcion \t | Activo" << std::endl;

                    std::cout << veterinarios.toInforme() << std::endl;
                    return VeteEncontrado;
                }
        }
    if (!VeteEncontrado)
        {
            std::cout << "No se encontro el Veterinario con el DNI: " << dniBuscado << std::endl;
            return VeteEncontrado;
        }
}

void VeterinariosManager::Guardar(Veterinarios veterinarios)
{
    GestorArchivo vArchivo("veterinarios.dat");
    if (vArchivo.GuardarVeterinario(veterinarios))
        {
            std::cout << std::endl;
            std::cout << "Veterinario guardado correctamente." << std::endl;
        }
    else
        {
            std::cout << "Error al guardar el Veterinario." << std::endl;
        }
}

int VeterinariosManager::SiguienteID()
{
    Veterinarios ultimoveterinario;
    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();

    return cantidadRegistros + 1;
}

bool VeterinariosManager::BajaVeterinario()
{
    Validaciones validar;
    std::string dni;
    Veterinarios veterinarios;

    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();
    std::cout << "Ingrese el DNI del Veterinario que desea dar de baja: ";
    std::cin.ignore();
    dni = validar.validarNUMenString();

    for (int i = 0; i < cantidadRegistros; i++)
        {
            veterinarios = vArchivo.LeerVeterinario(i);
            if (veterinarios.getDNI() == dni && veterinarios.getActivo())
                {
                    veterinarios.setActivo(false);
                    if (vArchivo.ModificarVeterinarios(i, veterinarios))
                        {
                            std::cout << "Veterinario dado de baja exitosamente." << std::endl;
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


void VeterinariosManager::ListarVeterinariosActivos()
{
    Veterinarios veterinario;
    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadregistros = vArchivo.CantidadRegistrosVeterinario();
    if (cantidadregistros == 0)
        {
            std::cout << "No hay Veterinarioss registrados." << std::endl;
        }
    std::cout << "VETERINARIOS ACTIVOS: " << std::endl;
    std::cout << "IDVeterinario | MatriculaVete | DNIVete | NombreVete | ApellidoVete | IDEspe. | NombreEspe. | Descripcion \t | Activo" << std::endl;
    for (int i = 0; i < cantidadregistros; i++)
        {
            veterinario = vArchivo.LeerVeterinario(i);
            if (veterinario.getActivo() == true)
                {
                    std::cout << veterinario.toInforme() << std::endl;
                }
        }

}



void VeterinariosManager::ModificarVeterinarios()
{
    const static std::string OPCION_MATRICULA = "ID Matricula";
    const static std::string OPCION_IDESPECIALIDAD = "ID Especialidad";
    const static std::string OPCION_DNI = "DNI";
    const static std::string OPCION_NOMBRE = "Nombre";
    const static std::string OPCION_APELLIDO= "Apellido";
    const static std::string OPCION_ACTIVO = "Activo";
    const static std::string OPCION_SALIR = "Salir";


    const int OPC_MATRICULA = 1;
    const int OPC_IDESPECIALIDAD = 2;
    const int OPC_DNI = 3;
    const int OPC_NOMBRE = 4;
    const int OPC_APELLIDO = 5;
    const int OPC_ACTIVO = 6;
    const int OPC_ATRAS_SALIR = 0;


    Validaciones validar;
    Veterinarios veterinario;
    Especialidades especialidad;
    EspecialidadManager eManager;
    int matricula, idespecialidad,opcion,modifico=1;
    std::string nombre, apellido, modDNI;
    bool activo;


    GestorArchivo vArchivo("veterinarios.dat");
    int cantidadRegistros = vArchivo.CantidadRegistrosVeterinario();
    std::string dni;
    std::cout << "Ingrese el DNI del Veterinario a modificar: ";
    std::cin.ignore();
    dni = validar.validarNUMenString();
    for (int i = 0; i < cantidadRegistros; i++)
        {
        veterinario = vArchivo.LeerVeterinario(i);


        if (veterinario.getDNI() == dni)
        {
    do{
        std::cout << "Datos actuales:" << std::endl;
        std::cout << "IDVeterinario | MatriculaVete | DNIVete | NombreVete | ApellidoVete | IDEspe. | NombreEspe. | Descripcion \t | Activo" << std::endl;
        std::cout << veterinario.toInforme() ;
//-----------------------------------------------------------------------------------------------------------------------

        //opcion = validar.validarNumero();
        std::cout << std::endl <<"-----------------------------------------" << std::endl;
        std::cout << OPC_MATRICULA << ". " << OPCION_MATRICULA << std::endl;
        std::cout << OPC_IDESPECIALIDAD << ". " << OPCION_IDESPECIALIDAD << std::endl;
        std::cout << OPC_DNI << ". " << OPCION_DNI << std::endl;
        std::cout << OPC_NOMBRE << ". " << OPCION_NOMBRE << std::endl;
        std::cout << OPC_APELLIDO << ". " << OPCION_APELLIDO << std::endl;
        std::cout << OPC_ACTIVO << ". " << OPCION_ACTIVO << std::endl;
        std::cout << OPC_ATRAS_SALIR << ". " << OPCION_SALIR << std::endl;

        opcion = procesarEntradaMenu(OPC_ATRAS_SALIR, OPC_ACTIVO);
        std::cin.ignore();

        switch(opcion)
            {
            case OPC_MATRICULA:
                    std::cout << std::endl << "ID Veterinario actual: " << veterinario.getMatricula();
                    std::cout << std::endl << "Ingrese nueva Matricula: ";
                    matricula = validar.validarNumero();
                    veterinario.setMatricula(matricula);
                    modifico++;
                break;

            case OPC_IDESPECIALIDAD:
                    int posEspecialidad;
                    std::cout << std::endl << "ID Especialidad actual: " << veterinario.getEspecialidad().getIDEspecialidad();
                    std::cout << std::endl << "Ingrese nuevo ID Especialidad: ";
                    idespecialidad = validar.validarNumero();
                    posEspecialidad = eManager.BuscarEspecialidadPorID(idespecialidad);
                    if (posEspecialidad == -1)
                        {
                            std::cout << "No se encontro la especialidad." << std::endl;
                            especialidad = Especialidades(0, "Sin especialidad", "Sin datos");
                        }
                    else
                        {
                            especialidad = GestorArchivo("especialidades.dat").LeerEspecialidad(posEspecialidad);
                        }
                    veterinario.setEspecialidad(especialidad);
                    modifico++;
                break;
            case OPC_DNI:
                    std::cout << std::endl << "DNI del Veterinario actual: " << veterinario.getDNI();
                    std::cout << std::endl << "Ingrese nuevo DNI: ";
                    modDNI = validar.validarNUMenString();
                    veterinario.setDNI(modDNI);
                    modifico++;
            break;
            case OPC_NOMBRE:
                    std::cout << std::endl << "Nombre actual: " << veterinario.getNombre();
                    std::cout << std::endl << "Ingrese nuevo Nombre: ";
                    nombre = validar.validarLetra();
                    veterinario.setNombre(nombre);
                    modifico++;
                break;

            case OPC_APELLIDO:
                    std::cout << std::endl << "Apellido actual: " << veterinario.getApellido();
                    std::cout << std::endl << "Ingrese nuevo Apellido: ";
                    apellido = validar.validarLetra();
                    veterinario.setApellido(apellido);
                    modifico++;
                break;

            case OPC_ACTIVO:
                    std::cout << std::endl << "Status actual: " << veterinario.getActivo();
                    std::cout << std::endl << "Activo (1: Si / 0: No): ";
                    activo = validar.validarBool();
                    veterinario.setActivo(activo);
                    modifico++;
                break;

            case OPC_ATRAS_SALIR:
                    modifico--;
                    limpiarPantalla();
                break;
            }
        }while(opcion!=OPC_ATRAS_SALIR);


            if(modifico!=0)
            {
            if (vArchivo.ModificarVeterinarios(i, veterinario))
            {
                std::cout << "Veterinario se ha guardado correctamente." << std::endl;
            }
            else
            {
                std::cout << "Error al guardar el Veterinario." << std::endl;
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

    std::cout << "No se encontró el Veterinario con ese DNI." << std::endl;
}



int VeterinariosManager::procesarEntradaMenu(int opcionMinima, int opcionMaxima)
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
