#include "Fecha.h"
#include "Hora.h"
#include "InfoIngreso.h"
InfoIngreso::InfoIngreso(Fecha fechaIngreso,	Hora horaIngreso,	Usuario usuario){
	this->fechaIngreso = fechaIngreso;
	this->horaIngreso = horaIngreso;
	this->usuario = usuario;
}
Fecha InfoIngreso::getfechaIngreso(){
	return fechaIngreso;
}
Hora InfoIngreso::gethoraIngreso(){
	return horaIngreso;
}
Usuario InfoIngreso::getUsuario() {
	return usuario;
}

void InfoIngreso::setfechaIngreso(Fecha fechaIngreso){
	this->fechaIngreso = fechaIngreso;
}
void InfoIngreso::sethoraIngreso(Hora horaIngreso){
	this->horaIngreso = horaIngreso;
}
void InfoIngreso::setUsuario (Usuario usuario) {
	this->usuario = usuario;
}