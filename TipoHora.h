#ifndef TIPOHORA_H 
#define	TIPOHORA_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

using namespace std;

enum TipoEstado {Pedido, Encamino, Entregado, Cancelado};

class TipoHora{
private:
	int segundos;
	int minuto;
	int hora;
public:
	TipoHora(int = 0, int = 0, int = 0);
	int getSegundos();
	int getMinuto();
	int getHora();

};

#endif
