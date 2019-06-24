#include <cstdlib>
#include <string>
#include <iostream>
#include "factory.h"

#include <set>
#include <map>
#include <time.h>
using namespace std; 

Factory *fabrica=Factory::getInstance();
IAltaProducto * AP=fabrica->getIAltaProducto();
IInformacionDeUnProducto * infoproducto=fabrica->getIInformacionDeUnProducto();
IAsignarMozosAMesas * IM = fabrica->getIAsignarMozosAMesas();
IAltaEmpleado * AE = fabrica->getIAltaEmpleado();
IBajaProducto * BP = fabrica->getIBajaProducto();
IFacturacionDeUnaVenta * factventa = fabrica->getIFacturacionDeUnaVenta();
IAgregarProductoAUnaVenta * altaprodventa=fabrica->getIAgregarProductoAUnaVenta();
IQuitarProductoAUnaVenta * bajaprodventa=fabrica->getIQuitarProductoAUnaVenta();
IIniciarVentaEnMesas * iniciarv = fabrica->getIIniciarVentaEnMesas();
IFacturacionDeUnDia * factfecha=fabrica->getIFacturacionDeUnDia();
IConsultarPedidoCliente * CPC = fabrica->getIConsultarPedidoCliente();
IConsultarPedidoAdmin * CPA = fabrica->getIConsultarPedidoAdmin();
IModificarEstadoPedido *MEP = fabrica->getIModificarEstadoPedido();
IVentaADomicilio * vdom = fabrica->getIVentaADomicilio();


void imprimirFactura(TipoFactura);
void AltaProd();
void InfProd();
void BajaProd();
void AltaEmpleado();
void AsigMozoMesa();
void IniciarVenMesa();
void AgregarProdVenta();
void QuitarProdVenta();
void FactVenta();
void ResFactFecha();
void VentaDomicilio();
void ModificarEstado();
void ConsultarActualizacionesCliente();
void ConsultarActualizacionesAdministrador();
void CargarDatos();


void imprimirProducto(TipoProducto * tp) {
	TipoSimple * ts = dynamic_cast<TipoSimple*>(tp);
	if (ts != NULL) {
		cout << "Codigo del producto: " << ts->getCod() << '\n';
		cout << "Descripcion: " << ts->getDescripcion() << '\n';
		cout << "Precio: " << ts->getPrecio() << '\n';
		cout << '\n';
		cout << "-------" << "\n" << '\n';
	} else {
		TipoMenu * tm = dynamic_cast<TipoMenu*>(tp);
		cout << "Codigo del menu: " << tm->getCod() << '\n';
		cout << "Descripcion: " << tm->getDescripcion() << '\n';
		cout << "Precio: " << tm->getPrecio() << '\n';
		cout << "Productos Simples: " << '\n';
		set <TipoCantProdMenu *> tcp = tm->getProds();
		set <TipoCantProdMenu *> :: iterator it1;
		for (it1 = tcp.begin(); it1 != tcp.end(); ++it1) {
			TipoCantProdMenu * current1 = *it1;
			TipoSimple * s = current1->getTipoS();
			cout << "Codigo Simple: " << s->getCod() << '\n';
			cout << "Descripcion Simple: " << s->getDescripcion() << '\n';
			cout << "Precio Simple: " << s->getPrecio() << '\n';
			cout << "Cantidad: " << current1->getCant() << '\n';
		}
		cout << '\n';
		cout << "-------" << "\n";	
	}
}


void imprimirSetProds(set <TipoProducto *> stp) {
	set <TipoProducto *> :: iterator it;
	for (it = stp.begin(); it != stp.end(); ++it) {
		TipoProducto * current = *it;
		imprimirProducto(current);
	}
}


void imprimirCantProducto(TipoCantProducto * tcp) {
	cout << "Cantidad del Producto Vendida: " << tcp->getCant() << '\n';
	imprimirProducto(tcp->getTipoProducto());
	cout << '\n';
}


/*
void ImprimirProductos(set<TipoProducto*> prods) {
	set<TipoProducto*> :: iterator it;
	for (it = prods.begin(); it != prods.end(); ++it) {
		TipoProducto* producto = *it;
		TipoSimple* simple = dynamic_cast<TipoSimple*>(producto);
		if (simple != NULL) {
			cout << simple << endl;
		} else {
			TipoMenu* menu = dynamic_cast<TipoMenu*>(producto);
			cout << menu << endl;
		}
	}
}*/
//enum TipoTransporte {Pie,Bicicleta,Moto};

void imprimirTransporte(TipoTransporte t) {
	if (t == Pie)
		cout << "A Pie" << '\n';;
	if (t == Bicicleta)
		cout << "Bicicleta" << '\n';
	if (t == Moto)
		cout << "Moto" << '\n';
}

void imprimirFactura(TipoFactura * tf) {
	cout << "Numero de factura: " << tf->getNrofactura() << '\n';
	cout << '\n';
	set<TipoCantProducto*> cp = tf->getProductos();
	set <TipoCantProducto *> :: iterator it;
	for (it = cp.begin(); it != cp.end(); ++it) {
		TipoCantProducto * current = *it;
		imprimirCantProducto(current);
		cout << '\n';
	}
	cout << '\n';
	
	TipoFecha* fechita = tf->getFecha();
	cout << "Fecha: " << fechita->getdia() <<"/" << fechita->getmes() <<"/" << fechita->getanio() << '\n';
	
	TipoHora* horita = tf->getHora();
	cout << "Hora: " << horita->getHora() <<" : " << horita->getMinuto() <<" : " << horita->getSegundos() << '\n';
	cout << '\n';
	cout << "Subtotal : " << tf->getSubtotal() << '\n';
	cout << "Descuento : " << tf->getDescuento() << '\n'; //en facturar, si no aplica el descuento poner 0;
	cout << "Total sin IVA: " << tf->getPreciosiniva() << '\n';
	cout << "Total : " << tf->getTotal() << '\n';
	cout << '\n';
	
	TipoEmpleado * te = tf->getEmpleado();
	
	cout << "Atendido por: " << te->getNombre() << '\n';
	
		TipoRepartidor * tr = NULL;
		tr = dynamic_cast<TipoRepartidor*>(te);
	if (tr != NULL) {
		TipoTransporte tp = tr->getTransporte();
		cout << "Medio de transporte: ";
		imprimirTransporte(tp);
		cout << '\n';
	}
}

void imprimirEstado(TipoEstado e) {
	if (e == Pedido)
		cout << "Estado: Pedido" << '\n';;
	if (e == Encamino)
		cout << "Estado: En Camino" << '\n';
	if (e == Entregado)
		cout << "Estado: Entregado" << '\n';
	if (e == Cancelado)
		cout << "Estado: Cancelado" << '\n';
}

void imprimirTipoAct(TipoActualizacion * ta) {
  cout << "INFORMACION DE ACTUALIZACION:" << endl;
  cout << "-----------------------------------" << endl;
  if (ta!=NULL)
  {
  	TipoHora * hora = ta->getHora();
	cout << "Hora: " << hora->getHora() << ":" << hora->getMinuto() << ":" << hora->getSegundos() << '\n';
	TipoFecha * fecha = ta->getFecha();
	cout << "Fecha: " << fecha->getdia() << "/" << fecha->getmes() << "/" << fecha->getanio() << '\n';
	string nombreR = ta->getNombrerepartidor();
	cout << "Nombre del repartidor: " << nombreR << '\n';
	string nombreC = ta->getNombrecliente();
	cout << "Nombre del cliente: " << nombreC << '\n';
	set<TipoCantProducto*> tcp = ta->getPedido();
	set<TipoCantProducto*> :: iterator it;
	for (it = tcp.begin(); it != tcp.end(); ++it) {
		TipoCantProducto * current = *it;
		imprimirCantProducto(current);
	}	
	string tel = ta->getTelefono();
	cout << "Telefono del cliente: " << tel << '\n';
	TipoEstado estado = ta->getEstado();
	imprimirEstado(estado);
}else
cout << "Vacio"<<"\n";}



void repartidores() {
    set<TipoRepartidor*> mover = AE->VerRepartidores();
    set<TipoRepartidor*> :: iterator it;
    for (it = mover.begin(); it != mover.end(); ++it) {
		TipoRepartidor* rep = *it;
     	cout << rep << endl;
    }
}


void imprimirMozos(){
	set<TipoMozo*> mozosImprimir = AE->VerMozos();
	set<TipoMozo*> :: iterator it;
	for (it = mozosImprimir.begin(); it != mozosImprimir.end(); ++it) {
		TipoMozo* mozi = *it;
		cout << mozi << endl;
	}
}



void AltaProd() {
	try { 
		string eleccion, sPrecio, sCantSim, codProd, descripcion, codSim, sConfirmar;
		bool simple,masSimples,hs,nhc,masProductos;
		int cantSim;
		float precio;
		masProductos = true;
		while (masProductos) {
			AP->borrarPares();
			hs = AP->hayProdSim();
			cout << "Ingrese el codigo del producto a agregar\n" << '\n';
			cin >> codProd;
			nhc = AP->noHayCodigo(codProd);
			if (nhc) {
				cout << "¿Desea ingresar un Producto Simple (ingrese '1') o un Menu (ingrese '2')?\n" << '\n';
				cin >> eleccion;
				if (!eleccion.compare("1")) {
					simple = true;
					cout << "Ingrese la descripcion del producto\n" << '\n';
					cin.ignore(1,'\n');
					fflush(stdin); getline(std::cin,descripcion);
					cout << "Ingrese el precio del producto\n" << '\n';
					cin >> sPrecio;
					precio = stoi(sPrecio);
					if (precio < 0)
						throw "El precio no puede ser negativo\n";
					AP->datosProdSim(descripcion, precio);
				} else if (!eleccion.compare("2")) {
					if (hs) {
						simple = false;
						cout << "Ingrese la descripcion del producto\n" << '\n';
						std::fflush(stdin); getline(std::cin, descripcion);
						AP->datosProdMenu(descripcion);
						cout << AP->darProdSim();
						cout << "Ahora ingrese los codigos y cantidades de los productos para su menu\n" << '\n';
						masSimples = true;
						while (masSimples) {
							cout << "Codigo: ";
							cin >> codSim;
							if (!(AP->haySimple(codSim)))
								throw "El codigo ingresado no existe\n";
							cout << "Cantidad: ";
							cin >> sCantSim;
							cantSim = stoi(sCantSim);
							if (cantSim <= 0)
								throw "La cantidad debe ser mayor a 0\n";
							AP->ingrProdSim(codSim, cantSim);
							cout << "¿Desea agregar mas productos al menu? (Escriba 'Y' o 'N')\n" << '\n';
							do {
								cin >> sConfirmar;
								if (!sConfirmar.compare("N"))
									masSimples = false;
								else if (sConfirmar != "Y")
									cout << "Opcion no valida. Por favor, ingrese 'Y' o 'N'" << '\n';
							} while ((sConfirmar != "Y") && (sConfirmar != "N"));
						}
					} else
						throw "No puede ingresar un menu porque no existen productos simples en el sistema\n";
				} else
					throw "Opcion no valida";
				cout << "¿Desea agregar este producto? (Escriba 'Y' o 'N')\n" << '\n';
				do {
					cin >> sConfirmar;
					if (!sConfirmar.compare("Y")) {
						AP->confirmarAltaProd(simple);
						cout << "Producto ingresado con exito" << '\n' << '\n';
					} else if (sConfirmar != "N")
						cout << "Opcion no valida. Por favor, ingrese 'Y' o 'N'" << '\n';
				} while ((sConfirmar != "Y") && (sConfirmar != "N"));
			} else {
				cout << "Este codigo ya existe, intente de nuevo" << '\n';
			}
			cout << "¿Desea ingresar mas productos al sistema? (Escriba 'Y' o 'N')\n" << '\n';
			do {
				cin >> sConfirmar;
				if (!sConfirmar.compare("N"))
					masProductos = false;
				else if (sConfirmar != "Y")
					cout << "Opcion no valida. Por favor, ingrese 'Y' o 'N'" << '\n';
			} while ((sConfirmar != "Y") && (sConfirmar != "N"));
		}
	}
	catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void InfProd() {
	try {
		string elect;
		bool bandera = true;
		set <TipoProducto *> stp = infoproducto->darProds();
		imprimirSetProds(stp);
		//ImprimirProductos(stp);
		//cout << stp << '\n';
		do {                                                         
			cout << "Elija el codigo de producto" << "\n";
			cin >> elect;
			if (infoproducto->productoValido(elect)) {
				bandera=false;
				//cout << infoproducto->verInfoProducto();
				TipoCantProducto * tcp = infoproducto->verInfoProducto();
				imprimirCantProducto(tcp);
			} else {
				cout << "Codigo incorrecto!!"<< "\n";
				cout << "Precione 0 para salir, 1 para intentar de nuevo"<< "\n";
				do {
					cin >>bandera;
					if ((bandera != 0) && (bandera != 1))
						cout << "Opcion no valida. Por favor, ingrese '0' o '1'" << '\n';
				} while ((bandera != 0) && (bandera != 1));
			}
		} while(bandera);
	}
	catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void BajaProd() {
	try {
		bool hp,pv, nv ;
		string codProd;
		hp = BP->hayProducto();
		if (hp) {
			set <TipoProducto *> stp = BP->darProds();
			imprimirSetProds(stp);
			//ImprimirProductos(stp);
			//cout << stp << '\n';
			cout << "Ahora ingrese el codigo del producto a eliminar\n" << '\n';
			cin >> codProd;
			pv = BP->productoValido(codProd);
			if (!pv)
				throw "El codigo ingresado no existe\n";
			nv = BP->noHayVenta(codProd);
			if (!nv)
				throw "Este codigo representa a un producto asociado a una venta, no se puede eliminar\n";
			BP->confirmarBajaProd();
			cout << "El producto fue borrado con exito" << '\n' << '\n';;
		} else
			throw "No puede eliminar productos porque no existe ninguno en el sistema\n";
	}
	catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void AltaEmpleado() {
	try {
		string nombre,opcion,cancelar;
		string que;
		int veh;
		set<TipoTransporte> :: iterator it;
		cout << "Desea agregar:" << endl;
		cout << "Mozo (1)" << endl;
		cout << "Repartidor(2)" << endl;
		cin >> opcion;
		if (!opcion.compare("1")) {
			cout << "Nombre del mozo?" << endl;	
			cin.ignore(1,'\n');
			fflush(stdin); 
			getline(std::cin,nombre);
            cout << "Confirmar (1)" << endl;
            cout << "Cancelar (0)" << endl;
            cin >> cancelar;
            if (!cancelar.compare("1")) {
				AE->setNombreEmpleado(nombre);
                AE->ConfirmarEmpleado(true);
			} 
		} else if (!opcion.compare("2")) {
			cout << "Ingrese nombre de Repartidor" << endl;
			//fflush(stdin);
			cin.ignore(1,'\n');
			fflush(stdin); 
			getline(std::cin,nombre);
			AE->setNombreEmpleado(nombre);
			cout << "Elija medio de transporte:" << endl;
			set<TipoTransporte> t = AE->DarTransporte();
			cout << "Pie (0)" << endl;
			cout << "Bicicleta(1)" << endl;
			cout << "Moto(2)" << endl;
			do {
				cin >> que;
				if ((que != "0") && (que != "1") && (que != "2"))
					cout << "Por favor, ingrese '0', '1' o '2'" << '\n';
			} while ((que != "0") && (que != "1") && (que != "2"));
			veh = stoi(que);
			AE->setVehiculo(veh);
			cout << "Desea confirmar?" << endl;
			cout << "Confirmar (1)" << endl;
			cout << "Cancelar (0)" << endl; 
			cin >> cancelar;
			if(!cancelar.compare("1")) {
				AE->ConfirmarEmpleado(false);
			} 
		} else {
			throw "Error";
		}			
	} catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void AsigMozoMesa() {
	set<TipoMesaMozo*> mesas= IM->AsignarMozoMesas();
	set<TipoMesaMozo*> :: iterator it;
	for (it = mesas.begin(); it != mesas.end(); ++it) { 
		TipoMesaMozo* mesita = *it;
		cout << mesita;
	}
}

void IniciarVenMesa() {
	try {
		bool juira,quieraseguiragregando, salirbool, seconfirma;
		string NewYork;
		int nromozo, mesilla;
		cout << "Ingrese el numero de mozo"<<"\n";
		cin >> nromozo;
		set<TipoMesa*> lasmesas = iniciarv->VerMesasMozo(nromozo);
		juira = true;
		while (lasmesas.empty() && juira) {
			cout << "Ingrese el numero de mozo correcto, o -1 para salir"<<"\n";
			cin >> nromozo;
			lasmesas = iniciarv->VerMesasMozo(nromozo);
			if (nromozo == -1)
				juira = false;
		}
		if (!lasmesas.empty()) {
		  iniciarv->setNroEmpleado(nromozo);	
			quieraseguiragregando = true;
			cout << "Mesas libres del mozo: " << endl;
			set<TipoMesa*> :: iterator movermesa;
			for (movermesa = lasmesas.begin(); movermesa != lasmesas.end(); ++movermesa) {
				TipoMesa* mes = *movermesa;
				cout << mes << endl;
			}
			cout << "--------------------" << endl;
			set<int> result;	
			while (quieraseguiragregando) {
				cout << "Ingrese numero de mesa"<<"\n";
				cin >> mesilla;
				while (mesilla < 0) {
					cout << "Ingrese numero de mesa positivo"<<"\n";
					cin >> mesilla;
				}
				result.insert(mesilla);
				cout << "¿Desea agregar otra mesa?: No(N) o Si(Y)" << "\n";
				cin >> NewYork;
				salirbool = false;
				while (!salirbool) {
					if (NewYork == "N") {
						salirbool = true;
						quieraseguiragregando = false;
					} else if (NewYork == "Y") {
						salirbool = true;
					} else {
						salirbool = false;
						cout << "No(N) o Si(Y)" << "\n";
						cin >> NewYork;
					}
				}
				
			}
			iniciarv->ElegirMesaMozo(result); //deberia chqeuear si son mesas elegibles
			set<int> :: iterator it;
			cout << "Se ingresarán las siguientes mesas" << "\n";
			for (it = result.begin(); it != result.end(); ++it) {
				cout << *it << "\n";
			}
			cout << "\n";
			cout << "¿Confirma? No(N) o Si(Y)" << "\n";
			cin >> NewYork;
			salirbool = false;
			seconfirma = false;
			while (!salirbool) {
				if (NewYork == "N") {
					salirbool = true;
				} else if (NewYork == "Y") {
					salirbool = true;
					seconfirma = true;
				} else {
					salirbool = false;
					cout << "No(N) o Si(Y)" << "\n";
					cin >> NewYork;
				}
			}
			if (seconfirma) {
				iniciarv->ConfirmarVentaEnMesa();
				cout << "Confirmado" << "\n";
			} else {
				cout << "Se cancela la operación" << "\n";
			}
		}
	} catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void AgregarProdVenta() {
	try {
		int mesilla, cant, elec, seguir;
		bool vnf, existe;
		string cod;
		cout << "Ingrese codigo de Mesa"<<"\n";
		cin >> mesilla;
		vnf=altaprodventa->ventaNoFacturada(mesilla);
		seguir = -1;
		while (!vnf && (seguir == -1)) {
			cout << "Codigo de Mesa Facturada o incorrecto"<<"\n";
			cout << "Ingrese codigo de Mesa"<<"\n";
			cout << "Para salir presione ingrese -1"<<"\n";
			cin >> mesilla;
			vnf=altaprodventa->ventaNoFacturada(mesilla);
			if (mesilla == -1)
				seguir = 0;
		}
		if (seguir != 0) {
			do {
				if (vnf) {
					set<TipoProducto*> listaproductos = altaprodventa->darProds();
					//ImprimirProductos(listaproductos);
					imprimirSetProds(listaproductos);
					cout << "Ingrese el código de uno de los productos mostrados anteriormente"<<"\n";
					cin >> cod;			
					cout << "Ingrese la cantidad de dicho producto a agregar"<<"\n";
					cin >> cant;
					while (cant <= 0) {
						cout << "Ingrese una cantidad positiva"<<"\n";
						cin >> cant;
					}
					existe = altaprodventa->ingProds(cod, cant);
					while (!existe) {
						cout << "Ingrese un codigo valido"<<"\n";
						cin >> cod;
						existe = altaprodventa->ingProds(cod, cant);
					}
					cout << "Agregar el producto de codigo "<< cod <<" con cantidad "<< cant <<" a la mesa "<< mesilla <<"\n";
					cout << "Presione 1 para confirmar, o 0 para desistir"<<"\n";
					cin >> elec;
					if (elec == 1) {
						altaprodventa->confirmarAgregarProducto();
					}
				}
				cout << "Presione 0 para salir, presione 1 para continuar agregando" << '\n';
				cin >> seguir;
			} while(seguir!=0);
		}
	} catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void QuitarProdVenta() {
	try {
		int mesilla, cant, elec, seguir;
		bool vnf, existe;
		string cod;
		cout << "Ingrese codigo de Mesa"<<"\n";
		cin >> mesilla;
		vnf=bajaprodventa->ventaNoFacturada(mesilla);
		seguir = -1;
		while (!vnf && (seguir == -1)) {
			cout << "Codigo de Mesa Facturada o incorrecto"<<"\n";
			cout << "Ingrese codigo de Mesa"<<"\n";
			cout << "Para salir presione ingrese -1"<<"\n";
			cin >> mesilla;
			vnf=bajaprodventa->ventaNoFacturada(mesilla);
			if (mesilla == -1)
				seguir = 0;
		}
		if (seguir != 0) {
			do {
				if (vnf) {
					set<TipoProducto*> prods = bajaprodventa->verProdsVenta();
					//ImprimirProductos(prods);
					imprimirSetProds(prods);
					cout << "Ingrese el código de uno de los productos mostrados anteriormente para eliminarlo"<<"\n";
					cin >> cod;
					cout << "Ingrese la cantidad de dicho producto a eliminar"<<"\n";
					cin >> cant;
					while (cant <= 0) {
						cout << "Ingrese una cantidad positiva y no mayor a la que contiene la venta"<<"\n";
						cin >> cant;
					}
					existe = bajaprodventa->prodAEliminar(cod, cant);
					while (!existe) {
						cout << "Ingrese un codigo valido de un producto de la venta"<<"\n";
						cin >> cod;
						cout << "Ingrese una cantidad positiva y no mayor a la que contiene la venta "<<"\n";
						cin >> cant;
						existe = bajaprodventa->prodAEliminar(cod, cant);
					}
					cout << "Quitar el producto de codigo "<< cod <<" con cantidad "<< cant <<" a la mesa "<< mesilla <<"\n";
					cout << "Presione 1 para confirmar, o 0 para desistir"<<"\n";
					cin >> elec;
					if (elec == 1) {
						bajaprodventa->confirmarQuitarProdVenta();
					}
				}
				cout << "Presione 0 para salir, presione 1 para continuar quitando" << '\n';
				cin >> seguir;
			} while(seguir!=0);
		}
	} catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void FactVenta() {
	try {
		bool vnf;
		float descuentazo;
		int mesilla,salir;
		salir=0;
		cout << "Ingrese codigo de Mesa"<<"\n";
		cin >> mesilla;
		vnf=factventa->ventaNoFacturada(mesilla);
		while (!vnf&&!salir) {
			cout << "Codigo de Mesa Facturada o incorrecto"<<"\n";
			cout << "¿Desea salir? si-1 no-0"<<"\n";
			cin >> salir;
			if (!salir)
			{
			cout << "Ingrese codigo de Mesa"<<"\n";
			cin >> mesilla;
			vnf=factventa->ventaNoFacturada(mesilla);
		    }
		}
		if (vnf&&!salir) {
			cout << "Ingrese el numero de porcentaje de descuento (sin %, solo numero)"<<"\n";
			cout << "Solo se aplicará de no haber menus en la venta"<<"\n";
			cin >> descuentazo;
			while (descuentazo < 0) {
				cout << "Ingrese un descuento no negativo"<<"\n";
				cin >> descuentazo;
			}
			TipoFactura * lafactura = factventa->facturar(descuentazo);
			imprimirFactura(lafactura);
			cout << "¡Facturado!"<<"\n";
		}
	} catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void ResFactFecha() {
	try {
		int a, m, d;
		cout << "Ingrese el numero de anio"<<"\n";
		cin >> a;
		cout << "Ingrese el numero de mes"<<"\n";
		cin >> m;
		while ((m < 1) || (12<m)) {
			cout << "Ingrese el numero de mes adecuado: 1,2,3,4,5,6,7,8,9,10,11 o 12"<<"\n";
			cin >> m;
		}
		cout << "Ingrese el numero de dia"<<"\n";
		cin >> d;
		while ((d < 1) || (31<d)) {
			cout << "Ingrese el numero de dia adecuado: desde 1 hasta 31"<<"\n";
			cin >> d;
		}
		TipoFecha * tf = factfecha->hacedorFecha(a, m, d);
		cout << "Dia, mes, anio: " << tf->getdia() << tf->getmes() << tf->getanio() << "\n";
		set <TipoFactura *> setcillo = factfecha->verFacturasFecha(tf);
		set <TipoFactura *> :: iterator it;
		if (setcillo.empty()) {
			cout << "vacio"<<"\n";
		} else {
			cout << "no vacio"<<"\n";
		}
		for (it = setcillo.begin(); it != setcillo.end(); ++it) {
			imprimirFactura (*it);
			cout << '\n';
		}
	} catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void VentaDomicilio() {
	try {
		bool nhc, existe, hayProductos;
		int cerouno, nropuerta, nroapart, cant, elec, seguir, repar,salir;
		string telefono, calle, c1, c2, nombreedif, nombrecliente, cod;
		
		salir=0;
		cout << "Ingrese el numero de telefono de cliente"<<"\n";
		cin >> telefono;
		nhc = vdom->noHayCliente(telefono);
		if (nhc) {
			cout << "No registrado, procederemos a registrarlo"<<"\n";
			cout << "Presione 1 si vive en un apartamento"<<"\n";
			cout << "Presione 0 si vive en una casa"<<"\n";
			cin >> cerouno;
			cout << "Ingrese el nombre de calle: "<<"\n";
			cin.ignore(1,'\n');
			getline(std::cin,calle);fflush(stdin); 
			cout << "Ingrese el numero de puerta: "<<"\n";
			cin >> nropuerta;
			cout << "Ingrese una esquina: "<<"\n";
			cin.ignore(1,'\n');
			fflush(stdin); getline(std::cin,c1);
			cout << "Ingrese la otra esquina: "<<"\n";
			cin.ignore(1,'\n');
			fflush(stdin); getline(std::cin,c2);
			cout << "Ingrese su nombre: "<<"\n";
			cin.ignore(1,'\n');
			fflush(stdin); getline(std::cin,nombrecliente);
			if (cerouno == 1) {
				cout << "Ingrese el nombre del edificio: "<<"\n";
				fflush(stdin); getline(std::cin,nombreedif);
				cout << "Ingrese el numero de apartamento: "<<"\n";
				cin >> nroapart;
				TipoDireccionApart * tda = vdom->hacedorApar(calle, nropuerta, c1, c2, nombreedif, nroapart);
				vdom->datosCliente(nombrecliente, tda);
			} else {
				TipoDireccion * td = vdom->hacedorDir(calle, nropuerta, c1, c2);
				vdom->datosCliente(nombrecliente, td);
			}
			vdom->confirmarAgregarCliente(true);
		}
		hayProductos = false;
		do {
			set<TipoProducto*> prods = vdom->darProds();
			//ImprimirProductos(prods);
			imprimirSetProds(prods);
			cout << "Ingrese el código de uno de los productos mostrados anteriormente"<<"\n";
			cin >> cod;
			cout << "Ingrese la cantidad de dicho producto a agregar"<<"\n";
			cin >> cant;
			while (cant <= 0) {
				cout << "Ingrese una cantidad positiva"<<"\n";
				cin >> cant;
			}
			existe = vdom->ingProds(cod, cant);
			while (!existe&&salir==0) {
				cout << "Codigo no valido ¿Desea salir? si-1, no-0" << "\n";
				cin >> salir;
				if (!salir)
				{
					cout << "Ingrese un codigo valido"<<"\n";
					cin >> cod;
					existe = vdom->ingProds(cod, cant);
				}
				
			}if (!salir)
				{
				cout << "Agregar el producto de codigo "<< cod <<" con cantidad "<< cant <<"\n";
				cout << "Presione 1 para confirmar, o 0 para desistir"<<"\n";
				cin >> elec;
				if (elec == 1) {
					vdom->confirmarProductoEnDomicilio();
					hayProductos = true;
				}
				cout << "Presione 0 para salir, presione 1 para continuar agregando" << '\n';
				cin >> seguir;
			}
			} while(seguir!=0&&!salir);
		if (hayProductos) 
		{
			cout << "¿Desea delivery?"<<"\n";
			cout << "Presione 1 si quiere"<<"\n";
			cout << "Presione 0 si no quiere"<<"\n";
			cin >> cerouno;
			if (cerouno == 1) {
				int solicitar=1;
				while(solicitar){
				cout << "Ingrese el código de uno de los repartidores a continuación"<<"\n";
				repartidores();
				cin >> repar;
				if(AE->encontrarRepartidor(repar))
					{
					vdom->elegirRepartidor(repar);
					vdom->inicializarEstado(1);
			    	cout << "Su pedido fue ingresado" << '\n';
			    	solicitar=0;
			    	}
					else
						{cout << "Repartidor no valido" << "\n";
						 cout << "Desea solicitar otro? si 1 // no 0" << "\n";
						 cin >> solicitar;
						}
				}	}
			else{
				cout << "Su pedido fue ingresado" << '\n';
				vdom->inicializarEstado(3);}
			
			
		} else
			cout << "No ingreso ningun producto a su venta" << '\n';
		}
	 catch (const char* error) {
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}


void VentasRepartidor(){

		cout << "Ingrese numero de empleado: " << endl;
        int nro;
        cin >> nro;
        set<TipoDomicilio*> ventas = MEP->getVentasRepartidor(nro);
         set<TipoDomicilio*> :: iterator k;
        for (k = ventas.begin(); k != ventas.end(); ++k)
        {
        	TipoDomicilio* domi = *k;
        	cout << domi << endl;
        }


}


void ModificarEstado() {
	try {
		VentasRepartidor();
		string cod, sEstado, confirmar;
		int estado;
		float descuentazo;
		cout << "Ingrese el codigo de venta" << '\n';
		cin >> cod;
		bool evd = MEP->existeVentaDom(cod);
		if (!evd)
			throw "El codigo ingresado no existe\n";
		set <TipoEstado> ste = MEP->ingrPedido(cod);
		set <TipoEstado> :: iterator it;
		for (it = ste.begin(); it != ste.end(); ++it) {
			TipoEstado current = *it;
			imprimirEstado(current);
		}
		cout << "Ahora ingrese el nuevo estado (numero del 1 al 4)" << '\n';
		cin >> sEstado;
		estado = stoi(sEstado);
		if (estado > 4 || estado < 1)
			throw "Estado inexistente\n";
		MEP->elegirEstado(estado);
		cout << "¿Desea confirmar? (Y) o (N)" << '\n';
		cin >> confirmar;
		if (!confirmar.compare("Y")) {
			MEP->confirmarNuevoEstado();
			cout << "Estado cambiado con exito" << '\n';
			if (estado == 3) {
				cout << "Como el estado ha pasado a ser 'Entregado', procederemos a facturar su pedido" << '\n' << '\n';
				cout << "Ingrese el numero de porcentaje de descuento (sin %, solo numero)"<<"\n";
				cout << "Solo se aplicará de no haber menus en la venta"<<"\n";
				cin >> descuentazo;
				while (descuentazo < 0) {
					cout << "Ingrese un descuento no negativo"<<"\n";
					cin >> descuentazo;
				}
				TipoFactura * lafactura = MEP->facturar(descuentazo);
				imprimirFactura(lafactura);
				
			}
		}
	} catch (const char* error) {
		cout << error << '\n';
	} catch (...) {
		cout << "Error inesperado\n";
	}
}

void ConsultarActualizacionesCliente() { 
	try {
		cout << "Ingrese su telefono" << '\n';
		string tel;
		cin >> tel;
		bool nhc = CPC->noHayCliente(tel);
		if (nhc)
			throw "Disculpe, usted no esta ingresado en el sistema\n";
		 //CV->setTelefono(tel);
		bool rm = CPC->recibeMensajes();
		if (!rm)
			throw "Lo sentimos, usted no esta de alta para recibir mensajes";
		cout << "¿Desea confirmar? (Y) o (N)" << '\n';
		string sConfirmar;
		cin >> sConfirmar;
		if (!sConfirmar.compare("Y")) {
			TipoActualizacion * ta = CPC->ConfirmarMensaje();
			imprimirTipoAct(ta);
		}
	} catch (const char* error){
		cout << error << '\n';
	}
	catch (...) {
		cout << "Error inesperado\n";
	}
}

void ConsultarActualizacionesAdministrador() {
	set<TipoActualizacion*> sta = CPA->ListarActualizacionesSistema();
	set<TipoActualizacion*> :: iterator it;
	for (it = sta.begin(); it != sta.end(); ++it) {
		TipoActualizacion * current = *it;
		imprimirTipoAct(current);
	}
}

void CargarDatos() { 
	bool bandera, existe;
    int cont;
    cout << "Eliga la cantidad de mesas" << "\n";
    cin >> cont;
	bandera=AP->noHayCodigo("1");
	if (bandera) {
		AP->datosProdSim("Pizza con muzzarella", 130);
		AP->confirmarAltaProd(1);
	}
	bandera=AP->noHayCodigo("2");
	if (bandera) {	
		AP->datosProdSim("Milanesa con guarnición", 230);
		AP->confirmarAltaProd(1);
	} 
	bandera=AP->noHayCodigo("3");
	if (bandera) {
		AP->datosProdSim("Coca Cola 1.25L ", 95);
		AP->confirmarAltaProd(1);
	}
	bandera=AP->noHayCodigo("4");
	if (bandera) {
		AP->datosProdSim("Empanada Capresse", 72);
		AP->confirmarAltaProd(1);
	}
	bandera=AP->noHayCodigo("5");
	if (bandera) {
		AP->datosProdSim("Flan con dulce de leche ", 110);
		AP->confirmarAltaProd(1);
	}
	bandera=AP->noHayCodigo("6");
	if (bandera) {
		AP->datosProdMenu("Combo Pizza");
		AP->ingrProdSim("1", 1);
		AP->ingrProdSim("3", 1);
		AP->confirmarAltaProd(0);
		AP->borrarPares();
    }
	bandera=AP->noHayCodigo("7");
	if (bandera) {
		AP->datosProdMenu("Combo Empanadas");
		AP->ingrProdSim("3", 1);
		AP->ingrProdSim("4", 3);
		AP->confirmarAltaProd(0);
		AP->borrarPares();
    }
    AE->setNombreEmpleado("Juan Pedro" );
    AE->ConfirmarEmpleado(true);							
    AE->setNombreEmpleado("Johnny" );
    AE->ConfirmarEmpleado(true);
    AE->setNombreEmpleado("José" );
    AE->ConfirmarEmpleado(true);
    AE->setNombreEmpleado("Tito");
    AE->setVehiculo(Bicicleta);
    AE->ConfirmarEmpleado(false);
    AE->setNombreEmpleado("Raúl");
    AE->setVehiculo(Moto);
    AE->ConfirmarEmpleado(false);
    AE->setNombreEmpleado("Tiki Gelana" );
    AE->setVehiculo(Pie);
    AE->ConfirmarEmpleado(false);
	for (int i = 1; i <= cont; i++) {
		AE->crearmesa(i);
	}
	
	vdom->noHayCliente("098217523");
	TipoDireccionApart * tda1 = vdom->hacedorApar("18 de Julio", 2033, "Calle 1", "Calle 2", "Mar Austral", 701);
	vdom->datosCliente("Vladimir", tda1);
	vdom->confirmarAgregarCliente(true);
	
	vdom->noHayCliente("091651249");
	TipoDireccion * td = vdom->hacedorDir("Cabildo", 500, "Calle 1", "Calle 2");
	vdom->datosCliente("Martin", td);
	vdom->confirmarAgregarCliente(true);
	
	vdom->noHayCliente("097321590");
	TipoDireccionApart * tda2 = vdom->hacedorApar("Avenida Brasil", 842, "Calle 1", "Calle 2", "Atlantis", 302);
	vdom->datosCliente("Ronaldo", tda2);
	vdom->confirmarAgregarCliente(true);
	
	vdom->noHayCliente("091651249");
	existe = vdom->ingProds("7", 5);
	if (existe) {
		vdom->confirmarProductoEnDomicilio();
		vdom->elegirRepartidor(4);
		vdom->inicializarEstado(2);
	}
	vdom->noHayCliente("091651249");
	existe = vdom->ingProds("2", 2);
	if (existe) {
		vdom->confirmarProductoEnDomicilio();
		vdom->elegirRepartidor(5);
		vdom->inicializarEstado(3);
	}
	vdom->noHayCliente("098217523");
	existe = vdom->ingProds("6", 1);
	if (existe) {
		vdom->confirmarProductoEnDomicilio();
		vdom->elegirRepartidor(4);
		vdom->inicializarEstado(2);
	}
}

//------------nuevo





int main() {
	
	
	int bandera,bandera1;


	cout << '\n' << "¡Bienvenido!" << '\n' << '\n';
    
	do {
	    cout << "----------------------------------------------------------------" 	<< '\n';

		//cout << "cantidad ventas: ";
		//factventa->imprimirVentas();
		//factfecha->imprimirAct();
		//cout << endl;
		cout << "Por favor, seleccione una de las siguientes opciones: " << '\n';
		cout << "1-Administrador"<< "\n";
		cout << "2-Mozo"<<"\n";
		cout << "3-Repartidor"<<"\n";
		cout << "4-Cliente"<<"\n";
		cout << "5-Cargar datos de prueba"<< "\n";
		cout << "0-Salir"<<"\n";
		cout << "Opcion: ";
		cin >> bandera;
		switch (bandera) {
			case 1: { //Administrador
				do {
					cout << "----------------------------------------------------------------"<< "\n";
					cout << "1-Alta producto"<< "\n";
					cout << "2-Informacion de un producto"<< "\n";
					cout << "3-Baja Producto"<< "\n";
					cout << "4-Alta empleado"<< "\n";
					cout << "5-Asignar Mozo-Mesa"<< "\n";
					cout << "6-Resumen facturación de 1 día dada la fecha"<< "\n";
					cout << "7-Consultar actualizaciones de pedidos a domicilio"<<"\n";
					cout << "8-Venta a domicilio"<< "\n";
					cout << "9-Ver repartidores" << "\n";
					cout << "10-Ver mozos" << "\n";
					cout << "0-volver"<<"\n";
					cout << "Opcion: ";

					cin >> bandera1;
					switch(bandera1) {
						case 1: {
							AltaProd();
							break;
						}
						case 2: {
							InfProd();
							break;
						}
						case 3: {
							BajaProd();
							break;
						}
						case 4: {
							AltaEmpleado();
						    //repartidores();
							break;
						}
						case 5: {
							AsigMozoMesa();
							break;
						}
						case 6: {
							ResFactFecha();
							break;
						}
						case 7: {
							ConsultarActualizacionesAdministrador();
							break;
						}
						case 8: {
							VentaDomicilio();
							break;
						}
						case 9: {
							repartidores();
							break;
						}
						case 10: {
							imprimirMozos(); 
							break;
						}
						default:break;
					}
				} while(bandera1!=0);    
				break;
			}
			case 2: { //Mozo
				do {
					cout << "----------------------------------------------------------------"<< "\n";

					cout << "1-Iniciar venta en mesa"<< "\n";
					cout << "2-Agregar producto a una venta"<<"\n";
					cout << "3-Quitar producto a una venta"<<"\n";
					cout << "4-Facturar una venta"<<"\n";
					cout << "0-volver"<<"\n";
					cout << "Opcion: ";

					cin >> bandera1;

					switch(bandera1) {
						case 1: {
							IniciarVenMesa();
							break;
						}
						case 2: {
							AgregarProdVenta();
							break;
						}
						case 3:{ 
							QuitarProdVenta();
							break;
						}
						case 4: {
							FactVenta();
							break;
						}
						default:break;
					}
				} while(bandera1!=0);
				break;
			}
			case 3: { //Repartidor
				do {		
					cout << "----------------------------------------------------------------"<< "\n";

					cout << "1-Modificar estado pedido"<<"\n";
					cout << "2 - Ventas repartidor" << endl;
					cout << "0-volver"<<"\n";
					cout << "Opcion: ";

					cin >> bandera1;
					switch(bandera1) {
						case 1:{
							ModificarEstado();
							break;
						}
						case 2:{
							VentasRepartidor();
							break;
						}
						default:break;

					}
				} while(bandera1!=0);
				break;
			}
			case 4: { //Cliente
				do {
					cout << "----------------------------------------------------------------" << "\n";

					cout << "1-Consultar actualizaciones de pedidos a domicilio"<< "\n";
					cout << "0-volver"<<"\n"; 
					cout << "Opcion: ";

					cin >> bandera1;
					switch(bandera1) {
						case 1: {
							ConsultarActualizacionesCliente();
							break;
						}
						default:break;
					}
				} while(bandera1!=0);  
				break;
			}	
			case 5: { //Cargar datos
				CargarDatos();
				break;
			}
			default: break;
	
		}
	} while(bandera!=0);
	
	cout << "¡Adios!" << '\n';
	
	return 0;
}
