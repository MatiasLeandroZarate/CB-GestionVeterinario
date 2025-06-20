#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "ExportacionesManager.h"
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
#include <iostream>
#include <string>

class MenuManager {
public:
    bool procesarMenuPrincipal();
private:
    void realizarOperacionPostSeleccion(int opcionSeleccionada);
    void procesarSubmenuClientes();
    void procesarSubmenuMascotas();
    void procesarSubmenuConsultasMedicas();
    void procesarSubmenuVacunas();
    void procesarSubmenuTratamientos();
    void procesarSubmenuVeterinarios();
    void procesarSubmenuSucursales();
    void procesarSubmenuPagos();
    void procesarSubmenuAcercaDe();
    void procesarSubmenuExportaciones();
    int procesarEntradaMenu(int opcionMinima, int opcionMaxima);
};

#endif
