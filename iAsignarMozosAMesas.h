#ifndef IASIGNARMOZOSAMESAS_H 
#define	IASIGNARMOZOSAMESAS_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Mozo.h"
#include "Repartidor.h"
#include "tipoMesaMozo.h"
using namespace std;

class IAsignarMozosAMesas {
	public:
		virtual set<TipoMesaMozo*> AsignarMozoMesas() = 0;
                
		virtual ~IAsignarMozosAMesas(){};
};

#endif
