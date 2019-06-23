#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipodireccion.h"
#include "TipoDireccionApart.h"
using namespace std;

TipoDireccionApart :: TipoDireccionApart(string road, int nro, string calle1, string calle2, string edif, int nroedif) : TipoDireccion(road, nro, calle1, calle2){
	edificio = edif;
	nroapartamento = nroedif;
}

string TipoDireccionApart :: getEdificio(){
	return edificio;
}

int TipoDireccionApart :: getNroapartamento(){
	return nroapartamento;
}