#ifndef _CONTREMPLEADO_H
#define	_CONTREMPLEADO_H

#include <string>
#include <cstdlib>
#include "tipoactualizacion.h"
#include <iostream>
#include <map>
#include <set> 
#include <cmath>
#include <ctime>
#include "ContrVenta.h"
#include "iAltaEmpleado.h"
#include "iAsignarMozosAMesas.h"
#include "iIniciarVentaEnMesas.h"
#include "iModificarEstadoPedido.h"
#include "TipoEmpleado.h"
using namespace std; 


class ContrVenta;

class ContrEmpleado : public IAltaEmpleado, public IAsignarMozosAMesas, public IIniciarVentaEnMesas, public IModificarEstadoPedido {
	private:
		static ContrEmpleado * instancia;
		ContrEmpleado(){};
		map <int, Empleado*> CEmpleado;
		map <int,Mozo*> CMozo;
		map <int,Repartidor*> CRepartidor;
		map <int, Mesa*> CMesa;
		string nombreEmpleado;
		int vehiculo;
		set<int> eleccionMesaMozo;
		int nroEmpleado;
		string codVenta;
		int nroEstado;
	public:
	  void guardarVentaRepartidor(int, Domicilio*);
		static ContrEmpleado * getInstance();
		int getNroMesa(Mesa*);
		int getNroMozo(int);
		string getNombreMozo(int);
		//getters
		string getNombreEmpleado();
		int getVehiculo();
		string getCodVenta();
		int getNroEstado();
		int getNroEmpleado();
		//setters
		void setNombreEmpleado(string);
		void setVehiculo(int);
		void setCodVenta(string);
		void setNroEstado(int);
		void setNroEmpleado(int);
		void AgregarMozo(Mozo*);
        void AgregarRepartidor(Repartidor*);
        void AgregarMesa(Mesa*);
		//Alta Empleado
		void  ingresarNombre(string);
		set <TipoTransporte> DarTransporte();
		void ingresarTransporte(int);
		void ConfirmarEmpleado(bool);
		//Asignar Mozos a Mesas
		set <TipoMesaMozo*> AsignarMozoMesas();
		//Iniciar Venta en Mesas
		set <TipoMesa*> VerMesasMozo(int);
		void ElegirMesaMozo(set<int>);
		void ConfirmarVentaEnMesa();
		//Modificar Estado Pedido
		bool existeVentaDom(string);
		set <TipoEstado> ingrPedido(string);
		void elegirEstado(int);
		void confirmarNuevoEstado();
		TipoFactura * facturar(float);
		set<TipoMozo*> VerMozos();
		set<TipoRepartidor*> VerRepartidores();
		void CambiarEstado(set<int>, int);
		TipoRepartidor* obtenerTipoRepartidor(int);
		TipoMozo* obtenerTipoMozo(int);
		void crearmesa(int);
		void VaciarMesas();
};

#endif

