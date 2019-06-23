#ifndef IINICIARVENTAENMESAS_H 
#define	IINICIARVENTAENMESAS_H 

#include <string>
#include <cstdlib>
#include <iostream>
#include <map> 
#include <set>

#include "Mozo.h"
#include "Repartidor.h"
using namespace std;

class IIniciarVentaEnMesas {
	public:
		virtual set <TipoMesa*> VerMesasMozo(int) = 0;
		virtual void ElegirMesaMozo(set<int>) = 0;
		virtual void ConfirmarVentaEnMesa() = 0;
                virtual void setNroEmpleado(int) = 0;
		virtual ~IIniciarVentaEnMesas(){};
};

#endif
	
