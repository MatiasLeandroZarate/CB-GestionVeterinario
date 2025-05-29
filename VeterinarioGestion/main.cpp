#include <iostream>
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
#include "MenuManager.h"

using namespace std;

int main()
{
   MenuManager menuManager;
    menuManager.procesarMenuPrincipal();


 //   MascotaManager mascotaMan;

 //   SucursalManager sucursalMan;
//    EspecialidadManager especialidadMan;

 //   TratamientosManager tratamientoMan;
 //   ConsultasManager consultaMan;
 //   PagosManager pagosMan;
 //   VacunasManager vacunasMan;
 //   VacunacionesManager vacunacionesMan;


    //for(int i=0;i<3;i++) clienteMan.CargarCliente();
    //mascotaMan.CargarMascota();
    //sucursalMan.CargarSucursal();
    //especialidadMan.CargarEspecialidad();
    //veterinarioMan.CargarVeterinarios();
    //tratamientoMan.CargarTratamiento();
    //consultaMan.CargarConsulta();
    //pagosMan.CargarPagos();
    //vacunasMan.CargarVacunas();
    //vacunacionesMan.CargarVacunaciones();

    //std::cout << std::endl <<"--------------------" << std::endl;
    //std::cout << "--------------------" << std::endl;
    //std::cout << "MASCOTA: " << std::endl;
    //std::cout << "IDMascota,Nombre,Especie,Raza,EdadAños,Peso,Sexo,FechaNacimiento,IDCliente" << std::endl;
    //mascotaMan.MostrarMascota();
    //
    //std::cout << std::endl <<"--------------------" << std::endl;
    //std::cout << "--------------------" << std::endl;
    //std::cout << "SUCURSAL: " << std::endl;
    //std::cout << "IDSucursal,NombreSuc,Direccion";
    //sucursalMan.MostrarSucursal();
    //
    //std::cout << std::endl <<"--------------------" << std::endl;
    //std::cout << "--------------------" << std::endl;
    //std::cout << "ESPECIALIDADES: " << std::endl;
    //std::cout << "IDEspecialidad,NombreEspe,Descripcion" << std::endl;
    //especialidadMan.MostrarEspecialidades();
//
//
    //std::cout << std::endl <<"--------------------" << std::endl;
    //std::cout << "--------------------" << std::endl;
    //std::cout << "TRATAMIENTO:" << std::endl;
    //std::cout << "IDTratamiento,NombreTratamiento,Descripcion,DuracionDias,Costo" << std::endl;
    //tratamientoMan.MostrarTratamiento();
    //
    /*std::cout << std::endl <<"--------------------" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "CONSULTA:" << std::endl;
    std::cout << "IDConsultas,IDMascota,Fecha,Sintomas,Diagnostico,IDTratamiento,NombreTratamiento,DescTratamiento,DuracionTrata,CostoTrata,FechaProximaVisita,IDVeterinario,IDSucursal" << std::endl;
    consultaMan.MostrarConsulta();*/

    /*std::cout << std::endl <<"--------------------" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "PAGOS:" << std::endl;
    std::cout << "IDPago  |" << "IDConsulta  |" "\t" << "Monto  |"  << "FechaPago  |" "\t" << "MediodePago  |" << std::endl;
    std::cout << "---------------------------------------------------------------------------" << std::endl;
    pagosMan.MostrarPagos();
    std::cout << std::endl;*/
    //pagosMan.FacturacionPorAnio();

// hola
    return 0;
}
