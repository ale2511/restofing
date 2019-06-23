#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "TipoHora.h"
#include "TipoFecha.h"
#include "tipoCantProducto.h"
#include "tipoactualizacion.h"
using namespace std;



TipoActualizacion :: TipoActualizacion(TipoHora * horita, TipoFecha * fechita, string repartidor, string cliente, set<TipoCantProducto*> lospedidos, string tel, TipoEstado elestado){
	hora = horita;
	fecha = fechita;
	nombrerepartidor = repartidor;
	nombrecliente = cliente;
	pedido = lospedidos;
	telefono = tel;
	estado = elestado;
}

TipoHora * TipoActualizacion :: getHora(){
	return hora;
}

TipoFecha * TipoActualizacion :: getFecha(){
	return fecha;
}

string TipoActualizacion :: getNombrerepartidor(){
	return nombrerepartidor;
}

string TipoActualizacion :: getNombrecliente(){
	return nombrecliente;
}

set<TipoCantProducto*> TipoActualizacion :: getPedido(){
	return pedido;
}

TipoEstado TipoActualizacion :: getEstado(){
	return estado;
}

string TipoActualizacion :: getTelefono(){
	return telefono;
}
