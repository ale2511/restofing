#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoSimple.h"
#include "tipoCantProdMenu.h"
using namespace std;

//constructor

TipoCantProdMenu :: TipoCantProdMenu(int miCant, TipoSimple * miTipoS) {
	cant = miCant;
	tipoS = miTipoS;
}

//getters

int TipoCantProdMenu :: getCant() {
	return cant;
}

TipoSimple * TipoCantProdMenu :: getTipoS() {
	return tipoS;
}

//setters

void TipoCantProdMenu :: setCant(int unaCant) {
	cant = unaCant;
}

void TipoCantProdMenu :: setTipoS(TipoSimple * unTipoS) {
	tipoS = unTipoS;
}