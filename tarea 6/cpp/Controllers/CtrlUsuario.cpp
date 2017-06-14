//instancia = NULL

#include "Fecha.h"
#include "Hora.h"
#include "Usuario.h"
#include "Mensaje.h"
#include "CtrlUsuario.h"

/*Singleton*/
CtrlUsuario * CtrlUsuario::getinstancia(){

	if(instancia == NULL)
		this->instancia = new CtrlUsuario();
	return instancia;
}


/*Cerrar Guasap*/

void CtrlUsuario::cerrarGuasap(){

	Fecha fch = FechaSistema->getFecha();
	Hora hr = HoraSistema->getHora();

	usuarioLog->setfechaUltimaConex(fch);
	usuarioLog->sethoraUltimaConex(hr);

	this->usuarioLog = NULL;
}


Usuario * CtrlUsuario::getusuarioLog(){
	return usuarioLog;
}
IDictionary CtrlUsuario::getusuarios(){
	return usuarios;
}
void CtrlUsuario::setusuarioLog(Usuario * u){
	this->usuarioLog = u;
}
void CtrlUsuario::setusuarios(IDictionary lista_usuarios){
	this->usuarios = lista_usuarios;
}

	/*archivar_conversacion*/
 ICollection CtrlUsuario::listarActivas(){
 	Usuario u = getusuariolog();
 	ICollection coleccion = u.get_lista_activos();
 	return coleccion;
 }

 void CtrlUsuario::archivar_conversacion(String ID){
 	Usuario u = getusuariolog();
 	u->archivar(ID);
 }
 	/*agregarContacto*/
 ICollection CtrlUsuario::getContactos(){
 	Usuario u = getusuariolog();
 	return u->getIfoContactos();
 }
 bool CtrlUsuario::existeUsuario(String telCel){
 	IDictionary usuarios = getusuarios();
 	return usuarios->member(telCel);
}
bool CtrlUsuario::esContacto(telCel){
	Usuario u = getusuariolog();
	return u->esContacto(telCel);
}
DtInfoContacto CtrlUsuario::agregarContacto(telcel){
	Usuario u = getusuariolog();
	return u->getIfoContacto(telCel);
}
void CtrlUsuario::confirmarAgregarContacto(telcel){
	IDictionary usuarios = getusuarios();
	Usuario u = find(telCel);
	agregarContacto(u);
}

ICollection CtrlUsuario::mensajesCoversacion (int idConv) {
	//Usuario logeado
	Usuario * user_log = usuarioLog;
	return Usuario::mensajesConversacion(idConv);	
}