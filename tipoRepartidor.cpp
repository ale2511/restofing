#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoRepartidor.h"
using namespace std;


TipoRepartidor :: TipoRepartidor(int nro, string nombre, TipoTransporte trans) : TipoEmpleado(nro, nombre) {

    transporte = trans;
}
 


TipoTransporte TipoRepartidor :: getTransporte() {
  	return transporte;
}


void TipoRepartidor :: setTipoTransporte(TipoTransporte tt) {
	transporte = tt;
}




 ostream& operator <<(ostream &o, TipoRepartidor* &reparte){
 
                    if (reparte != NULL){
                    o << "Número Empleado: " << reparte->getnroEmpleado() << " / " << "Nombre empleado: " << reparte->getNombre() << endl;
   
                      } else {
                     o << "" << endl;
}



return o;
}
		
