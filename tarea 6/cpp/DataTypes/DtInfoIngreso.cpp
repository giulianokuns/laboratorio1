#include "DtInfoIngreso.h"
#include <string.h>

using namespace std;

DtInfoIngreso::DtInfoIngreso (Fecha fecha_ingreso, Hora hora_ingreso) {
	this->dtFechaIngreso = fecha_ingreso;
	this->dtHoraIngreso  = hora_ingreso;
}

DtInfoIngreso::~DtInfoIngreso () {}

string DtInfoIngreso::getFechaIngreso() {
	return dtFechaIngreso;
}
string DtInfoIngreso::getHoraIngreso() {
	return dtHoraIngreso;
}