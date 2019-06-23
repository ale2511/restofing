#ifndef FACTORY_H 
#define	FACTORY_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "contrProducto.h"
#include "ContrVenta.h"
#include "ContrEmpleado.h"
using namespace std;

class Factory {
	private:
		static Factory * instancia;
		Factory(){};
	public:
		static Factory * getInstance();
		//interfaces
		IAltaProducto * getIAltaProducto();
		IAltaEmpleado * getIAltaEmpleado();
		IAsignarMozosAMesas * getIAsignarMozosAMesas();
		IIniciarVentaEnMesas * getIIniciarVentaEnMesas();
		IAgregarProductoAUnaVenta * getIAgregarProductoAUnaVenta();
		IQuitarProductoAUnaVenta * getIQuitarProductoAUnaVenta();
		IFacturacionDeUnaVenta * getIFacturacionDeUnaVenta();
		IVentaADomicilio * getIVentaADomicilio();
		IInformacionDeUnProducto * getIInformacionDeUnProducto();
		IFacturacionDeUnDia * getIFacturacionDeUnDia();
		IBajaProducto * getIBajaProducto();
		IModificarEstadoPedido * getIModificarEstadoPedido();
		IConsultarPedidoCliente * getIConsultarPedidoCliente();
		IConsultarPedidoAdmin * getIConsultarPedidoAdmin();
};

#endif