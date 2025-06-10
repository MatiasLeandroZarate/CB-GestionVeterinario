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
    return 0;
}
