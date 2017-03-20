#include "Spinning.h"

using namespace std;

Spinning::Spinning(int cantBicicletas, int id, string nombre,Turno turno){
	this->cantBicicletas = cantBicicletas;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
	Inscripcion **Inscripciones = new *Inscripcion[cantBicicletas];
	this->setInscripciones(Inscripciones);
	this->setInscriptos(0);
};

int  Spinning::getCantBicicletas(){
	return cantBicicletas;
}

void  Spinning::setCantBicicletas(int cantBicicletas){
	this->cantBicicletas = cantBicicletas;
}

int Spinning::cupo(){
	this->cantBicicletas - this->getCantInscriptos();
}

Spinning::~Spinning(){
	Inscripcion **Inscripciones = this->getInscriptos();
	for(int i=0;i<this->getCantInscriptos();i++){
		delete *Inscripciones[i];
	}
	delete Inscripciones;
}
