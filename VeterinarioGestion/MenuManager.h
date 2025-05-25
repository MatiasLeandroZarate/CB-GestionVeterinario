#ifndef MENUMANAGER_H
#define MENUMANAGER_H

class MenuManager {
public:
    void procesarMenuPrincipal();
private:
    void evaluarOpcionDefault(int opcionSeleccionada);
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
    void mostrarMensajeOpcionInvalida();
};

#endif
