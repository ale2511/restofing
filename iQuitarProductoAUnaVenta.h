#ifndef IQUITARPRODUCTOAUNAVENTA_H 
#define	IQUITARPRODUCTOAUNAVENTA_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Domicilio.h"
#include "Factura.h"
#include "Local.h"
using namespace std;

class IQuitarProductoAUnaVenta {
	public:
		virtual bool ventaNoFacturada(int) = 0;
		virtual set <TipoProducto *> verProdsVenta() = 0;
		virtual bool prodAEliminar(string, int) = 0;
		virtual void confirmarQuitarProdVenta() = 0;
		virtual ~IQuitarProductoAUnaVenta(){};
};

#endif