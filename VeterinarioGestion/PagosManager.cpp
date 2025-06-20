#include "PagosManager.h"

void PagosManager::CargarPagos()
{
    Pagos pago;
    GestorArchivo pArchivo("pagos.dat");

    int IDPagos, IDConsulta;
    float Monto;
    std::string MedioPago;
    Fecha Fechapago, fechavalidar;

    std::cout << "Ingrese el ID del Pago: ";
    std::cin >> IDPagos;
    std::cout << "Ingrese el ID de la Consulta: ";
    std::cin >> IDConsulta;
    std::cout << "Ingrese el Monto: ";
    std::cin >> Monto;
    std::cout << "Ingrese la Fecha del Pago: " << std::endl;

    Fechapago = fechavalidar.ValidacionFecha(Fechapago);

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
    std::cout << "No se encontró el ID del Pago." << std::endl;
    return -1;
}
/*
void PagosManager::FacturacionPorAnio()
{
    Validaciones validar;
    Consultas consulta;
    GestorArchivo pArchivo("consultas.dat");
    int cantidadRegistros = pArchivo.CantidadRegistrosConsultas();
    int anio;
    float vecContadorGananciaAnual[12] {};
    float total;
    bool encontrado = false;
    std::cout << "Ingrese Anio: ";
    anio = validar.validarNumero();


    for (int i = 0; i < cantidadRegistros; i++)
        {
            consulta = pArchivo.LeerConsultas(i);
            if(consulta.getFecha().getAnio() == anio)
                {

                    vecContadorGananciaAnual[consulta.getFecha().getMes()-1] += consulta.getIDTratamiento().getCosto();
                    encontrado = true;
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
*/
void PagosManager::RecaudacionPorCliente()
{

    int IDCliente;
    Cliente cliente;
    GestorArchivo gArchivo("clientes.dat");
    int cantidadRegistros = gArchivo.CantidadRegistrosClientes();
    bool IDValido = false;

    while (!IDValido)
        {

            std::cout << "Ingrese ID del Cliente: ";
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
                    std::cout << "ID invalido, Ingrese de nuevo." << std::endl;

                }

        }
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
                    mascotas = gArchivo.LeerMascota(j);

                    if(mascotas.getIDCliente() == IDCliente && mascotas.getIDMascota() == IDMascotaAux)
                        {
                           // Sumatoria += consulta.getTratamiento().getCosto();
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
    int sucursalAux;
    int cantidadRegistrosSucursales = sArchivo.CantidadRegistrosSucursales();
    int cantidadRegistros = pArchivo.CantidadRegistrosConsultas();

    for (int i = 0; i < cantidadRegistros; i++)
        {
            consulta = pArchivo.LeerConsultas(i);
            sucursalAux = consulta.getIDSucursal();

            for(int j=0; j<cantidadRegistrosSucursales; j++)
                {
                    sucursal = sArchivo.LeerSucursal(i);

                    if(sucursal.getIDSucursal()==sucursalAux)
                        {
                           // sucursal.setRecaudacion()+=consulta.getTratamiento().getCosto();
                        }

                }

        }

    for(int i=0; i<cantidadRegistrosSucursales; i++)
        {
            sucursal = sArchivo.LeerSucursal(i);
         //   std::cout << "RECAUDACION DE LA SUCURSAL " << sucursal.setIDSucursal() << " : $" << sucursal.getRecaudacion()<< std::endl;
        }
}


/*
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
*/
