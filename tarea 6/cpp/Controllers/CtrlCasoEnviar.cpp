#include "CtrlUsuario.h"
#include "Mensaje.h"
#include "Usuario.h"

int cantidadArchivadas(){
	return (this->getCtrlUsuario()).cantidadArchivadas();
}

ListaDtConversacion * listarArchivadas(){
	return (this->getCtrlUsuario()).listarArchivadas();
}
	   
ListaDtConversacion * listarActivas(){
	return (this->getCtrlUsuario()).listarActivas();
}
