#include "../../h/Simple/Hora.h"

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

bool Hora::operator ==(Hora &a) {
	if (this->gethoras() == a.gethoras()) {
		if (this->getminutos() == a.getminutos()) {
			return true;	
		}
	}
	return false;
}

bool Hora::operator  >(Hora &a) {
	if (this->gethoras() > a.gethoras()) {
		return true;
	} else if (this->gethoras() < a.gethoras()) {
		return false;
	} else {
		if (this->getminutos() > a.getminutos()) {
			return true;
		} else {
			return false;
		}
	}
}

ostream& Hora::operator<<(ostream& os) {
	os 	<< this->gethoras() << ":" << this->getminutos();  
    return os;  	
}