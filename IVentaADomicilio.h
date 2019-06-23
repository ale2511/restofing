#ifndef IVENTAADOMICILIO_H 
#define	IVENTAADOMICILIO_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Domicilio.h"
#include "Factura.h"
#include "Local.h"
#include "tipoRepartidor.h"
using namespace std;

class IVentaADomicilio {
	public:
		virtual bool noHayCliente(string) = 0;
		virtual TipoDireccion * hacedorDir(string, int, string, string) = 0;
		virtual TipoDireccionApart * hacedorApar(string, int, string, string, string, int) = 0;
		virtual void datosCliente(string, TipoDireccion *) = 0;
		virtual void confirmarAgregarCliente(bool) = 0;
		virtual set<TipoProducto *> darProds()= 0;
		virtual bool ingProds(string, int) = 0;
		virtual void confirmarProductoEnDomicilio() = 0;
		//virtual void confirmarAgregarProducto() = 0;
		virtual set<TipoRepartidor *> verRepartidores() = 0;
		virtual void elegirRepartidor(int) = 0;
		virtual void inicializarEstado(int) = 0;
		//virtual TipoFactura * facturar(float) = 0;
		~IVentaADomicilio(){};
};

#endif