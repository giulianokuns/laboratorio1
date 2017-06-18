#include "Fecha.h"
#include "Hora.h"

Grupo::Grupo(String nomGrupo, String imagenGrupo,	Fecha fechaCreacion,	Hora horaCreacion,	IDictionary infoIngresos){
	this->nomGrupo = nomGrupo;
	this->imagenGrupo = imagenGrupo;
	this->fechaCreacion = fechaCreacion;
	this->horaCreacion = horaCreacion;
	this->infoIngresos = infoIngresos;
}

String Grupo::getnomGrupo(){
	return nomGrupo;
}
String Grupo::getimagenGrupo(){
	return imagenGrupo;
}
Fecha Grupo::getfechaCreacion(){
	return fechaCreacion;
}
Hora Grupo::gethoraCreacion(){
	return horaCreacion;
}
void Grupo::setnomGrupo(String nombre){
	this->nomGrupo = nombre;
}
void Grupo::setimagenGrupo(String imagen){
	this->imagenGrupo = imagen;
}
void Grupo::setfechaCreacion(Fecha fechaCreacion){
	this->fechaCreacion = fechaCreacion;
}
void Grupo::sethoraCreacion(Hora horaCreacion){
	this->horaCreacion = horaCreacion;
}