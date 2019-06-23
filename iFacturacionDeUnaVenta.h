#ifndef IFACTURACIONDEUNAVENTA_H 
#define	IFACTURACIONDEUNAVENTA_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Domicilio.h"
#include "Factura.h"
#include "Local.h"
using namespace std;

class IFacturacionDeUnaVenta {
	public:
		virtual bool ventaNoFacturada(int) = 0;
		virtual TipoFactura * facturar(float) = 0;
		~IFacturacionDeUnaVenta(){};
};

#endif
