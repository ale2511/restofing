#ifndef TIPOSIMPLE_H 
#define	TIPOSIMPLE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoProducto.h"
using namespace std;

class TipoSimple : public TipoProducto {
	public:
		//constructor
		TipoSimple(string, string, float);
		//destructor
		~TipoSimple(){};
};

                ostream& operator << (ostream &o, TipoSimple* &simple);

#endif
