#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "EstadoConversacion.h"

EstadoConversacion::EstadoConversacion(bool archivada, Conversacion c){
	this->archivada = archivada;
	this->conversacion = c;
}
EstadoConversacion::~EstadoConversacion(){

}
bool EstadoConversacion::getarchivada(){
	return archivada;
}
Conversacion EstadoConversacion::getconversacion(){
	return conversacion;
}
void EstadoConversacion::setarchivada(bool archivada){
	this->archivada = archivada;
}
void EstadoConversacion::setconversacion( Conversacion c){
	this->conversacion = c;
}

/* 
	Compara el id conversacion asociada a un estado de conversacion con 
	el idConv recibido.
	Si son iguales devuelve un puntero a la Conversacion
	NULL en otro caso.
*/
Conversacion * EstadoConversacion::compararConv (int idConv) {
	Conversacion c * = this->getconversacion();
	if (c->getidConversacion() == idConv) {
		return c;
	} else {
		return NULL;
	}
}