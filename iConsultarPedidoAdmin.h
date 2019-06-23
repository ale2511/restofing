#ifndef ICONSULTARPEDIDOADMIN_H 
#define	ICONSULTARPEDIDOADMIN_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Domicilio.h"
#include "Factura.h"
#include "Local.h"
using namespace std;

class IConsultarPedidoAdmin {
	public:
		virtual set<TipoActualizacion*> ListarActualizaciones() = 0;
		virtual ~IConsultarPedidoAdmin(){};
		virtual 	set<TipoActualizacion*> ListarActualizacionesSistema() = 0;
};

#endif