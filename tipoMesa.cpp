#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoMesaMozo.h"
#include "tipoMesa.h"
using namespace std; 

//-----------------constr
TipoMesa :: TipoMesa(int a, bool b) {
   nroMesa = a;
   activa = b;
}

//-----------------get

int TipoMesa :: DarMesa() {
	return nroMesa;
}

bool TipoMesa :: Activa() {
	return activa;
}

//-----------------set

void TipoMesa :: setActiva(bool a) {
	activa = a;
}

void TipoMesa :: setDarMesa(int a) {
	nroMesa = a;
}

TipoMesa :: TipoMesa(int nro){

nroMesa = nro;}

ostream& operator <<(ostream &o, TipoMesa* &mesa){
 
                    if (mesa != NULL){
                    string estado;
                    if (mesa->Activa()){
                            estado = "En uso";} else {
                                     estado = "Libre";}
                    o << "Número mesa: " << mesa->DarMesa() << " / " << "Estado mesa: " << estado << endl;
   
                      } else {
                     o << "" << endl;
}



return o;
}
