
Conversacion::Conversacion(bool visto,string idConversacion,bool esGrupo,Grupo grupo,Usuario receptor){
	this->visto = visto;
	this->idConversacion = idConversacion;
	this->esGrupo = esGrupo;
	this->grupo = grupo;
	this->receptor = receptor;
}
bool Conversacion::getvisto(){
	return visto;
}
string Conversacion::getidConversacion(){
	return idConversacion;
}
bool Conversacion::getesGrupo(){
	return esGrupo;

}
Grupo Conversacion::getgrupo(){
	return grupo;
}
Usuario Conversacion::getreceptor(){
	return receptor;
}
void Conversacion::setvisto(bool visto){
	this->visto = visto;
}
void Conversacion::setidConversacion(string ID){
	this->idConversacion = ID;
}
void Conversacion::setesGrupo(bool esgrupo){
	this->esGrupo = esgrupo;
}
void Conversacion::setgrupo(Grupo g){
	this->grupo = grupo;
}
void Conversacion::setreceptor(Usuario u){
	this->receptor = receptor;
}
	/*archivar_conversacion*/
DtConversacion Conversacion::getinfo(){
	DtConversacion *dtc;
	if(getesGrupo()){
		Grupo g = getgrupo();
		dtc = new DtConversacion(true,g->getnomGrupo(),0000,getidConversacion());
	}
	else{
		Usuario u = getreceptor();
		dtc = new DtConversacion(false,u->getnomUsuario,u->gettelCel,getidConversacion());
	}
	return dtc;
}