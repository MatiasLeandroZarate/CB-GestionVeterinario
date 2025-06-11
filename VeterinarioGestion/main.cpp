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


    //std::cout << std::endl <<"--------------------" << std::endl;
    //std::cout << "--------------------" << std::endl;
    //std::cout << "SUCURSAL: " << std::endl;
    //std::cout << "IDSucursal,NombreSuc,Direccion";
    //sucursalMan.MostrarSucursal();
    //
   // std::cout << std::endl <<"--------------------" << std::endl;
   // std::cout << "--------------------" << std::endl;
   // std::cout << "ESPECIALIDADES: " << std::endl;
   // std::cout << "IDEspecialidad,NombreEspe,Descripcion" << std::endl;
   //especialidadMan.MostrarEspecialidades();
/*
    std::cout << "PAGOS:" << std::endl;
    std::cout << "IDPago  |" << "IDConsulta  |" "\t" << "Monto  |"  << "FechaPago  |" "\t" << "MediodePago  |" << std::endl;
    std::cout << "---------------------------------------------------------------------------" << std::endl;
    pagosMan.MostrarPagos();
    std::cout << std::endl;*/
    //pagosMan.FacturacionPorAnio();

    return 0;
}
