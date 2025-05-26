#include "Pagos.h"

Pagos::Pagos()
{
    _IDPago = 0;
    _IDConsulta = 0;
    _Monto = 0.0f;
    _FechaPago = Fecha();
    strcpy(_MedioPago, "");
}
Pagos::Pagos(int idpago, int idconsulta, float monto, Fecha fechapago, std::string mediopago)
{
    setIDPagos(idpago);
    setIDConsulta(idconsulta);
    setMonto(monto);
    setFechaPagos(fechapago);
    setMedioPagos(mediopago);
}

void Pagos::setIDPagos(int idpago)
{
    _IDPago = idpago;
}
void Pagos::setIDConsulta(int idconsulta)
{
    _IDConsulta = idconsulta;
}
void Pagos::setMonto(float monto)
{
    _Monto = monto;
}
void Pagos::setFechaPagos(Fecha fechapago)
{
    _FechaPago = fechapago;
}
void Pagos::setMedioPagos(std::string mediopago)
{
    strcpy(_MedioPago, mediopago.c_str());
}

int Pagos::getIDPagos()
{
    return _IDPago;
}
int Pagos::getIDConsulta()
{
    return _IDConsulta;
}
float Pagos::getMonto()
{
    return _Monto;
}
Fecha Pagos::getFechaPagos()
{
    return _FechaPago;
}
std::string Pagos::getMedioPagos()
{
    return _MedioPago;
}

std::string Pagos::toCSV()
{
    return std::to_string(_IDPago) + "," + std::to_string(_IDConsulta) + "," + std::to_string(_Monto) + "," + _FechaPago.toString() + "," + _MedioPago;
}

std::string Pagos::toInforme()
{
    return std::to_string(_IDPago) + "\t"+std::to_string(_IDConsulta)  + "\t\t"  + std::to_string(int(_Monto)) + "\t"+  _FechaPago.toString()+ "\t" + _MedioPago;
}
