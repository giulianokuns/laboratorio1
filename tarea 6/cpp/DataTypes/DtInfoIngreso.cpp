#include "DtInfoIngreso.h"
#include <string.h>

using namespace std;

DtInfoIngreso::DtInfoIngreso (Fecha fecha_ingreso, Hora hora_ingreso) {
	this->dtFechaIngreso = new Fecha(fecha_ingreso->getdia(), fecha_ingreso->getmes(), fecha_ingreso->getanio());
	this->dtHoraIngreso  = new Hora(hora_ingreso->gethoras(), hora_ingreso->getminutos());
}

DtInfoIngreso::~DtInfoIngreso () {}

string DtInfoIngreso::getFechaIngreso() {
	return dtFechaIngreso;
}
string DtInfoIngreso::getHoraIngreso() {
	return dtHoraIngreso;
}