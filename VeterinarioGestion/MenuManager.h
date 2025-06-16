#ifndef MENUMANAGER_H
#define MENUMANAGER_H

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
    int procesarEntradaMenu(int opcionMinima, int opcionMaxima);
};

#endif
