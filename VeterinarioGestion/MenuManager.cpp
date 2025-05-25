#include <iostream>
#include <string>
#include "MenuManager.h"
#include "FuncionesGlobales.h"
#include "MascotaManager.h"
#include "ClienteManager.h"
#include "SucursalManager.h"
#include "EspecialidadManager.h"
#include "VeterinariosManager.h"
#include "TratamientosManager.h"
#include "ConsultasManager.h"
#include "PagosManager.h"
#include "VacunasManager.h"
#include "VacunacionesManager.h"

using namespace std;

//TITULOS COMUNES
const static string TITULO_MENU_PRINCIPAL = "Menu principal";
const static string TITULO_GESTION_CLIENTES = "Gestion de clientes";
const static string TITULO_GESTION_MASCOTAS = "Gestion de Mascotas";
const static string TITULO_GESTION_VETERINARIOS = "Gestion de Veterinarios";
const static string TITULO_GESTION_CONSULTAS_MEDICAS = "Gestion de consultas medicas";
const static string TITULO_GESTION_VACUNAS = "Gestion de vacunas";
const static string TITULO_GESTION_TRATAMIENTOS = "Gestion de tratamientos";
const static string TITULO_GESTION_SUCURSALES = "Gestion de sucursales";
const static string TITULO_GESTION_PAGOS = "Gestion de pagos";
const static string TITULO_ACERCA_DE = "Acerca del aplicativo";
const static string TITULO_SALIR = "Salir";

//TITULO OPCIONES COMUNES
const static string TITULO_OPCION_MENU_ANTERIOR = "Ir al menu anterior";

//OPCIONES COMUNES
const int OPCION_ATRAS_SALIR = 0;

//TEXTOS COMUNES
const static string SEPARADOR_TITULO_PRINCIPAL = " ======= ";

//MENSAJES COMUNES
const static string MENSAJE_SELECCIONE_OPCION = "Seleccione una opcion: ";
const static string MENSAJE_OPCION_INVALIDA = "Error: Opcion invalida, porfavor ingrese una opcion valida nuevamente.";

void MenuManager::procesarMenuPrincipal() {
    const int OPCION_GESTION_CLIENTES = 1;
    const int OPCION_GESTION_MASCOTAS = 2;
    const int OPCION_CONSULTAS_MEDICAS = 3;
    const int OPCION_VACUNAS = 4;
    const int OPCION_TRATAMIENTOS = 5;
    const int OPCION_GESTION_VETERINARIOS = 6;
    const int OPCION_GESTION_SUCURSALES = 7;
    const int OPCION_PAGOS = 8;
    const int OPCION_ACERCA_DE = 9;

    int opcion;

    do {
        limpiarPantalla();

        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_MENU_PRINCIPAL << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_GESTION_CLIENTES << ". " << TITULO_GESTION_CLIENTES << endl;
        cout << OPCION_GESTION_MASCOTAS << ". " << TITULO_GESTION_MASCOTAS << endl;
        cout << OPCION_CONSULTAS_MEDICAS << ". " << TITULO_GESTION_CONSULTAS_MEDICAS << endl;
        cout << OPCION_VACUNAS << ". " << TITULO_GESTION_VACUNAS << endl;
        cout << OPCION_TRATAMIENTOS << ". " << TITULO_GESTION_TRATAMIENTOS << endl;
        cout << OPCION_GESTION_VETERINARIOS << ". " << TITULO_GESTION_VETERINARIOS << endl;
        cout << OPCION_GESTION_SUCURSALES << ". " << TITULO_GESTION_SUCURSALES << endl;
        cout << OPCION_PAGOS << ". " << TITULO_GESTION_PAGOS << endl;
        cout << OPCION_ACERCA_DE << ". " << TITULO_ACERCA_DE << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_SALIR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;

        limpiarPantalla();

        switch (opcion) {
            case OPCION_GESTION_CLIENTES:
                procesarSubmenuClientes();
                break;
            case OPCION_GESTION_MASCOTAS:
                procesarSubmenuMascotas();
                break;
            case OPCION_CONSULTAS_MEDICAS:
                procesarSubmenuConsultasMedicas();
                break;
            case OPCION_VACUNAS:
                procesarSubmenuVacunas();
                break;
            case OPCION_TRATAMIENTOS:
                procesarSubmenuTratamientos();
                break;
            case OPCION_GESTION_VETERINARIOS:
                procesarSubmenuVeterinarios();
                break;
            case OPCION_GESTION_SUCURSALES:
                procesarSubmenuSucursales();
                break;
            case OPCION_PAGOS:
                procesarSubmenuPagos();
                break;
            case OPCION_ACERCA_DE:
                procesarSubmenuAcercaDe();
                break;
            case OPCION_ATRAS_SALIR:
                limpiarPantalla();
                cout << "Muchas gracias por usar nuestro sistema de gestion, hasta luego!" << endl;
                esperarCualquierTecla();
                break;
            default:
                evaluarOpcionDefault(opcion);
        }
    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::evaluarOpcionDefault(int opcionSeleccionada){
  if(opcionSeleccionada != OPCION_ATRAS_SALIR){
    mostrarMensajeOpcionInvalida();
  }
}

void MenuManager::realizarOperacionPostSeleccion(int opcionSeleccionada){
  if(opcionSeleccionada == OPCION_ATRAS_SALIR){
    limpiarPantalla();
  } else {
    cout << endl;
    esperarCualquierTecla();
    limpiarPantalla();
  }
}

void MenuManager::procesarSubmenuClientes(){
    const int OPCION_ALTA = 1;
    const int OPCION_MODIFICAR = 2;
    const int OPCION_BAJA= 3;
    const int OPCION_LISTAR = 4;
    const int OPCION_CONSULTA_DNI = 5;
    const int OPCION_CONSULTA_ID = 6;
    const int OPCION_CONSULTA_TELEFONO = 7;

    const string TITULO_ALTA = "Alta de cliente";
    const string TITULO_MODIFICAR = "Modificacion de cliente";
    const string TITULO_BAJA = "Baja de cliente";
    const string TITULO_LISTAR = "Listado de clientes (ordenado por ID)";
    const string TITULO_CONSULTA_DNI = "Consulta por DNI";
    const string TITULO_CONSULTA_ID = "Consulta por ID";
    const string TITULO_CONSULTA_TELEFONO = "Consulta por telefono";

    int opcion;

    ClienteManager clienteMan;

    do {
        limpiarPantalla();
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_CLIENTES << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_ALTA << ". " << TITULO_ALTA << endl;
        cout << OPCION_MODIFICAR << ". " << TITULO_MODIFICAR << endl;
        cout << OPCION_BAJA << ". " << TITULO_BAJA << endl;
        cout << OPCION_LISTAR << ". " << TITULO_LISTAR << endl;
        cout << OPCION_CONSULTA_DNI << ". " << TITULO_CONSULTA_DNI << endl;
        cout << OPCION_CONSULTA_ID << ". " << TITULO_CONSULTA_ID << endl;
        cout << OPCION_CONSULTA_TELEFONO << ". " << TITULO_CONSULTA_TELEFONO << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;
        limpiarPantalla();

        switch (opcion) {
            case OPCION_LISTAR:
                std::cout << "--------------------" << std::endl;
                std::cout << "CLIENTE: " << std::endl;
                std::cout << "ID\t| DNI\t\t|Nombre\t|Apellido\t|Telefono\t|Email" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------" << std::endl;
                clienteMan.MostrarClientes();
                break;
            case OPCION_ALTA:
                break;
            case OPCION_MODIFICAR:
                break;
            case OPCION_BAJA:
                break;
            default:
                evaluarOpcionDefault(opcion);
        }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuMascotas(){
    const int OPCION_ALTA = 1;
    const int OPCION_MODIFICAR = 2;
    const int OPCION_BAJA = 3;
    const int OPCION_LISTAR = 4;
    const int OPCION_CONSULTA_ID = 5;
    const int OPCION_CONSULTA_RAZA = 6;
    const int OPCION_CONSULTA_ESPECIE = 7;

    const string TITULO_ALTA = "Alta de mascota";
    const string TITULO_MODIFICAR = "Modificacion de mascota";
    const string TITULO_BAJA = "Baja de mascota";
    const string TITULO_LISTAR = "Listado de mascotas";
    const string TITULO_CONSULTA_ID = "Consulta por ID";
    const string TITULO_CONSULTA_RAZA = "Consulta por raza";
    const string TITULO_CONSULTA_ESPECIE = "Consulta por especie";

    int opcion;

    do {
        limpiarPantalla();
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_MASCOTAS << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_ALTA << ". " << TITULO_ALTA << endl;
        cout << OPCION_MODIFICAR << ". " << TITULO_MODIFICAR << endl;
        cout << OPCION_BAJA << ". " << TITULO_BAJA << endl;
        cout << OPCION_LISTAR << ". " << TITULO_LISTAR << endl;
        cout << OPCION_CONSULTA_ID << ". " << TITULO_CONSULTA_ID << endl;
        cout << OPCION_CONSULTA_RAZA << ". " << TITULO_CONSULTA_RAZA << endl;
        cout << OPCION_CONSULTA_ESPECIE << ". " << TITULO_CONSULTA_ESPECIE << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;
        limpiarPantalla();

        switch (opcion) {
            case OPCION_LISTAR:
                break;
            case OPCION_ALTA:
                break;
            case OPCION_MODIFICAR:
                break;
            case OPCION_BAJA:
                break;
            case OPCION_ATRAS_SALIR:
                break;
            default:
                evaluarOpcionDefault(opcion);
        }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuVeterinarios(){
    const int OPCION_ALTA = 1;
    const int OPCION_MODIFICAR = 2;
    const int OPCION_BAJA = 3;
    const int OPCION_LISTAR_ID = 4;
    const int OPCION_LISTAR_ACTIVOS = 5;

    const string TITULO_ALTA = "Alta de veterinario";
    const string TITULO_MODIFICAR = "Modificacion de veterinario";
    const string TITULO_BAJA = "Baja de veterinario";
    const string TITULO_LISTAR_ID = "Listado por ID";
    const string TITULO_LISTAR_ACTIVOS = "Listado de activos";

    int opcion;

    do {
        limpiarPantalla();
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_VETERINARIOS << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_ALTA << ". " << TITULO_ALTA << endl;
        cout << OPCION_MODIFICAR << ". " << TITULO_MODIFICAR << endl;
        cout << OPCION_BAJA << ". " << TITULO_BAJA << endl;
        cout << OPCION_LISTAR_ID << ". " << TITULO_LISTAR_ID << endl;
        cout << OPCION_LISTAR_ACTIVOS << ". " << TITULO_LISTAR_ACTIVOS << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;
        limpiarPantalla();

        switch (opcion) {
            case OPCION_ALTA:
                break;
            case OPCION_MODIFICAR:
                break;
            case OPCION_BAJA:
                break;
            case OPCION_LISTAR_ID:
                break;
            case OPCION_LISTAR_ACTIVOS:
                break;
            case OPCION_ATRAS_SALIR:
                break;
            default:
                evaluarOpcionDefault(opcion);
        }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuConsultasMedicas(){
    const int OPCION_ALTA = 1;
    const int OPCION_MODIFICAR = 2;
    const int OPCION_BAJA = 3;
    const int OPCION_CONSULTA_MASCOTA = 4;
    const int OPCION_CONSULTA_FECHA = 5;
    const int OPCION_CONSULTA_SUCURSAL = 6;
    const int OPCION_CONSULTA_VETERINARIO = 7;
    const int OPCION_CONSULTA_CLIENTE = 8;

    const string TITULO_ALTA = "Alta de atencion";
    const string TITULO_MODIFICAR = "Modificacion de atencion";
    const string TITULO_BAJA = "Baja de atencion";
    const string TITULO_CONSULTA_MASCOTA = "Consulta por ID Mascota";
    const string TITULO_CONSULTA_FECHA = "Consulta por rango de fecha";
    const string TITULO_CONSULTA_SUCURSAL = "Consulta por sucursal";
    const string TITULO_CONSULTA_VETERINARIO = "Consulta por ID Veterinario";
    const string TITULO_CONSULTA_CLIENTE = "Consulta por ID Cliente";

    int opcion;

    do {
        limpiarPantalla();
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_CONSULTAS_MEDICAS << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_ALTA << ". " << TITULO_ALTA << endl;
        cout << OPCION_MODIFICAR << ". " << TITULO_MODIFICAR << endl;
        cout << OPCION_BAJA << ". " << TITULO_BAJA << endl;
        cout << OPCION_CONSULTA_MASCOTA << ". " << TITULO_CONSULTA_MASCOTA << endl;
        cout << OPCION_CONSULTA_FECHA << ". " << TITULO_CONSULTA_FECHA << endl;
        cout << OPCION_CONSULTA_SUCURSAL << ". " << TITULO_CONSULTA_SUCURSAL << endl;
        cout << OPCION_CONSULTA_VETERINARIO << ". " << TITULO_CONSULTA_VETERINARIO << endl;
        cout << OPCION_CONSULTA_CLIENTE << ". " << TITULO_CONSULTA_CLIENTE << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;
        limpiarPantalla();

        switch (opcion) {
            case OPCION_ALTA:
                break;
            case OPCION_MODIFICAR:
                break;
            case OPCION_BAJA:
                break;
            case OPCION_ATRAS_SALIR:
                break;
            default:
                evaluarOpcionDefault(opcion);
        }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuVacunas(){
    const int OPCION_ALTA = 1;
    const int OPCION_MODIFICAR = 2;
    const int OPCION_BAJA = 3;
    const int OPCION_REGISTRAR = 4;
    const int OPCION_LISTAR = 5;

    const string TITULO_ALTA = "Alta de vacuna";
    const string TITULO_MODIFICAR = "Modificacion de vacuna";
    const string TITULO_BAJA = "Baja de vacuna";
    const string TITULO_REGISTRAR = "Registrar vacunacion";
    const string TITULO_LISTAR = "Listado de vacunas";

    int opcion;
    limpiarPantalla();

    do {
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_VACUNAS << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_ALTA << ". " << TITULO_ALTA << endl;
        cout << OPCION_MODIFICAR << ". " << TITULO_MODIFICAR << endl;
        cout << OPCION_BAJA << ". " << TITULO_BAJA << endl;
        cout << OPCION_REGISTRAR << ". " << TITULO_REGISTRAR << endl;
        cout << OPCION_LISTAR << ". " << TITULO_LISTAR << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;

        switch (opcion) {
            case OPCION_ALTA:
                break;
            case OPCION_MODIFICAR:
                break;
            case OPCION_BAJA:
                break;
            case OPCION_REGISTRAR:
                break;
            case OPCION_LISTAR:
                break;
            case OPCION_ATRAS_SALIR:
                break;
            default:
                evaluarOpcionDefault(opcion);
        }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuTratamientos(){
    const int OPCION_ALTA = 1;
    const int OPCION_MODIFICAR = 2;
    const int OPCION_BAJA = 3;
    const int OPCION_LISTAR = 4;

    const string TITULO_ALTA = "Alta de tratamiento";
    const string TITULO_MODIFICAR = "Modificacion de tratamiento";
    const string TITULO_BAJA = "Baja de tratamiento";
    const string TITULO_LISTAR = "Listado de tratamientos";

    int opcion;
    limpiarPantalla();

    do {
        limpiarPantalla();
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_TRATAMIENTOS << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_ALTA << ". " << TITULO_ALTA << endl;
        cout << OPCION_MODIFICAR << ". " << TITULO_MODIFICAR << endl;
        cout << OPCION_BAJA << ". " << TITULO_BAJA << endl;
        cout << OPCION_LISTAR << ". " << TITULO_LISTAR << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;

        switch (opcion) {
            case OPCION_ALTA:
                break;
            case OPCION_MODIFICAR:
                break;
            case OPCION_BAJA:
                break;
            case OPCION_LISTAR:
                break;
            case OPCION_ATRAS_SALIR:
                break;
            default:
                evaluarOpcionDefault(opcion);
            }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuPagos(){
    const int OPCION_RECAUDACION_ANUAL = 1;
    const int OPCION_RECAUDACION_POR_CLIENTE = 2;
    const int OPCION_RECAUDACION_POR_SUCURSAL = 3;

    const string TITULO_RECAUDACION_ANUAL = "Informe de recaudacion anual";
    const string TITULO_RECAUDACION_POR_CLIENTE = "Informe de recaudacion por cliente";
    const string TITULO_RECAUDACION_POR_SUCURSAL = "Informe de recaudacion por sucursal";

    int opcion;
    limpiarPantalla();

    do {
        limpiarPantalla();
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_PAGOS << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_RECAUDACION_ANUAL << ". " << TITULO_RECAUDACION_ANUAL << endl;
        cout << OPCION_RECAUDACION_POR_CLIENTE << ". " << TITULO_RECAUDACION_POR_CLIENTE << endl;
        cout << OPCION_RECAUDACION_POR_SUCURSAL << ". " << TITULO_RECAUDACION_POR_SUCURSAL << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;

        switch (opcion) {
            case OPCION_RECAUDACION_ANUAL:
                break;
            case OPCION_RECAUDACION_POR_CLIENTE:
                break;
            case OPCION_RECAUDACION_POR_SUCURSAL:
                break;
            case OPCION_ATRAS_SALIR:
                break;
            default:
                evaluarOpcionDefault(opcion);
        }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuSucursales(){
    const int OPCION_ALTA = 1;
    const int OPCION_MODIFICAR = 2;
    const int OPCION_BAJA = 3;
    const int OPCION_LISTAR = 4;

    const string TITULO_ALTA = "Alta de sucursal";
    const string TITULO_MODIFICAR = "Modificacion de sucursal";
    const string TITULO_BAJA = "Baja de sucursal";
    const string TITULO_LISTAR = "Listado de sucursales";

    int opcion;
    limpiarPantalla();

    do {
        limpiarPantalla();
        cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_GESTION_SUCURSALES << SEPARADOR_TITULO_PRINCIPAL << endl;
        cout << OPCION_ALTA << ". " << TITULO_ALTA << endl;
        cout << OPCION_MODIFICAR << ". " << TITULO_MODIFICAR << endl;
        cout << OPCION_BAJA << ". " << TITULO_BAJA << endl;
        cout << OPCION_LISTAR << ". " << TITULO_LISTAR << endl;
        cout << OPCION_ATRAS_SALIR << ". " << TITULO_OPCION_MENU_ANTERIOR << endl;
        cout << endl << MENSAJE_SELECCIONE_OPCION;

        cin >> opcion;

        switch (opcion) {
            case OPCION_ALTA:
                break;
            case OPCION_MODIFICAR:
                break;
            case OPCION_BAJA:
                break;
            case OPCION_LISTAR:
                break;
            case OPCION_ATRAS_SALIR:
                break;
            default:
                evaluarOpcionDefault(opcion);
        }

        realizarOperacionPostSeleccion(opcion);

    } while (opcion != OPCION_ATRAS_SALIR);
}

void MenuManager::procesarSubmenuAcercaDe(){
    cout << SEPARADOR_TITULO_PRINCIPAL << TITULO_ACERCA_DE << SEPARADOR_TITULO_PRINCIPAL << endl;
    cout << "Trabajo Practico Integrador - Programacion 2 - UTN FRGP" << endl;
    cout << "Sistema de Gestion Integral para Veterinaria (SIGVE)" << endl;
    cout << endl;
    cout << "Desarrollado por el Grupo #22 - Comision 101-102" << endl;
    cout << "- Emilio Jose Vera Parra" << endl;
    cout << "- Joaquin Ardaiz" << endl;
    cout << "- Matias Leandro Zarate" << endl;
    cout << endl;
    cout << "Integrantes de la catedra:" << endl;
    cout << "- Kloster, Daniel - Profesor" << endl;
    cout << "- Wenner, Maximiliano - Ayudante" << endl;
    cout << "- Lara Campos, Brian - Ayudante" << endl;
    cout << "- Carbonari, Verónica - Ayudante" << endl;
    cout << endl;
    esperarCualquierTecla();
}

void MenuManager::mostrarMensajeOpcionInvalida(){
    cout << MENSAJE_OPCION_INVALIDA << endl << endl;
    esperarCualquierTecla();
    limpiarPantalla();
}


