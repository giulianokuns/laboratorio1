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

bool Hora::operator ==(const Hora &a) const {
	if (this.gethoras() == a.gethoras()) {
		if (this.minutos() == a.minutos()) {
			return true;	
		}
	}
	return false;
}

bool Hora::operator  >(const Hora &a) const {
	if (this.gethoras() > a.gethoras()) {
		return true;
	} else if (this.gethoras() < a.gethoras()) {
		return false;
	} else {
		if (this.getminutos() > a.getminutos()) {
			return true;
		} else {
			return false;
		}
	}
}


ostream& Hora::operator<<(ostream& os, const Hora& hora) {
	os 	<< hora.getdia() << " - " << hora.getmes() << " - " << hora.getanio();  
    return os;  	
}