#include "Entrenamiento.h"

using namespace std;

Entrenamiento::Entrenamiento(bool enRambla, int id, string nombre,Turno turno){
	this->enRambla = enRambla;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
	if(enRambla)
		Inscripcion **Inscripciones = new *Inscripcion[20];
	else
		Inscripcion **Inscripciones = new *Inscripcion[10];
	this->setInscripciones(Inscripciones);
	this->setInscriptos(0);
};

int  Entrenamiento::getenRambla(){
	return enRambla;
}

void  Entrenamiento::setenRambla(bool enRambla){
	this->enRambla = enRambla;
}

int Entrenamiento::cupo(){
	if(enRambla)
		20 - this->getCantInscriptos();
	else
		10 - this->getCantInscriptos();
}

Entrenamiento::~Entrenamiento(){
	Inscripcion **Inscripciones = this->getInscriptos();
	for(int i=0;i<this->getCantInscriptos();i++){
		delete *Inscripciones[i];
	}
	delete Inscripciones;
}