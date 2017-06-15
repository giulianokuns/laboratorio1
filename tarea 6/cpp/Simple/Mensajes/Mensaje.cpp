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

bool Mensaje::validarFechaHoraMensaje(DtInfoIngreso fecha_hora_ingreso) {
	if (this->getfechaMensaje() > fecha_hora_ingreso->getFechaIngreso()) {
		//mensaje valido
	} else if (this->getfechaMensaje() == fecha_hora_ingreso->getFechaIngreso()) {
		//Puede valer, depende de la hora
		if (this->gethoraMensaje() >= fecha_hora_ingreso->getHoraIngreso()) {
			//vale mensaje
		} else {
			//no vale mensaje
		}
	} else {
		//no vale mensaje
	}
}