#ifndef IBAJAPRODUCTO_H 
#define	IBAJAPRODUCTO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "menu.h"
using namespace std;

class IBajaProducto {
	public:
		virtual bool hayProducto() = 0;
		virtual set <TipoProducto *> darProds() = 0;
		virtual bool productoValido(string) = 0;
		virtual bool noHayVenta(string) = 0;
		virtual void confirmarBajaProd() = 0;
		virtual ~IBajaProducto(){};
};

#endif