#pragma once
#include "GestorArchivo.h"
#include "EspecialidadManager.h"
#include "Veterinarios.h"
#include "FuncionesGlobales.h"
#include "Validaciones.h"
#include <cstring>
#include "rlutil.h"
#include <optional>

class VeterinariosManager
{private:
public:
	void CargarVeterinarios();
	void MostrarVeterinarioInforme();
	void MostrarVeterinarioExportable();
	void Guardar(Veterinarios veterinarios);
	void ListarVeterinariosActivos();

	int SiguienteID();
	int BuscarVeterinariosPorID(int idBuscado);
	std::optional<Veterinarios> obtenerVeterinarioPorId(int idBuscado);
	bool BuscarVeterinarioPorDNI(std::string dniBuscado);
	bool ConfirmarIngreso(Veterinarios veterinario, bool confirmar);
	bool BajaVeterinario();
	void ModificarVeterinarios();
	int procesarEntradaMenu(int opcionMinima, int opcionMaxima);

	void LocateTitulo();
};

