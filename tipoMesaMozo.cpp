#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoMesaMozo.h"
using namespace std; 

TipoMesaMozo :: TipoMesaMozo(int nro, int mesas){
	nroMozo = nro;
	cantmesas = mesas;
}

int TipoMesaMozo :: getMozo() {
	return nroMozo;
}

int TipoMesaMozo :: getCantMesas() {
	return cantmesas;
}

void TipoMesaMozo :: setMozo(int n) {
	nroMozo = n;
}

void TipoMesaMozo :: setCantMesas(int c) {
	cantmesas = c;
}


                ostream& operator <<(ostream &o, TipoMesaMozo* &mesa){
 
                    if (mesa != NULL){
                    o << "Número mozo: " << mesa->getMozo() << " / " << "Cantidad de mesas: " << mesa->getCantMesas() << endl;
   
                      } else {
                     o << "" << endl;
}



return o;
}
