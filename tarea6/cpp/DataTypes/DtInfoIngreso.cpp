#include "../../h/DataTypes/DtInfoIngreso.h"


using namespace std;

DtInfoIngreso::DtInfoIngreso(Fecha fecha_ingreso, Hora hora_ingreso){
	this->dtFechaIngreso = fecha_ingreso;
	this->dtHoraIngreso  = hora_ingreso;
}

DtInfoIngreso::~DtInfoIngreso () {}

Fecha DtInfoIngreso::getFechaIngreso() {
	return dtFechaIngreso;
}
Hora DtInfoIngreso::getHoraIngreso() {
	return dtHoraIngreso;
}