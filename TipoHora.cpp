#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "TipoHora.h"
using namespace std;

TipoHora :: TipoHora(int seg, int min, int hour){
	segundos = seg;
	minuto = min;
	hora = hour;
}

int TipoHora :: getSegundos(){
	return segundos;
}

int TipoHora :: getMinuto(){
	return minuto;
}

int TipoHora :: getHora(){
	return hora;
}
