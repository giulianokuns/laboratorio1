#include "../../cpp/Controllers/CtrlUsuario.h"

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

bool CtrlUsuario::ingresar(IKey numero){

	if (usuarioLog == NULL){

		for (IIterator *it = usuarios->getIterator(); it->hasCurrent() and it->getCurrent()->gettelCel !=  numero.getVal(); it->next());

		if(it->hasCurrent()){

			Fecha fch = new Fecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());
			Hora hr = new Hora(HoraSistema::getHora(),HoraSistema::getMinutos());

			usuarioLog = it->getCurrent();
			usuarioLog->sethoraUltimaConex(hr);
			usuarioLog->setfechaUltimaConex(fch);

			return true;

		}else{

			throw std::invalid_argument('El usuario no existe');
			return false
		}

	}else{

		if(usuarioLog->gettelCel() != numero){

			throw std::invalid_argument('Cierre Guasap antes de entrar con otro numero');

		}else{

			return true // en caso de ser numeros iguales, no se hace nada

		}
	}
}

DtFecha CtrlUsuario::altaUsuario(IKey numero, string nombre, string URL,string Descripcion){

	Fecha fch = new Fecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());
	Hora hr = new Hora(HoraSistema::getHora(),HoraSistema::getMinutos());

	Usuario usrnew = new Usuario(numero,nombre,fch,URL,fch,hr,new List(),new List(),new List());

	usuarios->add(usrnew);
	usuarioLog = &usrnew;

	DtFecha retorno = new DtFecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());

	return retorno;	
}

ICollection CtrlUsuario::getNotificaciones(){
	return usuarioLog->getNotificaciones();
};

void CtrlUsuario::eliminarNotificaciones(){
	usuarioLog->eliminarNotificaciones();
};

void CtrlUsuario::agregarSuscriptor(ISuscriptos *s){
    
    usr = usuarios->find(new string(s->gettelCel));
    usr->agregarSuscriptor(this->usuarioLog);

};


void CtrlUsuario::eliminarSuscriptor(IKey telCel){
    
    usr = usuarios->find(telCel);
    usr->eliminarSuscriptor(new string(usuarioLog->gettelCel));
}; 

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


ICollection CtrlUsuario::listarArchivadas(){
 	Usuario * u = usuarioLog;
 	ICollection conv_arhivadas = u.getListaArchivadas();
	return conv_arhivadas;
}

	/*archivar_conversacion*/
ICollection CtrlUsuario::listarActivas(){
 	Usuario u = getusuariolog();
 	ICollection coleccion = u.get_lista_activos();
 	return coleccion;
}

 void CtrlUsuario::archivar_conversacion(IKey ID){
 	Usuario u = getusuariolog();
 	u->archivar(ID);
 }
 	/*agregarContacto*/
 ICollection CtrlUsuario::getContactos(){
 	Usuario u = getusuariolog();
 	return u->getIfoContactos();
 }
 bool CtrlUsuario::existeUsuario(IKey telCel){
 	IDictionary usuarios = getusuarios();
 	return usuarios->member(telCel);
}
bool CtrlUsuario::esContacto(telCel){
	Usuario u = getusuariolog();
	return u->esContacto(telCel);
}
DtInfoContacto CtrlUsuario::agregarContacto(IKey telCel){
	Usuario u = getusuariolog();
	return u->getIfoContacto(telCel);
}
void CtrlUsuario::confirmarAgregarContacto(IKey telCel){
	IDictionary usuarios = getusuarios();
	Usuario u = find(telCel);
	agregarContacto(u);
}

ICollection CtrlUsuario::mensajesCoversacion (IKey idConv) {
	Usuario * user_log = usuarioLog;
	if (user_log != NULL) {
		return user_log->mensajesConversacion(idConv);
	}

	throw std::invalid_argument("No hay un usuario logeado");
}

int CtrlUsuario::cantidadArchivadas () {
	Usuario * user_log = usuarioLog;
	
	int cant_archivadas = user_log->getCantidadArchivadas();
	return cant_archivadas;
}

ICollection CtrlUsuario::obtenerInfoAdicional(IKey codigo) {
	Usuario * user_log = usuarioLog;

	ICollection receptores = user_log->getReceptores(IKey codigo);
	return receptores;
}

void CtrlUsuario::eliminarMensaje (IKey codigo, IKey idConv) {
	Usuario * user_log = usuarioLog;
	u->eliminarMensaje(IKey codigo, IKey idConv);
}

//Enviar mensaje
IKey CtrlUsuario::crearConvNueva(IKey tel ,Ikey converID){
	// Se crea la conversación nueva con el id de conversación
	//autogenerado por el sistema, el usuario logeado y el
	//usuario asociado a la IKet tel.
    IDictionary *participantes = new OrderedDictionary();
    participantes->add(this->getusuarioLog()->gettelCel() ,this->getusuarioLog());
    IDictionary ar_usu = getusuarios();
    participantes->add(tel ,ar_usu->find(tel)); 
    Conversacion c = new Conversacion(false, converID, false, NULL, participantes);

    //Se crea un nuevo estado de conversación, con la conversación
    //anteriormente creada y se lo asocia a los participantes.
    Usuario log = this->getusuarioLog();
    IDictionary ar_ec = log->getarreglo_ec();
    ICollectible ec = new EstadoConversacion(false,c);
    ar_ec->add(converID, ec);

    Usuario participante = ar_usu->find(tel);
    ICollectible ec2 = new EstadoConversacion(false,c)
    IDictionary *ar_ecTel = participante->getarreglo_ec();
    ar_ecTel->add(converID, ec2);

    return converID;
}
