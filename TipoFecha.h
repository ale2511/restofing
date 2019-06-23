#ifndef TIPOFECHA_H 
#define	TIPOFECHA_H

#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class TipoFecha {
private:
	int dia, mes, anio;
public:
	TipoFecha(int = 0, int = 0, int = 0);
	int getdia();
	int getmes();
	int getanio();
};

#endif
