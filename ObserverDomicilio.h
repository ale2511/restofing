#ifndef OBSERVERDOMICILIO_H
#define OBSERVERDOMICILIO_H
#include "tipoactualizacion.h"
using namespace std;


class ObserverDomicilio{
public:
	ObserverDomicilio(){};
	virtual void actualizar(TipoActualizacion*) = 0;


};

#endif