#pragma once
#include "GestorArchivo.h"
#include "EspecialidadManager.h"
#include "Veterinarios.h"
#include "FuncionesGlobales.h"
#include "Validaciones.h"


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

	bool BuscarVeterinarioPorDNI(std::string dniBuscado);
	bool ConfirmarIngreso(Veterinarios veterinario, bool confirmar);
	bool BajaVeterinario();
	void ModificarVeterinarios();

	//int validarNumero();
	//bool validarBool();
	//std::string validarNombre();
    //std::string validarNUMenString();


};

