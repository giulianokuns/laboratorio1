#include <iostream>
#include "DtClase.h"

using namespace std;

int DtClase::getid(){
	return id;
}

string DtClase::getNombre(){
	return nombre;
}

Turno DtClase::getTurno(){
	return turno;
}

void setid(int id){
	this->id = id;
}

void setNombre(string nombre){
	this->nombre = nombre;
}

void setTurno(Turno turno){
	this->turno = turno;
}
