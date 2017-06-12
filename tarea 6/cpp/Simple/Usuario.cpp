#include "Fecha.h"
#include "Hora.h"


Usuario::Usuario(string telCel,string nomUsuario,Fecha fechaRegistro,string imaPerfil,Fecha fechaUltimaConex,Hora horaUltimaConex){
	
	this->telCel = telCel;
	this->nomUsuario = nomUsuario;
	this->fechaRegistro = fechaRegistro;//no se crea una instancia nueva 
	this->imaPerfil = imaPerfil;
	this->fechaUltimaConex = fechaUltimaConex;//no se crea una instancia nueva
	this->horaUltimaConex = horaUltimaConex;//no se crea una instancia nueva
	this->arreglo_ec = arreglo_ec;
}
Usuario::~Usuario(){
	
}

string Usuario::gettelCel(){
	return telCel;
}

string Usuario::getnomUsuario(){
	return nomUsuario;
}

Fecha Usuario::getfechaRegistro(){
	return fechaRegistro;
}

string Usuario::getimaPerfil(){
	return imaPerfil;
}

Fecha Usuario::getfechaUltimaConex(){
	return fechaUltimaConex;
}

Hora Usuario::gethoraUltimaConex(){
	return horaUltimaConex;
}

ICollection Usuario::getarreglo_ec(){
	return arreglo_ec;
}

void Usuario::settelCel(string cel){
	this->telCel = cel;
}

void Usuario::setnomUsuario(string nombre){
	this->nomUsuario = nombre;
}

void Usuario::setfechaRegistro(Fecha fechaRegistro){
	this->fechaRegistro = fechaRegistro;
}

void Usuario::setimaPerfil(string URL){
	this->imaPerfil = URL;
}
void Usuario::setfechaUltimaConex(Fecha fechaUltimaConex){
	this->fechaUltimaConex = fechaUltimaConex;
}
void Usuario::sethoraUltimaConex(Hora horaUltimaConex){
	this->horaUltimaConex = horaUltimaConex;
}
void Usuario::setarreglo_ec(ICollection arreglo_ec){
	this->arreglo_ec = arreglo_ec;
}
	
	/*archivar_conversacion*/
ICollection Usuario::get_lista_activos(){
	ICollection arreglo_ec = getarreglo_ec();
	ICollection colecciondt = new List();
	for(IIterator *it = arreglo_ec->getIterator();it->hasCurrent();it->next){
		EstadoConversacion ec = getCurrent();
		if (ec->getarchivada()!){
			Conversacon c = ec->getconversacion();
			Dtconversacion dtc = c->getinfo();
			colecciondt->add(dtc);
		}
	}
	return colecciondt;
}