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