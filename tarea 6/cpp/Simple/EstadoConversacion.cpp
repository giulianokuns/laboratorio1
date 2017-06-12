
EstadoConversacion::EstadoConversacion(bool archivada, Conversacion c){
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