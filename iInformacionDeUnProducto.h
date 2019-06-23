#ifndef IINFORMACIONDEUNPRODUCTO_H 
#define	IINFORMACIONDEUNPRODUCTO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "menu.h"
#include "tipoCantProducto.h"
using namespace std;

class IInformacionDeUnProducto {
	public:
		virtual set <TipoProducto *> darProds() = 0;
		virtual bool productoValido(string) = 0;
		virtual TipoCantProducto * verInfoProducto() = 0;
		virtual ~IInformacionDeUnProducto(){};
};

#endif