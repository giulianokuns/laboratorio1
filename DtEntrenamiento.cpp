#include "DtEntrenamiento.h";

DtEntrenamiento::DtEntrenamiento(bool enRambla,int id, string nombre,Turno turno){
	this->enRambla = enRamla;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
}

DtEntrenamiento::~DtEntrenamiento(){}

bool DtEntrenamiento::getenRambla(){
	return enRambla;
}