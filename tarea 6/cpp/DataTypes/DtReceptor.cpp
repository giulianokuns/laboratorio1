#include "DtReceptor.h"
#include <string.h>

using namespace std;

DtReceptor::DtReceptor (string nombre, int num_cel, Fecha fecha_visto, hora hora_visto) {
	this->dtNombre 		= nombre;
	this->dtNumTel 		= num_cel;
	this->dtFechaVisto 	= new Fecha(fecha_ingreso->getdia(), fecha_ingreso->getmes(), fecha_ingreso->getanio());
	this->dtHoraVisto 	= new Hora(hora_ingreso->gethoras(), hora_ingreso->getminutos());
}

DtReceptor::~DtReceptor () {}

string DtReceptor::getNombre () {
	return dtNombre;
}

int DtReceptor::getNumTel () {
	return dtNumTel;
}
Fecha DtReceptor::getFechaVisto () {
	return dtFechaVisto;
}
Hora DtReceptor::getHoraVisto () {
	return dtHoraVisto;
}