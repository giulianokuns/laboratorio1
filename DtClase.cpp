#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
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

void DtClase::setid(int id){
	this->id = id;
}

void DtClase::setNombre(string nombre){
	this->nombre = nombre;
}

void DtClase::setTurno(Turno turno){
	this->turno = turno;
}
