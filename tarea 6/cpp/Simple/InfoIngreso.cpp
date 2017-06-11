#include "Fecha.h"
#include "Hora.h"


Fecha InfoIngreso::getfechaIngreso(){
	return fechaIngreso;
}
Hora InfoIngreso::gethoraIngreso(){
	return horaIngreso;
}
void InfoIngreso::setfechaIngreso(Fecha fechaIngreso){
	this->fechaIngreso = fechaIngreso;
}
void InfoIngreso::sethoraIngreso(Hora horaIngreso){
	this->horaIngreso = horaIngreso;
}