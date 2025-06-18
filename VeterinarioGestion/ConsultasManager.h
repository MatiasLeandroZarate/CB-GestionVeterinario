#pragma once
#include <iostream>
#include "Sucursales.h"
#include <string>
#include "Fecha.h"
#include "Consultas.h"
#include "Mascotas.h"
#include "Validaciones.h"
#include "GestorArchivo.h"
#include "MascotaManager.h"
#include "SucursalManager.h"
#include "VeterinariosManager.h"
#include "TratamientosManager.h"
#include "ClienteManager.h"
#include <optional>
#include "rlutil.h"

class ConsultasManager
{
private:
	MascotaManager mascotasManager;
	SucursalManager sucursalesManager;
	VeterinariosManager veterinariosManager;
	TratamientosManager tratamientosManager;
	ClienteManager clientesManager;

    void imprimirEncabezadoListado();
    void imprimirConsulta(Consultas consulta);
    void listarConsultasConFiltro(bool (*filtro)(Consultas));

    bool esConsultaValida(Consultas consulta);
    bool esConsultaDuplicada(Consultas consulta);
    bool confirmaAccion();

    static int idMascotaFiltro;
    static Fecha fechaDesdeFiltro;
    static Fecha fechaHastaFiltro;
    static int idSucursalFiltro;
    static int idVeterinarioFiltro;
    static int idClienteFiltro;

    static bool sinFiltro(Consultas consulta);
    static bool filtroPorMascota(Consultas consulta);
    static bool filtroPorRangoDeFecha(Consultas consulta);
    static bool filtroPorSucursal(Consultas consulta);
    static bool filtroPorVeterinario(Consultas consulta);
    static bool filtroPorCliente(Consultas consulta);

    std::optional<Mascotas> solicitarMascotaValidada();
    std::optional<Sucursales> solicitarSucursalValidada();
    std::optional<Veterinarios> solicitarVeterinarioValidado();
    std::optional<Cliente> solicitarClienteValidado();
    std::optional<Tratamientos> solicitarTratamientoValidado();
public:
	void altaConsulta();
	void modificarConsulta();
	void listarConsultas();
	void bajaConsulta();
	void consultarPorMascota();
	void consultarPorFecha();
	void consultarPorSucursal();
	void consultarPorVeterinario();
	void consultarPorCliente();
	int BuscarConsultaPorID(int idBuscado);
    std::optional<Consultas> obtenerConsultaPorId(int idBuscado);
	int obtenerProximoId();
};

