#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "cantProdMenu.h"
#include "menu.h"
using namespace std;

//constructor

Menu :: Menu(string miCod, string miDescripcion) : ProdGral(miCod, miDescripcion) {
	setPrecio(0);
	map <string, CantProdMenu *> cpm;
}

//getter

map <string, CantProdMenu *> Menu :: getCPM() {
	return cpm;
}

//setter

void Menu :: setCPM(map <string, CantProdMenu *> unCPM) {
	cpm = unCPM;
}

//resto de operaciones

void Menu :: nuevoCantProdMenu(string codigo, int cantidad, Simple * s) {
	CantProdMenu * pm = new CantProdMenu(cantidad, s);
	cpm[codigo] = pm;
	//actualizo el precio del menu
	float p = getPrecio() + (s->getPrecio()* cantidad * 0.9);
	setPrecio(p);
}

TipoProducto * Menu :: darDatosProd() {
	set <TipoCantProdMenu *> conjSim;
	map <string, CantProdMenu *> :: iterator it;
	Simple * s;
	for (it = cpm.begin(); it != cpm.end(); ++it) {
		s = it->second->getSimple();
		TipoProducto * tp = s->darDatosProd();
		TipoSimple * ts = dynamic_cast<TipoSimple*>(tp);
		if (ts != NULL) {
			TipoCantProdMenu * tcpm = new TipoCantProdMenu(it->second->getCant(), ts);
			conjSim.insert(tcpm);
		}
	}
	TipoMenu * m = new TipoMenu(getCod(), getDescripcion(), getPrecio(), conjSim);
	return m;
}

void Menu :: reCalcularPrecio(Simple * s, int cant) {
	float p = getPrecio() - (s->getPrecio() * cant * 0.9);
	if (p < 0)
		p = 0;
	setPrecio(p);
}

bool Menu :: vaciadoMenu(Simple * s) {
	bool vacio = true;
	bool hayS = false;
	map <string, CantProdMenu *> :: iterator it;
	it = cpm.begin();
	while ((! hayS) && (it != cpm.end())) {
		hayS = it->second->contiene(s);
		if (hayS) {
			CantProdMenu * aBorrar = it->second;
			cpm.erase(it->first);
			aBorrar->~CantProdMenu();
			reCalcularPrecio(s, it->second->getCant());
		};
		vacio = cpm.empty();
		++it;
	};
	return vacio;
}

void Menu :: elimMenu() {
	map <string, CantProdMenu *> :: iterator it;
	CantProdMenu * aBorrar;
	for(it = cpm.begin(); it != cpm.end(); ++it) {
		aBorrar = it->second;
		cpm.erase(it->first);
		aBorrar->~CantProdMenu();
	}
}