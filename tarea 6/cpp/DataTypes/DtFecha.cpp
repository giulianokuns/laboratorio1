#include "DtFecha.h"

Fecha::DtFecha(int dia,int mes,int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int DtFecha::getdia(){
	return dia;
}
int DtFecha::getmes(){
	return mes;
}
int DtFecha::getanio(){
	return anio;
}