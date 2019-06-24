#ifndef IALTAEMPLEADO_H 
#define	IALTAEMPLEADO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Mozo.h"
#include "Repartidor.h"
#include "tipoRepartidor.h"
using namespace std;

class IAltaEmpleado {
	public:
		virtual void ingresarNombre(string) = 0;
		virtual set<TipoTransporte> DarTransporte() = 0;
		virtual void ingresarTransporte(int) = 0;
		virtual void ConfirmarEmpleado(bool) = 0;
		virtual void crearmesa(int) = 0;      //solo para la prueba
		virtual ~IAltaEmpleado(){};
		virtual void setNombreEmpleado(string) = 0;
		virtual void setVehiculo(int) = 0;
		virtual set<TipoRepartidor*> VerRepartidores() = 0;
		virtual bool encontrarRepartidor(int) = 0;
		virtual set<TipoMozo*> VerMozos() = 0;
};

#endif
