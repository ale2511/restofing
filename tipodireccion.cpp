#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipodireccion.h"
using namespace std;

TipoDireccion :: TipoDireccion(string road, int nro, string calle1, string calle2){
   calle = road;
   nrocalle = nro;
   entrecalle1 = calle1;
   entrecalle2 = calle2;    

}

string TipoDireccion :: getCalle(){
   return calle;
}

int TipoDireccion :: getNrocalle(){
	return nrocalle;
}

string TipoDireccion :: getEntrecalle1(){
	return entrecalle1;
}

string TipoDireccion :: getEntrecalle2(){
	return entrecalle2;
}