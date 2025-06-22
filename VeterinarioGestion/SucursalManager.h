#pragma once
#include "GestorArchivo.h"
#include "Sucursales.h"
#include "Validaciones.h"
#include "rlutil.h"
#include <optional>

class SucursalManager
{
private:
public:
    void CargarSucursal();
    void MostrarSucursal();
    int BuscarSucursalPorID(int idBuscado);
    int GenerarIdAutomatico();
    int procesarEntradaMenu(int opcionMinima, int opcionMaxima);
    void LocateTitulo();
    void ModificarSucursal();
    bool DarDeBajaSucursal();
    std::optional<Sucursales> obtenerSucursalPorId(int idBuscado);
};

