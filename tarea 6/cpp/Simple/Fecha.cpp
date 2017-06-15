#include "Fecha.h"

Fecha::Fecha(int dia,int mes,int anio){
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

bool Fecha::operator ==(const Fecha &a, const Fecha &b) const {
	if (a.getanio() == b.getanio()) {
		if (a.getmes() == b.getmes()) {
			if (a.getdia() == a.getdia()) {
				return true;
			}
		}
	}
	return false;
}

bool Fecha::operator >(const Fecha &a, const Fecha &b) const {
	if (a.getanio() > b.getanio()) {
		return true;
	} else if (a.getanio() < b.getanio()) {
		return false;
	} else {
		if (a.getmes() > b.getmes()) {
			return true;
		} else if (a.getmes() < b.getmes()) {
			return false;
		} else {
			if (a.getdia() > a.getdia()) {
				return true;
			} else {
				return false;
			}
		}
	}
}