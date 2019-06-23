#ifndef IALTAPRODUCTO_H 
#define	IALTAPRODUCTO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "menu.h"
using namespace std;

class IAltaProducto {
	public:
		virtual bool hayProdSim() = 0;
		virtual bool noHayCodigo(string) = 0;
		virtual void datosProdSim(string, float) = 0;
		virtual void datosProdMenu(string) = 0;
		virtual set <TipoSimple *> darProdSim() = 0;
		virtual void ingrProdSim(string, int) = 0;
		virtual void confirmarAltaProd(bool) = 0;
		//operaciones auxiliares
		virtual void borrarPares() = 0;
		virtual bool haySimple(string) = 0;
		virtual ~IAltaProducto(){};
};

#endif