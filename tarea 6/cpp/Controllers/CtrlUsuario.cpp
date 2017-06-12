//instancia = NULL

#include "Fecha.h"
#include "Hora.h"
#include "Usuario.h"
#include "Mensaje.h"

Usuario * CtrlUsuario::getusuarioLog(){
	return usuarioLog;
}
void CtrlUsuario::setusuarioLog(Usuario * u){
	this->usuarioLog = u;
}

	/*archivar_conversacion*/
 ICollection CtrlUsuario::listarActivas(){
 	Usuario u = getusuariolog();
 	ICollection coleccion = u.get_lista_activos();
 	return coleccion;
 }