#include <iostream>
#include "MenuManager.h"

using namespace std;

int main() {
    const string MENSAJE_ERROR_ADMINISTRADOR = " - Porfavor comuniquese con el administrador del sistema.";
    bool salirMenu = false;

    MenuManager menuManager;

    do{
        try {
            salirMenu = menuManager.procesarMenuPrincipal();
            if (salirMenu){
                break;
            }
        }
        catch (const exception& ex) {
            cerr << "Se produjo un error: " << ex.what() << MENSAJE_ERROR_ADMINISTRADOR << endl;
        }
        catch (...) {
            cerr << "Se produjo un error desconocido." << MENSAJE_ERROR_ADMINISTRADOR  << endl;
        }
    } while(!salirMenu);

    return 0;
}
