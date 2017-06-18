#include "DtInfoIngreso.h"
#include <String.h>

using namespace std;

DtInfoIngreso::DtInfoIngreso (Fecha fecha_ingreso, Hora hora_ingreso) {
	this->dtFechaIngreso = new Fecha(fecha_ingreso->getdia(), fecha_ingreso->getmes(), fecha_ingreso->getanio());
	this->dtHoraIngreso  = new Hora(hora_ingreso->gethoras(), hora_ingreso->getminutos());
}

DtInfoIngreso::~DtInfoIngreso () {}

Fecha DtInfoIngreso::getFechaIngreso() {
	return dtFechaIngreso;
}
Hora DtInfoIngreso::getHoraIngreso() {
	return dtHoraIngreso;
}