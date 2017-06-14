#include "Fecha.h"
#include "Hora.h"

String Mensaje::getcodigo(){
	return codigo;
}
Fecha Mensaje::getfechaMensaje(){
	return fechaMensaje;
}
Hora Mensaje::gethoraMensaje(){
	return horaMensaje;
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