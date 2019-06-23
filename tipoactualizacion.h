#ifndef TIPOACTUALIZACION_H
#define	TIPOACTUALIZACION_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "TipoHora.h"
#include "TipoFecha.h"
#include "tipoCantProducto.h"
using namespace std;


class TipoActualizacion{
	private:
		TipoHora * hora;
		TipoFecha * fecha;
		string nombrerepartidor;
		string nombrecliente;
		set<TipoCantProducto*> pedido;
		string telefono;
		TipoEstado estado;
	public:
		TipoActualizacion(TipoHora *, TipoFecha *, string, string, set<TipoCantProducto*>, string, TipoEstado);
		TipoHora * getHora();
		TipoFecha * getFecha();
		string getNombrerepartidor();
		string getNombrecliente();
		set<TipoCantProducto*> getPedido();
		string getTelefono();
		TipoEstado getEstado();


};

#endif
