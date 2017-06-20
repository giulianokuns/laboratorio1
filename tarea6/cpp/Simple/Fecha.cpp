#include "../../h/Simple/Fecha.h"

Fecha::Fecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int Fecha::getdia(){
	return dia;
}
int Fecha::getmes(){
	return mes;
}
int Fecha::getanio(){
	return anio;
}
void Fecha::setdia(int dia){
	this->dia = dia;
}
void Fecha::setmes(int mes){
	this->mes = mes;
}
void Fecha::setanio(int anio){
	this->anio = anio;
}

bool Fecha::operator ==(Fecha &a) {
	if (this->getanio() == a.getanio()) {
		if (this->getmes() == a.getmes()) {
			if (this->getdia() == a.getdia()) {
				return true;
			}
		}
	}
	return false;
}

bool Fecha::operator >(Fecha *a) {
	if (this->getanio() > a->getanio()) {
		return true;
	} else if (this->getanio() < a->getanio()) {
		return false;
	} else {
		if (this->getmes() > a->getmes()) {
			return true;
		} else if (this->getmes() < a->getmes()) {
			return false;
		} else {
			if (this->getdia() > a->getdia()) {
				return true;
			} else {
				return false;
			}
		}
	}
}

ostream& Fecha::operator<<(ostream& os) {
	os 	<< this->getdia() << " - " << this->getmes() << " - " << this->getanio();
    return os;  	
}