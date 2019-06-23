#ifndef TIPOPRODUCTO_H 
#define	TIPOPRODUCTO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

using namespace std;

class TipoProducto {
	private:
		string cod;
		string descripcion;
		float precio;
	public:
		//constructor
		TipoProducto(string, string, float);
		//getters
		string getCod();
		string getDescripcion();
		float getPrecio();
		//setters
		void setCod(string);
		void setDescripcion(string);
		void setPrecio(float);
		//destructor
		virtual ~TipoProducto() = default;
};

#endif