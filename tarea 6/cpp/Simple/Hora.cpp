#include "Hora.h"


Hora::Hora(int horas, int minutos){
	this->horas = horas;
	this->minutos = minutos;
}

int Hora::gethoras(){
	return horas;
}
int Hora::getminutos(){
	return minutos;
}
void Hora::sethoras(int hora){
	this->horas = hora;
}
void Hora::setminutos(int minutos){
	this->minutos = minutos;
}

bool operator ==(const Hora &a, const Hora &b) const {
	if (a.gethoras() == b.gethoras()) {
		if (a.minutos() == b.minutos()) {
			return true;
		}
	}
	return false;
}

bool operator  >(const Hora &a, const Hora &b) const {
	if (a.gethoras() > b.gethoras()) {
		return true;
	} else if (a.gethoras() < b.gethoras()) {
		return false;
	} else {
		if (a.getminutos() > b.getminutos()) {
			return true;
		} else {
			return false;
		}
	}
}