#ifndef TIPODIRECCION_H
#define TIPODIRECCION_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

using namespace std;

class TipoDireccion {
private:
	string calle;
	int nrocalle;
	string entrecalle1;
	string entrecalle2;
public:
	TipoDireccion(string, int, string, string);
	TipoDireccion(){};
	string getCalle();
	int getNrocalle();
	string getEntrecalle1();
	string getEntrecalle2();
};

#endif