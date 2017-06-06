#include "Fecha.h"
#include "Hora.h"


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