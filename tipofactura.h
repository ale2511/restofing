#ifndef TIPOFACTURA_H
#define TIPOFACTURA_H

#include <string>
#include "TipoFecha.h"
#include "TipoHora.h"
#include "tipoCantProducto.h"
#include "tipoMozo.h"
#include "tipoRepartidor.h"


using namespace std;

class TipoFactura {
private:
	string nrofactura;
	set<TipoCantProducto*> productos;
	TipoFecha* fecha;
    TipoHora* hora;
    float subtotal;
    float descuento;
    float preciosiniva;
    float total;
	TipoEmpleado* empleado;
public:
	TipoFactura(string, set<TipoCantProducto*>,TipoFecha*, TipoHora*, float, float, float, float, TipoEmpleado*);
	string getNrofactura();
	set<TipoCantProducto*> getProductos();
	TipoFecha* getFecha();
	TipoHora* getHora();
	float getSubtotal();
	float getDescuento();
	float getPreciosiniva();
	float getTotal();
	TipoEmpleado* getEmpleado();

};

#endif
