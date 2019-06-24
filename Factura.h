#ifndef FACTURA_H
#define FACTURA_H
#include "tipofactura.h"
#include <set>
#include <string>
#include "tipoCantProducto.h"

using namespace std;

class Factura {
	private:
		string nroFactura;
		map<string, TipoCantProducto*> productos;
		TipoFecha* fecha;
		TipoHora* hora;
		float subtotal;
		float descuento;
		float precioSinIva;
		float total;
		TipoEmpleado* empleado;
	public:
		Factura(string, map<string, TipoCantProducto*>, TipoFecha*, TipoHora*, float, float, float, float, TipoEmpleado*);
		map<string, TipoCantProducto*> mostrarTipoProds();
		string getNrofactura();
		TipoFecha* getFecha();
		TipoHora* getHora();
		float getSubtotal();
		float getDescuento();
		float getPreciosSinIva();
		float getTotal();
		TipoEmpleado* getEmpleado();
		TipoCantProducto * verProdsFacturados(string, TipoCantProducto *);
};

#endif 
