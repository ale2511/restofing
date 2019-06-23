#ifndef FACTURA_H
#define FACTURA_H
#include "tipofactura.h"
#include <set>
#include <string>
#include "CantProducto.h"

using namespace std;

class Factura {
	private:
		string nroFactura;
		map<string, CantProducto*> productos;
		TipoFecha* fecha;
		TipoHora* hora;
		float subtotal;
		float descuento;
		float precioSinIva;
		float total;
		TipoEmpleado* empleado;
	public:
		Factura(string, map<string, CantProducto*>, TipoFecha*, TipoHora*, float, float, float, float, TipoEmpleado*);
		string getNrofactura();
		set<string> mostrarCodProds();
		set<int> mostrarCantProds();
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