#ifndef SIMPLE_H 
#define	SIMPLE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "prodGral.h"
using namespace std;

class Simple : public ProdGral {
	public:
		//contructor
		Simple(string, string, float);
		//resto de operaciones
		TipoProducto * darDatosProd();
		//destructor
		~Simple(){};
};

#endif