#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
#include "Consultas.h"
#include "GestorArchivo.h"
#include "MascotaManager.h"
#include "SucursalManager.h"
#include "VeterinariosManager.h"
#include "TratamientosManager.h"
#include "optional"

class ConsultasManager
{
private:
	MascotaManager mascotasManager;
	SucursalManager sucursalesManager;
	VeterinariosManager veterinariosManager;
	TratamientosManager tratamientosManager;

    void imprimirListado();
    void imprimirConsulta(Consultas consulta);
    void listarConsultasConFiltro(bool (*filtro)(Consultas));

    bool validarNuevaConsulta(Consultas consulta);

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

