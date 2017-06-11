#include "Fecha.h"
#include "Hora.h"

string Mensaje::getcodigo(){
	return codigo;
}
Fecha Mensaje::getfechaMensaje(){
	return fechaMensaje;
}
Hora Mensaje::gethoraMensaje(){
	return horaMensaje;
}
void Mensaje::setcodigo(string codigo){
	this->codigo = codigo;
}
void Mensaje::setfechaMensaje(Fecha fechaMensaje){
	this->fechaMensaje = fechaMensaje;
}
void Mensaje::sethoraMensaje(Hora horaMensaje){
	this->horaMensaje = horaMensaje;
}