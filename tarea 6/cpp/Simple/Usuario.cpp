#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Fecha.h"
#include "Hora.h"
#include "EstadoConversacion.h"
#include "Usuario.h"

Usuario::Usuario(String telCel,String nomUsuario,Fecha fechaRegistro,String imaPerfil,Fecha fechaUltimaConex,Hora horaUltimaConexICollection arreglo_ec, IDictionary contactos){
	
	this->telCel = telCel;
	this->nomUsuario = nomUsuario;
	this->fechaRegistro = fechaRegistro;//no se crea una instancia nueva 
	this->imaPerfil = imaPerfil;
	this->fechaUltimaConex = fechaUltimaConex;//no se crea una instancia nueva
	this->horaUltimaConex = horaUltimaConex;//no se crea una instancia nueva
	this->arreglo_ec = arreglo_ec;
	this->contactos = contactos;
}
Usuario::~Usuario(){
	
}

String Usuario::gettelCel(){
	return telCel;
}

String Usuario::getnomUsuario(){
	return nomUsuario;
}

Fecha Usuario::getfechaRegistro(){
	return fechaRegistro;
}

String Usuario::getimaPerfil(){
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
IDictionary Usuario::getcontactos(){
	return contactos;
}
IDictionary Usuario::getMensajes(){
	return mensajes;
}

void Usuario::settelCel(String cel){
	this->telCel = cel;
}

void Usuario::setnomUsuario(String nombre){
	this->nomUsuario = nombre;
}

void Usuario::setfechaRegistro(Fecha fechaRegistro){
	this->fechaRegistro = fechaRegistro;
}

void Usuario::setimaPerfil(String URL){
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
void Usuario::setcontactos(IDictionary contactos){
	this->contactos = contactos;
}
void Usuario::setMensajes(IDictionary mensajes){
	this->mensajes = mensajes;
}

ICollection getListaArchivadas() {
	IDictionary * ec_array = getarreglo_ec();
	ICollection list_archivadas = new List();
	for (IIterator *it = ec_array->getIterator(); it->hasCurrent(); it->next()) {
		EstadoConversacion ec = getCurrent();
		if (ec.getarchivada()) {
			Conversacon c = ec.getconversacion();
			DtConversacion dtc = c.getinfo();
			list_archivadas.add(dtc);
		}
	}
	return list_archivadas;
}

/*archivar_conversacion*/
ICollection Usuario::get_lista_activos(){
	IDictionary arreglo_ec = getarreglo_ec();
	ICollection colecciondt = new List();
	for (IIterator *it = arreglo_ec->getIterator(); it->hasCurrent(); it->next()) {
		EstadoConversacion ec = getCurrent();
		if (!ec.getarchivada()) {
			Conversacon c = ec.getconversacion();
			DtConversacion dtc = c.getinfo();
			colecciondt.add(dtc);
		}
	}
	return colecciondt;
}

void Usuario::archivar(String ID){
	IDictionary arreglo_ec = getarreglo_ec();
	EstadoConversacion ec = find(ID);//o el correspondiente key
	ec.setarchivada(true);
}
	/*agregarContacto*/
ICollection Usuario::getInfoContactos(){
	IDictionary contactos = getcontactos();
	ICollection lista_dtInfoContacto = new list();
	for (IIterator *it = contactos->getIterator(); it->hasCurrent(); it->next()) {
		Usuario * u = getCurrent();
		DtInfoContacto *dt = new DtInfoContacto(u->getnomUsuario(), u->gettelCel(), u->getimaPerfil());
		lista_dtInfoContacto->add(dt);
	}
	return lista_dtInfoContacto;
}
bool Usuario::esContacto(telCel){
	IDictionary contactos = getcontactos();
	return contactos->member(telCel);
}
DtInfoContacto Usuario::getIfoContacto(telCel){
	IDictionary contactos = getcontactos();
	Usuario u = find(telCel);
	DtInfoContacto dt = new DtInfoContacto(u->getnomUsuario(), u->gettelCel(), u->getimaPerfil());
	return dt;
}
void Usuario::agregarContacto(Usuario u){
	IDictionary set_contactos = getcontactos();
	set_contactos->add(telCel,u);
}

ICollection Usuario::mensajesCoversacion (int idConv) {
	IDictionary ec_array = this->getarreglo_ec();
	Conversacion c = NULL;
	
	// Una vez obtiene la conversacion sale del for
	for (IIterator *it = ec_array->getIterator(); (it->hasCurrent() && c == NULL); it->next()) {
		EstadoConversacion ec = getCurrent();
		Conversacion c = ec.compararConv(idConv);
	}
	
	es_grupo = c.getesGrupo();
	if (es_grupo) {
		ICollection	mensajes = c.obtenerMensajesGrupo(); 
	} else {
		ICollection	mensajes = c.obtenerMensajesConv(); 
	}

	return mensajes
}

int Usuario::getCantidadArhivadas() {
	IDictionary ec_array = this->getarreglo_ec();
	int cant_archivadas = 0;

	for (IIterator *it = ec_array->getIterator(); it->hasCurrent(); it->next()) {
		EstadoConversacion ec = getCurrent();
		bool esta_archivada = ec.getarchivada();
		if (esta_archivada) {
			cant_archivadas++;
		}
	}

	return cant_archivadas;
}

ICollection Usuario::getReceptores(String codigo) {
	IDictionary arr_mensj = this->getMensajes();
	Mensaje m = arr_mensj.find(codigo);
	ICollection receptores = m.getReceptores();
}