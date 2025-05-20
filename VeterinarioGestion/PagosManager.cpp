#include "PagosManager.h"

void PagosManager::CargarPagos()
{
    Pagos pago;
    GestorArchivo pArchivo("pagos.dat");

    int IDPagos, IDConsulta;
    float Monto;
    std::string MedioPago;
    Fecha Fechapago;
    int dia, mes, anio;

    std::cout << "Ingrese el ID del Pago: ";
    std::cin >> IDPagos;
    std::cout << "Ingrese el ID de la Consulta: ";
    std::cin >> IDConsulta;
    std::cout << "Ingrese el Monto: ";
    std::cin >> Monto;
    std::cout << "Ingrese la Fecha del Pago: " << std::endl;
    std::cout << "Dia: ";
    std::cin >> dia;
    std::cout << "Mes: ";
    std::cin >> mes;
    std::cout << "Anio: ";
    std::cin >> anio;
    Fechapago = Fecha(dia, mes, anio);
    std::cout << "Ingrese el Medio de Pago: ";
    std::cin.ignore();
    std::getline(std::cin, MedioPago);


    pago = Pagos(IDPagos, IDConsulta, Monto, Fechapago, MedioPago);

    if (pArchivo.GuardarPagos(pago))
        {
            std::cout << std::endl;
            std::cout << "El Pago fue guardado correctamente." << std::endl;
        }
    else
        {
            std::cout << "Error al guardar el Pago." << std::endl;
        }
}

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
            std::cout << pago.toCSV() << std::endl;
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
    std::cout << "No se encontró el ID del Pago." << std::endl;
    return -1;
}

void PagosManager::FacturacionPorAnio()
{
    Pagos pago;
    GestorArchivo pArchivo("pagos.dat");
    int anio;
    std::cout << "Ingrese Anio Facturado: ";
    std::cin >> anio;
    float MesVec[12] = {0};
    int cantidadRegistros = pArchivo.CantidadRegistrosPagos();
    float totalFacturado = 0.0f;
    if (cantidadRegistros == 0)
        {
            std::cout << "No hay Pagos registrados." << std::endl;
        }

    std::cout << "FACTURACION DEL ANIO: " << anio << std::endl;
    std::cout << "MESES" << "\t \t" << "FACTURACION" <<std::endl;
    std::cout << "-------------------------------------" << std::endl;

    for (int i = 0; i < cantidadRegistros; i++)
        {
            pago = pArchivo.LeerPagos(i);
            if (pago.getFechaPagos().getAnio() == anio)
                {
                    MesVec[pago.getFechaPagos().getMes() - 1] += pago.getMonto();
                    totalFacturado += pago.getMonto();
                }
        }

    std::cout << "ENERO" << "\t \t" << MesVec[0] << std::endl;
    std::cout << "FEBRERO" << "\t \t" << MesVec[1] << std::endl;
    std::cout << "MARZO" << "\t \t" << MesVec[2] << std::endl;
    std::cout << "ABRIL" << "\t \t" << MesVec[3] << std::endl;
    std::cout << "MAYO" << "\t \t" << MesVec[4] << std::endl;
    std::cout << "JUNIO" << "\t \t" << MesVec[5] << std::endl;
    std::cout << "JULIO" << "\t \t" << MesVec[6] << std::endl;
    std::cout << "AGOSTO" << "\t \t" << MesVec[7] << std::endl;
    std::cout << "SEPTIEMBRE" << "\t" << MesVec[8] << std::endl;
    std::cout << "OCTUBRE" << "\t \t" << MesVec[9] << std::endl;
    std::cout << "NOVIEMBRE" << "\t" << MesVec[10] << std::endl;
    std::cout << "DICIEMBRE" << "\t" << MesVec[11] << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "TOTAL FACTURADO:" <<"\t " << totalFacturado << std::endl;
}
