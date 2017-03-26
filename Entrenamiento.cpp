#include "Entrenamiento.h"
#include "Inscripcion.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

using namespace std;

Entrenamiento::Entrenamiento(bool enRambla, int id, string nombre,Turno turno){
	this->enRambla = enRambla;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
    Inscripcion **Inscripciones = new *Inscripcion[50];
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
		delete Inscripciones[i];
	}
	delete Inscripciones;
}
