#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "contrProducto.h"
#include "ContrVenta.h"
#include "ContrEmpleado.h"
#include "factory.h"
using namespace std;

Factory * Factory :: instancia = NULL;

Factory * Factory :: getInstance() {
	if (instancia == NULL)
		instancia = new Factory();
	return instancia;
}

//interfaces

IAltaProducto * Factory :: getIAltaProducto() {
	return ContrProducto :: getInstance();
}

IAltaEmpleado * Factory :: getIAltaEmpleado() {
	return ContrEmpleado :: getInstance();
}

IAsignarMozosAMesas * Factory :: getIAsignarMozosAMesas() {
	return ContrEmpleado :: getInstance();
}

IIniciarVentaEnMesas * Factory :: getIIniciarVentaEnMesas() {
	return ContrEmpleado :: getInstance();
}

IAgregarProductoAUnaVenta * Factory :: getIAgregarProductoAUnaVenta() {
	return ContrVenta :: getInstance();
}

IQuitarProductoAUnaVenta * Factory :: getIQuitarProductoAUnaVenta() {
	return ContrVenta :: getInstance();
}

IFacturacionDeUnaVenta * Factory :: getIFacturacionDeUnaVenta() {
	return ContrVenta :: getInstance();
}

IVentaADomicilio * Factory :: getIVentaADomicilio() {
	return ContrVenta :: getInstance();
}

IInformacionDeUnProducto * Factory :: getIInformacionDeUnProducto() {
	return ContrProducto :: getInstance();
}

IFacturacionDeUnDia * Factory :: getIFacturacionDeUnDia() {
	return ContrVenta :: getInstance();
}

IBajaProducto * Factory :: getIBajaProducto() {
	return ContrProducto :: getInstance();
}

IModificarEstadoPedido * Factory :: getIModificarEstadoPedido() {
	return ContrEmpleado :: getInstance();
}

IConsultarPedidoCliente * Factory :: getIConsultarPedidoCliente() {
	return ContrVenta :: getInstance();
}

IConsultarPedidoAdmin * Factory :: getIConsultarPedidoAdmin() {
	return ContrVenta :: getInstance();
}