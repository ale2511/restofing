#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "simple.h"
#include "cantProdMenu.h"
using namespace std;

//constructor

CantProdMenu :: CantProdMenu(int miCant, Simple * miSimple) {
	cant = miCant;
	simple = miSimple;
}

//getters

int CantProdMenu :: getCant() {
	return cant;
}

Simple * CantProdMenu :: getSimple() {
	return simple;
}

//setters

void CantProdMenu :: setCant(int unaCant) {
	cant = unaCant;
}

void CantProdMenu :: setSimple(Simple * unSimple) {
	simple = unSimple;
}

//resto de operaciones

bool CantProdMenu :: contiene(Simple * algunSimple) {
	return simple == algunSimple;
}