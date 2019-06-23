#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoProducto.h"
#include "tipoSimple.h"
using namespace std;

//constructor

TipoSimple :: TipoSimple(string miCod, string miDescripcion, float miPrecio) : TipoProducto(miCod, miDescripcion, miPrecio) {}


ostream& operator <<(ostream &o, TipoSimple* &simple){
 
                    if (simple != NULL){
                    
                    o << "Código Producto: " << simple->getCod() << " / " << "Descripccion: " << simple->getDescripcion() << "Precio: " << simple->getPrecio() << endl;
   
                      } else {
                     o << "" << endl;
}



return o;
}
