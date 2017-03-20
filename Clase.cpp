#include "Clase.h"

using namespace std;

int Clase::getid(){
	return id
}

string Clase::getNombre(){
	return nombre;
}

Turno Clase::getTurno(){
	return turno;
}

Inscripcion **Clase::getInscriptos(){
	return Inscripciones;
}

int Clase::getCantInscriptos(){
	return cantInscriptos
}

void Clase::setid(int id){
	this->id = id;
}

void Clase::setNombre(string nombre){
	this->nombre = nombre;
}
void Clase::setTurno(Turno turno){
	this->turno = turno;
}

void Clase::setInscripciones(Inscripcion **Inscripciones){
	this->Inscripciones = Inscripciones;
}

void setInscriptos(int cantInscriptos){
	this->cantInscriptos = cantInscriptos;
}

