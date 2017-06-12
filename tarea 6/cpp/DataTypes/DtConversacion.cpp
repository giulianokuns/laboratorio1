DtConversacion::DtConversacion(bool esGrupo,string nombre,string telcel){
	this->esGrupo = esGrupo;
	this->nombre = nombre;
	this->telcel = telcel;
}
bool DtConversacion::getesGrupo(){
	return esGrupo;
}
string DtConversacion::getnombre(){
	return nombre;
}
string DtConversacion::gettelcel(){
	return telcel;
}
