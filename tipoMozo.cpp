#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoMozo.h"
using namespace std; 


TipoMozo::TipoMozo(int nro, string nombre, set<TipoMesa*> mesitas) : TipoEmpleado(nro, nombre){

    mesas = mesitas;
}


set<TipoMesa*> TipoMozo :: getMesas(){
	return mesas;
}


	
void TipoMozo :: SetMesas(TipoMesa* tm) {
	mesas.insert(tm);
}




 ostream& operator <<(ostream &o, TipoMozo* &reparte){
 
                    if (reparte != NULL){
                    o << "Número Empleado: " << reparte->getnroEmpleado() << " / " << "Nombre empleado: " << reparte->getNombre() << endl;
   
                      } else {
                     o << "" << endl;
}



return o;
}
		
