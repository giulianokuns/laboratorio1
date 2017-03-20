#include "DtSpinning.h"

DtSpinning::DtSpinning(int cantBicicletas, int id, string nombre,Turno turno){
	this->cantBicicletas = cantBicicletas;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
}

DtSpinning::~DtSpinning(){}

int DtSpinning::getCantBicicletas(){
	return cantBicicletas;
}