#include "Fecha.h"
#include "Hora.h"
#include "Mensaje.h"

String Mensaje::getcodigo(){
	return codigo;
}
Fecha Mensaje::getfechaMensaje(){
	return fechaMensaje;
}
Hora Mensaje::gethoraMensaje(){
	return horaMensaje;
}
IDictionary Mensaje::getRecibidos() {
	return recibidos;
}

void Mensaje::setcodigo(String codigo){
	this->codigo = codigo;
}
void Mensaje::setfechaMensaje(Fecha fechaMensaje){
	this->fechaMensaje = fechaMensaje;
}
void Mensaje::sethoraMensaje(Hora horaMensaje){
	this->horaMensaje = horaMensaje;
}
void Mensaje::setRecibidos(IDictionary recibidos) {
	this->recibidos = recibidos;
}
	
	//Crear uno para cada clase
DtMensaje Mensaje::darMensaje () {
	if (dynamic_cast<Simple*> (&this) != NULL) {
		//Es Simple
	} else if (dynamic_cast<Contacto*> (&this) != NULL) {
		//Es Contacto
	} else {
		//Es Multimedia
		if (dynamic_cast<Imagen*> (&this) != NULL) {
			//Es Imagen
		} else {
			//Es Video
		}
	}
}