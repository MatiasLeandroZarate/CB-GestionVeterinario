#include "GestorArchivo.h"

GestorArchivo::GestorArchivo() {
	_nombreArchivo = "error.dat";
}

GestorArchivo::GestorArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

// ----------------------------------SECTOR CLIENTES----------------------------------
bool GestorArchivo::GuardarClientes(Cliente cliente) {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
	if (pArchivo == nullptr) {
		return false;
	}
	bool ok = fwrite(&cliente, sizeof(cliente), 1, pArchivo);
	fclose(pArchivo);
	return ok;
}


Cliente GestorArchivo::LeerClientes(int posicion){
    Cliente cliente;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr){
        return Cliente();
    }
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return cliente;
}

int GestorArchivo::CantidadRegistrosClientes(){
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
    fclose(pArchivo);
    return cantidadRegistros;
}

// ----------------------------------SECTOR MASCOTAS----------------------------------

bool GestorArchivo::GuardarMascotas(Mascotas mascota)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&mascota, sizeof(mascota), 1, pArchivo);
    fclose(pArchivo);
    return ok;

}

Mascotas GestorArchivo::LeerMascota(int posicion)
{
    Mascotas mascota;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Mascotas();
    }
    fseek(pArchivo, sizeof(Mascotas) * posicion, SEEK_SET);
    fread(&mascota, sizeof(Mascotas), 1, pArchivo);
    fclose(pArchivo);
    return mascota;

}

int GestorArchivo::CantidadRegistrosMascotas()
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
    fclose(pArchivo);
    return cantidadRegistros;
}

bool GestorArchivo::ModificarMascota(int pos, Mascotas mascotas) {
    FILE* p;
    p = fopen("mascotas.dat", "rb+");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Mascotas), SEEK_SET);
    bool escribio = fwrite(&mascotas, sizeof(Mascotas), 1, p);
    fclose(p);

    return escribio;
}

// ----------------------------------SECTOR SUCURSALES----------------------------------

bool GestorArchivo::GuardarSucursal(Sucursales sucursal)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&sucursal, sizeof(sucursal), 1, pArchivo);
    fclose(pArchivo);
    return ok;

}

Sucursales GestorArchivo::LeerSucursal(int posicion)
{
    Sucursales sucursal;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Sucursales();
    }
    fseek(pArchivo, sizeof(Sucursales) * posicion, SEEK_SET);
    fread(&sucursal, sizeof(Sucursales), 1, pArchivo);
    fclose(pArchivo);
    return sucursal;

}

int GestorArchivo::CantidadRegistrosSucursales()
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Sucursales);
    fclose(pArchivo);
    return cantidadRegistros;
}
// ----------------------------------SECTOR ESPECIALIDAD----------------------------------
bool GestorArchivo::GuardarEspecialidad(Especialidades especialidad) {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&especialidad, sizeof(especialidad), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


Especialidades GestorArchivo::LeerEspecialidad(int posicion) {
    Especialidades especialidad;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Especialidades();
    }
    fseek(pArchivo, sizeof(Especialidades) * posicion, SEEK_SET);
    fread(&especialidad, sizeof(Especialidades), 1, pArchivo);
    fclose(pArchivo);
    return especialidad;
}

int GestorArchivo::CantidadRegistrosEspecialidades() {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Especialidades);
    fclose(pArchivo);
    return cantidadRegistros;
}

// ----------------------------------SECTOR Veterinarios ----------------------------------
bool GestorArchivo::GuardarVeterinario(Veterinarios veterinario)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&veterinario, sizeof(veterinario), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


Veterinarios GestorArchivo::LeerVeterinario(int posicion) {
    Veterinarios veterinario;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Veterinarios();
    }
    fseek(pArchivo, sizeof(Veterinarios) * posicion, SEEK_SET);
    fread(&veterinario, sizeof(Veterinarios), 1, pArchivo);
    fclose(pArchivo);
    return veterinario;
}

int GestorArchivo::CantidadRegistrosVeterinario() {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Veterinarios);
    fclose(pArchivo);
    return cantidadRegistros;
}

bool GestorArchivo::ModificarVeterinarios(int pos, Veterinarios veterinario) {
    FILE* p;
    p = fopen("veterinarios.dat", "rb+");
    if (p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof(Veterinarios), SEEK_SET);
    bool escribio = fwrite(&veterinario, sizeof(Veterinarios), 1, p);
    fclose(p);

    return escribio;
}

// ----------------------------------SECTOR TRATAMIENTO ----------------------------------
bool GestorArchivo::GuardarTratamientos(Tratamientos tratamiento)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&tratamiento, sizeof(tratamiento), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


Tratamientos GestorArchivo::LeerTratamientos(int posicion) {
    Tratamientos tratamiento;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Tratamientos();
    }
    fseek(pArchivo, sizeof(Tratamientos) * posicion, SEEK_SET);
    fread(&tratamiento, sizeof(Tratamientos), 1, pArchivo);
    fclose(pArchivo);
    return tratamiento;
}

int GestorArchivo::CantidadRegistrosTratamientos() {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Tratamientos);
    fclose(pArchivo);
    return cantidadRegistros;
}

bool GestorArchivo::ModificarTratamiento(int pos, Tratamientos tratamiento) {
    FILE* p;
    p = fopen("tratamientos.dat", "rb+");
    if (p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof(Tratamientos), SEEK_SET);
    bool escribio = fwrite(&tratamiento, sizeof(Tratamientos), 1, p);
    fclose(p);

    return escribio;
}

// ----------------------------------SECTOR CONSULTAS ----------------------------------
bool GestorArchivo::GuardarConsultas(Consultas consultas)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&consultas, sizeof(consultas), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


Consultas GestorArchivo::LeerConsultas(int posicion) {
    Consultas consulta;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Consultas();
    }
    fseek(pArchivo, sizeof(Consultas) * posicion, SEEK_SET);
    fread(&consulta, sizeof(Consultas), 1, pArchivo);
    fclose(pArchivo);
    return consulta;
}

int GestorArchivo::CantidadRegistrosConsultas() {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Consultas);
    fclose(pArchivo);
    return cantidadRegistros;
}

// ----------------------------------SECTOR PAGOS ----------------------------------
bool GestorArchivo::GuardarPagos(Pagos pagos)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&pagos, sizeof(pagos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


Pagos GestorArchivo::LeerPagos(int posicion) {
    Pagos pagos;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Pagos();
    }
    fseek(pArchivo, sizeof(Pagos) * posicion, SEEK_SET);
    fread(&pagos, sizeof(Pagos), 1, pArchivo);
    fclose(pArchivo);
    return pagos;
}

int GestorArchivo::CantidadRegistrosPagos() {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Pagos);
    fclose(pArchivo);
    return cantidadRegistros;
}

// ----------------------------------SECTOR VACUNAS  ----------------------------------
bool GestorArchivo::GuardarVacunas(Vacunas vacuna)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&vacuna, sizeof(vacuna), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


Vacunas GestorArchivo::LeerVacunas(int posicion) {
    Vacunas vacuna;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Vacunas();
    }
    fseek(pArchivo, sizeof(Vacunas) * posicion, SEEK_SET);
    fread(&vacuna, sizeof(Vacunas), 1, pArchivo);
    fclose(pArchivo);
    return vacuna;
}

int GestorArchivo::CantidadRegistrosVacunas() {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Vacunas);
    fclose(pArchivo);
    return cantidadRegistros;
}

// ----------------------------------SECTOR VACUNACIONES  ----------------------------------
bool GestorArchivo::GuardarVacunaciones(Vacunaciones vacunaciones)
{
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == nullptr) {
        return false;
    }
    bool ok = fwrite(&vacunaciones, sizeof(vacunaciones), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


Vacunaciones GestorArchivo::LeerVacunaciones(int posicion) {
    Vacunaciones vacunaciones;
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return Vacunaciones();
    }
    fseek(pArchivo, sizeof(Vacunaciones) * posicion, SEEK_SET);
    fread(&vacunaciones, sizeof(Vacunaciones), 1, pArchivo);
    fclose(pArchivo);
    return vacunaciones;
}

int GestorArchivo::CantidadRegistrosVacunaciones() {
    FILE* pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Vacunaciones);
    fclose(pArchivo);
    return cantidadRegistros;
}
