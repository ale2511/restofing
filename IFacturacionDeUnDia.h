#ifndef IFACTURACIONDEUNDIA_H 
#define	IFACTURACIONDEUNDIA_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Domicilio.h"
#include "Factura.h"
#include "Local.h"
using namespace std;

class IFacturacionDeUnDia {
	public:
		virtual TipoFecha * hacedorFecha(int, int, int) = 0;
		virtual set<TipoFactura *> verFacturasFecha(TipoFecha *) = 0;
		virtual ~IFacturacionDeUnDia(){};
		virtual  void imprimirAct() = 0;
};

#endif