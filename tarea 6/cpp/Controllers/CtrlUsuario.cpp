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

	Fecha fch = new Fecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());
	Hora hr = new Hora(HoraSistema::getHora(),HoraSistema::getMinutos());

	usuarioLog->setfechaUltimaConex(fch);
	usuarioLog->sethoraUltimaConex(hr);

	this->usuarioLog = NULL;
}


/*Abrir Guasap*/

bool CtrlUsuario::inicioSesion(){
	return usuarioLog == NULL
}

bool CtrlUsuario::ingresar(String numero){

	if (usuarioLog == NULL){

		//Buscar usuario y ver si existe (ver como hacer el iterador)

	}else{

		if(usuarioLog->gettelCel() != numero){

			//Levantar excepcion de cerrar guasap para entrar con otro numero

		}else{

			return true // en caso de ser numeros iguales, no se hace nada

		}
	}
}

DtFecha CtrlUsuario::altaUsuario(String numero, String nombre, String URL,String Descripcion){

	Fecha fch = new Fecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());
	Hora hr = new Hora(HoraSistema::getHora(),HoraSistema::getMinutos());

	Usuario usrnew = new Usuario(numero,nombre,fch,URL,fch,hr,NULL/*ICollection arreglo_ec*/,NULL/*ICollection arreglo_ec*/,IDictionary contactos);

	/*VER COMO AÑADIR USUARIO A LA COLECCION*/

	DtFecha retorno = new DtFecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());

	return retorno;

	
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
	if (user_log != NULL) {
		return user_log->mensajesConversacion(idConv);
	}
	// Usuario no logeado, exception de contratos
	return false;
}