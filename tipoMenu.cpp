#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoCantProdMenu.h"
#include "tipoMenu.h"
using namespace std;

//constructor

TipoMenu :: TipoMenu(string miCod, string miDescripcion, float miPrecio, set<TipoCantProdMenu *> misProds) : TipoProducto(miCod, miDescripcion, miPrecio) {
	prods = misProds;
}

//getter

set <TipoCantProdMenu *> TipoMenu :: getProds() {
	return prods;
}

//setter

void TipoMenu :: setProds(set <TipoCantProdMenu *> unosProds) {
	prods = unosProds;
}

//destructor

TipoMenu :: ~TipoMenu() {
	set <TipoCantProdMenu *> :: iterator it;
	TipoCantProdMenu * aBorrar;
	for(it = prods.begin(); it != prods.end(); ++it) {
		aBorrar = *it;
		prods.erase(aBorrar);
		aBorrar->~TipoCantProdMenu();
	}
}

ostream& operator <<(ostream &o, TipoMenu* &simple){
 
                    if (simple != NULL){
                    
                    o << "Código Producto: " << simple->getCod() << " / " << "Descripccion: " << simple->getDescripcion() << "Precio: " << simple->getPrecio() << endl;
   
                      } else {
                     o << "" << endl;
}



return o;
}
