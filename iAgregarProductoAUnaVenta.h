#ifndef IAGREGARPRODUCTOAUNAVENTA_H 
#define	IAGREGARPRODUCTOAUNAVENTA_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Domicilio.h"
#include "Factura.h"
#include "Local.h"
#include "Venta.h"
using namespace std;

class IAgregarProductoAUnaVenta {
	public:
		virtual bool ventaNoFacturada(int) = 0;
		virtual set <TipoProducto *> darProds() = 0;
		virtual bool ingProds(string, int) = 0;
		virtual void confirmarAgregarProducto() = 0;
		virtual ~IAgregarProductoAUnaVenta(){};
};

#endif
