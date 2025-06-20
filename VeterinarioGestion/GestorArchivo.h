#pragma once
#include <iostream>
#include "Cliente.h"
#include "Mascotas.h"
#include "Sucursales.h"
#include "Especialidades.h"
#include "Veterinarios.h"
#include "Consultas.h"
#include "Tratamientos.h"
#include "Consultas.h"
#include "Pagos.h"
#include "Vacunas.h"
#include "Vacunaciones.h"

class GestorArchivo{
    private:
        std::string _nombreArchivo;

    public:
        GestorArchivo();
        GestorArchivo(std::string nombreArchivo);

        //Funciones para Cliente
        bool GuardarClientes(Cliente cliente);
        Cliente LeerClientes (int posicion);
        int CantidadRegistrosClientes();

		//Funciones para Mascotas
        bool GuardarMascotas(Mascotas mascota);
		Mascotas LeerMascota(int posicion);
		int CantidadRegistrosMascotas();
		 bool ModificarMascota(int pos, Mascotas mascotas);

        //Funciones para Sucursales
        bool GuardarSucursal(Sucursales sucursal);
        Sucursales LeerSucursal(int posicion);
        int CantidadRegistrosSucursales();

        //Funciones para Especialidades
        bool GuardarEspecialidad(Especialidades especialidad);
        Especialidades LeerEspecialidad(int posicion);
        int CantidadRegistrosEspecialidades();

        //Funciones para Veterinario
        bool GuardarVeterinario(Veterinarios veterinario);
        Veterinarios LeerVeterinario(int posicion);
        int CantidadRegistrosVeterinario();
        bool ModificarVeterinarios(int pos, Veterinarios veterinario);

		//Funciones para TRATAMIENTOS
        bool GuardarTratamientos(Tratamientos tratamiento);
        Tratamientos LeerTratamientos(int posicion);
        int CantidadRegistrosTratamientos();
        bool ModificarTratamiento(int pos, Tratamientos tratamiento);

        //Funciones para CONSULTAS
        bool GuardarConsultas(Consultas consultas);
        Consultas LeerConsultas(int posicion);
        int CantidadRegistrosConsultas();
        bool ModificarConsulta(int pos, Consultas consulta);

        //Funciones para Pagos
        bool GuardarPagos(Pagos pagos);
        Pagos LeerPagos(int posicion);
        int CantidadRegistrosPagos();

        //Funciones para Vacunas
        bool GuardarVacunas(Vacunas vacuna);
        Vacunas LeerVacunas(int posicion);
        int CantidadRegistrosVacunas();
        bool ModificarVacuna(int pos, Vacunas vacuna);

        //Funciones para Vacunaciones
        bool GuardarVacunaciones(Vacunaciones vacunaciones);
        Vacunaciones LeerVacunaciones(int posicion);
        int CantidadRegistrosVacunaciones();
};
