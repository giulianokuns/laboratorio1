#include "../../h/DataTypes/DtInfoIngreso.h"


using namespace std;

DtInfoIngreso::DtInfoIngreso(Fecha *fecha_ingreso, Hora *hora_ingreso) : dtFechaIngreso(fecha_ingreso->getdia(), fecha_ingreso->getmes(), fecha_ingreso->getanio()), dtHoraIngreso(hora_ingreso->gethoras(), hora_ingreso->getminutos()){
}

DtInfoIngreso::~DtInfoIngreso () {}

Fecha DtInfoIngreso::getFechaIngreso() {
	return dtFechaIngreso;
}
Hora DtInfoIngreso::getHoraIngreso() {
	return dtHoraIngreso;
}