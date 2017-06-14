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