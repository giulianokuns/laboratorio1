#include "Fecha.h"
#include "Hora.h"

Grupo::Grupo(string nomGrupo, string imagenGrupo,	Fecha fechaCreacion,	Hora horaCreacion,	IDictionary infoIngresos){
	this->nomGrupo = nomGrupo;
	this->imagenGrupo = imagenGrupo;
	this->fechaCreacion = fechaCreacion;
	this->horaCreacion = horaCreacion;
	this->infoIngresos = infoIngresos;
}

string Grupo::getnomGrupo(){
	return nomGrupo;
}
string Grupo::getimagenGrupo(){
	return imagenGrupo;
}
Fecha Grupo::getfechaCreacion(){
	return fechaCreacion;
}
Hora Grupo::gethoraCreacion(){
	return horaCreacion;
}
void Grupo::setnomGrupo(string nombre){
	this->nomGrupo = nombre;
}
void Grupo::setimagenGrupo(string imagen){
	this->imagenGrupo = imagen;
}
void Grupo::setfechaCreacion(Fecha fechaCreacion){
	this->fechaCreacion = fechaCreacion;
}
void Grupo::sethoraCreacion(Hora horaCreacion){
	this->horaCreacion = horaCreacion;
}