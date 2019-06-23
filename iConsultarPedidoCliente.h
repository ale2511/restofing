#ifndef ICONSULTARPEDIDOCLIENTE_H 
#define	ICONSULTARPEDIDOCLIENTE_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Domicilio.h"
#include "Factura.h"
#include "Local.h"
using namespace std;

class IConsultarPedidoCliente {
	public:
		virtual bool noHayCliente(string) = 0;
		virtual bool recibeMensajes() = 0;
		virtual TipoActualizacion * ConfirmarMensaje() = 0;
		virtual ~IConsultarPedidoCliente(){};
};

#endif