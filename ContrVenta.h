#ifndef CONTRVENTA_H 
#define	CONTRVENTA_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "contrProducto.h"
#include "ContrEmpleado.h"
#include "iAgregarProductoAUnaVenta.h"
#include "iQuitarProductoAUnaVenta.h"
#include "iFacturacionDeUnaVenta.h"
#include "IVentaADomicilio.h"
#include "IFacturacionDeUnDia.h"
#include "iConsultarPedidoCliente.h"
#include "iConsultarPedidoAdmin.h"
#include "Venta.h"


using namespace std;

class ContrEmpleado;
class ContrProducto;

class ContrVenta : public IAgregarProductoAUnaVenta, public IQuitarProductoAUnaVenta, public IFacturacionDeUnaVenta, public IVentaADomicilio, public IFacturacionDeUnDia, public IConsultarPedidoCliente, public IConsultarPedidoAdmin {
	private:
	static ContrVenta * instancia;
	ContrVenta();
	map <string, Venta *> ventas;
	map <string, Local *> locales;
	map <string, Factura *> facturas;
	map <string, Cliente *> clientes;
	map <string, Domicilio *> domicilios;
	set<TipoActualizacion*> actualizaciones;
	int nroMesa;
	string cod;
	int cant;
	string prod;
	string ventilla;
	float IVA;
	string nombre;
	string telefono;
	TipoDireccion * direccion;
	int sumadorcodventa;
	int repartidorcillo;
	//ContrEmpleado * ce;
	//ContrProducto * pe;
	
	public:
	static ContrVenta* getInstance();
	//getters
	void imprimirAct();
	float getIVA();
	int getnroMesa();
	string getcod();
	int getcant();
	string getprod();
	string getventa();
	string getNombre();
	string getTelefono();
	TipoDireccion * getDireccion();
	string getSumador();
	int getRepartidor();
	bool localEsVacia();
	
	map <string, Domicilio *> getDomicilios();
	
	//setters
	void setnroMesa(int);
	void setcod(string);
	void setcant(int);
	void setprod(string);
	void setventa(string);
	void setNombre(string);
	void setTelefono(string);
	void setDireccion(TipoDireccion*);
	void setSumador();
	void setRepartidor(int);
	void AgregarVenta(Venta*);
	void AgregarCliente(Cliente*);
	void AgregarLocal(Local*);
	void AgregarMensaje(TipoActualizacion*);
	void AgregarFactura(Factura*);
	//funciones sistema
	set<TipoCantProducto*> FacturaATipoCantProducto (Factura *);
	bool ventaNoFacturada(int);
	set <TipoProducto *> darProds();
	bool ingProds(string, int);
	void confirmarAgregarProducto();
	set <TipoProducto *> verProdsVenta();
	bool prodAEliminar(string, int);
	void confirmarQuitarProdVenta();
	TipoFactura * facturar(float);
	set <TipoMozo *> verMozos();
	set <TipoFactura *> verFacturasMozo(int, TipoFecha *, TipoFecha *);
	set <TipoFactura *> verFacturasFecha(TipoFecha *);
	void datosCliente(string, TipoDireccion *);
	void confirmarAgregarCliente(bool);
	bool noHayCliente(string);
	void iniciarVentaEnMesas(set<Mesa*>, int);
	void iniciarVentaDomicilio();
	void confirmarProductoEnDomicilio();
	set <TipoRepartidor *> verRepartidores();
	void elegirRepartidor(int);
	void inicializarEstado(int);
	TipoActualizacion * ConfirmarMensaje();
	set<TipoActualizacion*> ListarActualizaciones();
	set<TipoActualizacion*> ListarActualizacionesSistema();
	
	TipoCantProducto * obtenerTCPFact(string, TipoProducto *);
	TipoFecha * hacedorFecha(int, int, int);
	bool noHayVenta(string);
	TipoDireccion * hacedorDir(string, int, string, string);
	TipoDireccionApart * hacedorApar(string, int, string, string, string, int);
	bool recibeMensajes();
	bool compareFechas(TipoFecha *, TipoFecha *);
	bool fechasIguales(TipoFecha *, TipoFecha *);
	bool compareHoras(TipoHora *, TipoHora *);
	bool existeVentaDom(string);
};

#endif
