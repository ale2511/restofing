#ifndef TIPODIRECCIONAPART_H
#define	TIPODIRECCIONAPART_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipodireccion.h"
using namespace std;

class TipoDireccionApart : public TipoDireccion {
private:
	string edificio;
	int nroapartamento;
public:
	TipoDireccionApart(string, int, string, string, string, int);
	string getEdificio();
	int getNroapartamento();
};

#endif
