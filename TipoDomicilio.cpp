#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 
#include "TipoDomicilio.h"
//#include "Repartidor.h"
using namespace std;

TipoDomicilio :: TipoDomicilio(string nombre, string celu, string venta, string direccion, TipoEstado estad){
	cliente_nombre = nombre;
	estado = estad;
	cliente_cel = celu;
        cod_venta = venta;
        direc = direccion;

      //  repartidor = NULL;
	
}


string TipoDomicilio :: getNombre(){
	return cliente_nombre;
}

TipoEstado TipoDomicilio :: getEstado(){
	return estado;
}




string TipoDomicilio :: getCelular(){
	return cliente_cel;
}

string TipoDomicilio :: getCodVenta(){
  return cod_venta;


}


string TipoDomicilio :: getDireccion(){
return direc;


}


 ostream& operator <<(ostream &o, TipoEstado &reparte){

switch (reparte) {
    case Pedido: o << "Pedido"; break;
    case Encamino: o << "Encamino"; break;
    case Cancelado: o << "Cancelado"; break;
        case Entregado: o << "Entregado"; break;
    default: o << "Función no implementada"; break;
}
 
                    



return o;
}
		

 ostream& operator <<(ostream &o, TipoDomicilio* &domicilio){
 
                    if (domicilio != NULL){
                    o << "Numero de venta: " << domicilio->getCodVenta() << "/" << "Nombre Cliente : " << domicilio->getNombre() << " / " << "Celular: " << domicilio->getCelular() << " / " << domicilio->getDireccion() << endl;
   
                      } else{
                     o << " " << endl;
}



return o;
}
		
