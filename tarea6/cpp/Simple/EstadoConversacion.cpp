#include "../../h/Simple/EstadoConversacion.h"

EstadoConversacion::EstadoConversacion(bool archivada, Conversacion c):conversacion(c.getvisto(),c.getidConversacion(),c.getesGrupo(),c.getgrupo(),c.getparticipantes(),c.getMensajes()){
	this->archivada = archivada;
	this->conversacion = c;
}
EstadoConversacion::~EstadoConversacion(){

}
bool EstadoConversacion::getarchivada(){
	return archivada;
}
Conversacion EstadoConversacion::getconversacion(){
	return conversacion;
}
void EstadoConversacion::setarchivada(bool archivada){
	this->archivada = archivada;
}
void EstadoConversacion::setconversacion( Conversacion c){
	this->conversacion = c;
}

/* 
	Compara el id conversacion asociada a un estado de conversacion con 
	el idConv recibido.
	Si son iguales devuelve un puntero a la Conversacion
	NULL en otro caso.
*/
Conversacion * EstadoConversacion::compararConv (IKey *idConv) {
	Conversacion c  = this->getconversacion();
	if (c.getidConversacion() == idConv) {
		return c;
	} else {
		return NULL;
	}
}