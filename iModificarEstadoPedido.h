#ifndef IMODIFICARESTADOPEDIDO_H 
#define	IMODIFICARESTADOPEDIDO_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Mozo.h"
#include "Repartidor.h"
#include "tipofactura.h"
using namespace std;

class IModificarEstadoPedido {
	public:
		virtual bool existeVentaDom(string) = 0;
		virtual set <TipoEstado> ingrPedido(string) = 0;
		virtual void elegirEstado(int) = 0;
		virtual void confirmarNuevoEstado() = 0;
		virtual TipoFactura * facturar(float) = 0;
		virtual ~IModificarEstadoPedido(){};
        virtual 		set<TipoDomicilio*> getVentasRepartidor(int) = 0;
		virtual void cargarAct() = 0;
};

#endif
