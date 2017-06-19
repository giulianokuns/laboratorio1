#include "../../h/Simple/Fecha.h"
#include "../../h/Simple/Hora.h"
#include "../../h/Simple/Grupo.h"

Grupo::Grupo(string nomGrupo, string imagenGrupo,	Fecha fechacreacion,	Hora horacreacion,	IDictionary *infoIngresos): fechaCreacion(fechacreacion.getdia(), fechacreacion.getmes(), fechacreacion.getanio()), horaCreacion(horacreacion.gethoras(), horacreacion.getminutos()){
	this->nomGrupo = nomGrupo;
	this->imagenGrupo = imagenGrupo;
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