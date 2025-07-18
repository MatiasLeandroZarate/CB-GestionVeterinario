#include "PagosManager.h"



void PagosManager::MostrarPagos()
{
    Pagos pago;
    GestorArchivo cArchivo("pagos.dat");
    int cantidadregistros = cArchivo.CantidadRegistrosPagos();
    if (cantidadregistros == 0)
    {
        std::cout << "No hay Pagos registrados." << std::endl;
    }

    for (int i = 0; i < cantidadregistros; i++)
    {
        pago = cArchivo.LeerPagos(i);

        std::cout << pago.toInforme() << std::endl;
        //std::cout << pago.toCSV() << std::endl;
    }
}

int PagosManager::BuscarPagosPorID(int idBuscado)
{
    Pagos pago;
    GestorArchivo cArchivo("pagos.dat");
    int cantidadRegistros = cArchivo.CantidadRegistrosPagos();
    for (int i = 0; i < cantidadRegistros; i++)
    {
        pago = cArchivo.LeerPagos(i);
        if (pago.getIDPagos() == idBuscado)
        {
            return i;
        }
    }
    std::cout << "No se encontr� el ID del Pago." << std::endl;
    return -1;
}

void PagosManager::FacturacionPorAnio()
{
    GestorArchivo tArchivo("tratamientos.dat");
    Tratamientos tratamiento;
    int cantidadRegistrosTratamientos = tArchivo.CantidadRegistrosTratamientos();
    Validaciones validar;
    Consultas consulta;
    GestorArchivo pArchivo("consultas.dat");
    int cantidadRegistros = pArchivo.CantidadRegistrosConsultas();
    int anio;
    float vecContadorGananciaAnual[12] {};
    float total=0;
    bool encontrado = false;
    std::cin.ignore();
    std::cout << "Ingrese Anio: ";
    anio = validar.validarNumero();


    for (int i = 0; i < cantidadRegistros; i++)
    {
        consulta = pArchivo.LeerConsultas(i);

        if (consulta.getFecha().getAnio() == anio)
        {
            int IDTrat = consulta.getIDTratamiento();


            for (int x = 0; x < cantidadRegistrosTratamientos; x++)
            {
                tratamiento = tArchivo.LeerTratamientos(x);
                if (tratamiento.getIDTratamiento() == IDTrat)
                {
                    int mes = consulta.getFecha().getMes();
                    if (mes >= 1 && mes <= 12)
                    {
                        vecContadorGananciaAnual[mes - 1] += tratamiento.getCosto();

                        encontrado = true;
                    }
                    break;
                }
            }
        }
    }

    system("cls");
    if(encontrado)
    {

        for(int i=0; i<12; i++)
        {

            std::cout << "MES " << i+1 << ": " << vecContadorGananciaAnual[i] << std::endl;
            total += vecContadorGananciaAnual[i];
        }
        std::cout << "TOTAL FACTURADO DEL " << anio << " :  " << total;
    }
    else
    {
        std::cout << "No se Encontraron Pagos registrados en ese anio.";
    }

}



void PagosManager::RecaudacionPorCliente()
{

    int IDCliente;
    Cliente cliente;
    GestorArchivo gArchivo("clientes.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
    bool IDValido = false;
    Validaciones validar;

    std::cin.ignore();
    while (!IDValido)
    {
        std::cout << "Ingrese ID del Cliente: ";
        IDCliente = validar.validarNumero();
        for (int i = 0; i < cantidadRegistros; i++)
        {
            cliente = gArchivo.LeerClientes(i);
            if (cliente.getIDCliente() == IDCliente)
            {
                IDValido = true;
            }
        }
        if (!IDValido)
        {
            std::cout << "ID no Encontrado, Ingrese de nuevo. " << std::endl;

        }

    }
    limpiarPantalla();
    GestorArchivo tArchivo("tratamientos.dat");
    Tratamientos tratamiento;
    int cantidadRegistrosTratamientos = tArchivo.CantidadRegistrosTratamientos();
    Mascotas mascotas;
    GestorArchivo mArchivo("mascotas.dat");
    int cantidadRegistrosMascotas = mArchivo.CantidadRegistrosMascotas();
    float Sumatoria = 0;
    Consultas consulta;
    GestorArchivo pArchivo("consultas.dat");
    int IDMascotaAux;
    cantidadRegistros = pArchivo.CantidadRegistrosConsultas();
    for (int i = 0; i < cantidadRegistros; i++)
    {
        consulta = pArchivo.LeerConsultas(i);
        IDMascotaAux = consulta.getIDMascotas();

        for (int j = 0; j < cantidadRegistrosMascotas; j++)
        {
            mascotas = mArchivo.LeerMascota(j);

            if(mascotas.getIDCliente() == IDCliente && mascotas.getIDMascota() == IDMascotaAux)
            {

                for(int x =0; x<cantidadRegistrosTratamientos; x++)
                {
                    tratamiento = tArchivo.LeerTratamientos(x);

                    if(consulta.getIDTratamiento() == tratamiento.getIDTratamiento())
                    {
                        Sumatoria += tratamiento.getCosto();
                    }

                }
            }


        }

    }
    std::cout << "--------------------" << std::endl;
    std::cout << "CLIENTE: " << std::endl;
    std::cout << "ID\t| DNI\t\t|Nombre\t|Apellido\t|Telefono\t|Email" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------" << std::endl;

    cliente = gArchivo.LeerClientes(IDCliente-1);
    //std::cout << cliente.toCSV() << std::endl;
    std::cout << cliente.toInforme() << std::endl<< std::endl;

    std::cout << "RECAUDACION TOTAL: $" << Sumatoria;


}

void PagosManager::RecaudacionPorSucursal()
{

    Consultas consulta;
    GestorArchivo pArchivo("consultas.dat");
    GestorArchivo sArchivo("sucursales.dat");
    Sucursales sucursal;
    GestorArchivo tArchivo("tratamientos.dat");
    Tratamientos tratamiento;
    int cantidadRegistrosTratamientos = tArchivo.CantidadRegistrosTratamientos();
    int sucursalAux;
    int cantidadRegistrosSucursales = sArchivo.CantidadRegistrosSucursales();
    int cantidadRegistros = pArchivo.CantidadRegistrosConsultas();
    float *vecSucursales;

    vecSucursales = new float [cantidadRegistrosSucursales];
    if(vecSucursales==nullptr)
    {
        std::cout << "Error Al asignar memoria.";
        return;
    }
         for (int i = 0; i < cantidadRegistrosSucursales; ++i)
    {
        vecSucursales[i] = 0.0f;
    }
    for (int i = 0; i < cantidadRegistros; i++)
    {
        consulta = pArchivo.LeerConsultas(i);
        sucursalAux = consulta.getIDSucursal();

        for(int j=0; j<cantidadRegistrosSucursales; j++)
        {
            sucursal = sArchivo.LeerSucursal(j);

            if(sucursal.getIDSucursal()==sucursalAux)
            {
                int IDTrat = consulta.getIDTratamiento();

                for (int x = 0; x < cantidadRegistrosTratamientos; x++)
                {
                    tratamiento = tArchivo.LeerTratamientos(x);
                    if (tratamiento.getIDTratamiento() == IDTrat)
                    {
                        vecSucursales[consulta.getIDSucursal()-1]+= tratamiento.getCosto();
                    }
                }

            }

        }

    }

    for(int i=0; i<cantidadRegistrosSucursales; i++)
    {
        sucursal = sArchivo.LeerSucursal(i);
        std::cout << "RECAUDACION DE LA SUCURSAL " << sucursal.getIDSucursal() << " : $" << vecSucursales[i]<< std::endl;
    }
    delete []vecSucursales;
}

