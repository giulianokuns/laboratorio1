#include "../../h/Simple/Usuario.h"
#include "../../h/Simple/Conversacion.h"
#include "../../h/Simple/EstadoConversacion.h"
#include "../../h/Simple/FechaSistema.h"
#include "../../h/Simple/HoraSistema.h"

Usuario::Usuario(IKey *telCel, string nomUsuario, Fecha fechaRegistro, string imaPerfil, Fecha fechaUltimaConex, Hora horaUltimaConex, IDictionary *arreglo_ec, IDictionary *contactos, IDictionary *notificaciones, IDictionary *suscriptores){
	
	this->telCel = telCel;
	this->nomUsuario = nomUsuario;
	this->fechaRegistro = fechaRegistro;//no se crea una instancia nueva 
	this->imaPerfil = imaPerfil;
	this->fechaUltimaConex = fechaUltimaConex;//no se crea una instancia nueva
	this->horaUltimaConex = horaUltimaConex;//no se crea una instancia nueva
	this->arreglo_ec = arreglo_ec;
	this->contactos = contactos;
	this->notificaciones = notificaciones;
	this->suscriptores = suscriptores;
}
Usuario::~Usuario(){
	
}


IKey *Usuario::gettelCel(){
	return telCel;
}

string Usuario::getnomUsuario(){
	return nomUsuario;
}

Fecha Usuario::getfechaRegistro(){
	return fechaRegistro;
}

string Usuario::getimaPerfil(){
	return imaPerfil;
}

Fecha Usuario::getfechaUltimaConex(){
	return fechaUltimaConex;
}

Hora Usuario::gethoraUltimaConex(){
	return horaUltimaConex;
}

IDictionary *Usuario::getarreglo_ec(){
	return arreglo_ec;
}
IDictionary *Usuario::getcontactos(){
	return contactos;
}
IDictionary *Usuario::getMensajes(){
	return mensajes;
}

void Usuario::settelCel(IKey *cel){
	this->telCel = cel;
}

void Usuario::setnomUsuario(string nombre){
	this->nomUsuario = nombre;
}

void Usuario::setfechaRegistro(Fecha fechaRegistro){
	this->fechaRegistro = fechaRegistro;
}

void Usuario::setimaPerfil(string URL){
	this->imaPerfil = URL;
}
void Usuario::setfechaUltimaConex(Fecha fechaUltimaConex){
	this->fechaUltimaConex = fechaUltimaConex;
}
void Usuario::sethoraUltimaConex(Hora horaUltimaConex){
	this->horaUltimaConex = horaUltimaConex;
}
void Usuario::setarreglo_ec(IDictionary *arreglo_ec){
	this->arreglo_ec = arreglo_ec;
}
void Usuario::setcontactos(IDictionary *contactos){
	this->contactos = contactos;
}
void Usuario::setMensajes(IDictionary *mensajes){
	this->mensajes = mensajes;
}

ICollection *getListaArchivadas() {
	IDictionary * ec_array = arreglo_ec;
	ICollection *list_archivadas = new List();
	for (IIterator *it = ec_array->getIterator(); it->hasCurrent(); it->next()) {
		EstadoConversacion *ec = dynamic_cast<EstadoConversacion * > (it->getCurrent());
		if (ec->getarchivada()) {
			Conversacion c = ec->getconversacion();
			DtConversacion *dtc = c.getinfo();
			list_archivadas->add(dtc);
		}
	}
	return list_archivadas;
}

/*archivar_conversacion*/
ICollection *Usuario::get_lista_activos(){
	IDictionary *arreglo_ec = getarreglo_ec();
	ICollection *colecciondt = new List();
	for (IIterator *it = arreglo_ec->getIterator(); it->hasCurrent(); it->next()) {
		EstadoConversacion *ec = dynamic_cast<EstadoConversacion * > (it->getCurrent());
		if (!ec->getarchivada()) {
			Conversacon c = ec.getconversacion();
			DtConversacion dtc = c.getinfo();
			colecciondt->add(dtc);
		}
	}
	return colecciondt;
}

void Usuario::archivar(IKey *ID){
	IDictionary *arreglo_ec = getarreglo_ec();
	EstadoConversacion *ec = dynamic_cast<EstadoConversacion * > (arreglo_ec->find(ID));
	ec->setarchivada(true);
}
	/*agregarContacto*/
ICollection *Usuario::getInfoContactos(){
	IDictionary *contactos = getcontactos();
	ICollection *lista_dtInfoContacto = new List();
	for (IIterator *it = contactos->getIterator(); it->hasCurrent(); it->next()) {
		Usuario  * u = dynamic_cast<Usuario * > (it->getCurrent());
		DtInfoContacto *dt = new DtInfoContacto(u->getnomUsuario(), u->gettelCel(), u->getimaPerfil());
		lista_dtInfoContacto->add(dt);
	}
	return lista_dtInfoContacto;
}
bool Usuario::esContacto(IKey *telCel){
	IDictionary *contactos = getcontactos();
	return contactos->member(telCel);
}
DtInfoContacto Usuario::getIfoContacto(IKey *telCel){
	IDictionary *contactos = getcontactos();
	Usuario  * u = dynamic_cast<Usuario * > (contactos->find(telCel));
	DtInfoContacto dt = new DtInfoContacto(u->getnomUsuario(), u->gettelCel(), u->getimaPerfil());
	return dt;
}
void Usuario::agregarContacto(Usuario u){
	IDictionary *set_contactos = getcontactos();
	set_contactos->add(telCel,u);
}

ICollection *Usuario::mensajesCoversacion (IKey *idConv) {
	IDictionary * ec_array = this->getarreglo_ec();
	Conversacion c = NULL;
	
	// Una vez obtiene la conversacion sale del for
	for (IIterator *it = ec_array->getIterator(); (it->hasCurrent() && c == NULL); it->next()) {
		EstadoConversacion *ec = dynamic_cast<EstadoConversacion * > (it->getCurrent());
		Conversacion c = ec.compararConv(idConv);
	}
	
	es_grupo = c.getesGrupo();
	if (es_grupo) {
		ICollection	*mensajes = c.obtenerMensajesGrupo(); 
	} else {
		ICollection	*mensajes = c.obtenerMensajesConv(); 
	}

	return mensajes
}

int Usuario::getCantidadArhivadas() {
	IDictionary * ec_array = this->getarreglo_ec();
	int cant_archivadas = 0;

	for (IIterator *it = ec_array->getIterator(); it->hasCurrent(); it->next()) {
		EstadoConversacion *ec = dynamic_cast<EstadoConversacion * > (it->getCurrent());
		bool esta_archivada = ec->getarchivada();
		if (esta_archivada) {
			cant_archivadas++;
		}
	}

	return cant_archivadas;
}

ICollection *Usuario::getReceptores(IKey *codigo) {
	IDictionary arr_mensj = this->getMensajes();
	Mensaje  * m = dynamic_cast<Mensaje * > (arr_mensj.find(codigo));
	if (m != NULL) {
		ICollection receptores = m->getReceptores();
	} else {
		throw std::invalid_argument('Mensaje seleccionado invalido, por favor, seleccione un mensaje enviado por usted');
	}
}

void Usuario::eliminarMensaje (IKey *codigo, IKey *idConv) {	
	IDictionary *arr_mensj = this->getMensajes();
	bool es_emisor 	= arr_mensj.member(codigo);
	bool es_mensaje = false;

	Mensaje mensj 	  = NULL;
	Conversacion conv = NULL;

	//Busca la conversacion que tiene el mensaje con ese codigo
	IDictionary * arr_ec = this->getarreglo_ec();
	if (!arr_ec->isEmpty()) {
		for (IIterator *it = arr_ec->getIterator(); (it->hasCurrent() && !es_mensaje); it->next()) {
			EstadoConversacion *ec = dynamic_cast<EstadoConversacion * > (it->getCurrent());
			Conversacion * conv = ec->getconversacion();
			if (idConv.compare(conv->getidConversacion())) {
				IDictionary mensajes = conv->getMensajes();
				
				Mensaje  * mensj= dynamic_cast<Mensaje * > (mensajes.find(codigo));
				if (mensj != NULL && codigo.compare(mensj->getcodigo())) {
					es_mensaje = true;
				}
			}
		}
		if (!es_mensaje) {
			throw std::invalid_argument('Error: Mensaje invalido');
		}

		if (es_emisor) {
			mensj.eliminarMensajeEmisor();
		} else {
			mensj.eliminarMensajeReceptor(conv);
		}
	} else { 	
		throw std::invalid_argument('No tiene conversaciones.');
	}
}

		
ICollection *Usuario::getNotificaciones(){
     
    return this->notificaciones;
    
}

void Usuario::eliminarNotificaciones(){
    this->notificaciones->clear();
};


void Usuario::agregarSuscriptor(ISuscriptos *s){
    this->suscriptores->add(s);
};

void Usuario::eliminarSuscriptor(IKey *telCel){
    this->suscriptores->remove(telCel);    
};

void Usuario::agregarNotificacion(DtNotificaciones notificacion){
    this->notificaciones->add(notificacion);
};

void Usuario::agregarNotificaciones(DtNotificaciones notificacion){
    
    for (IIterator *it = this->suscriptores->getIterator(); it->hasCurrent(); it->next()){
        Usuario  * u = dynamic_cast<Usuario * > (it->getCurrent());
        u->agregarNotificacion(notificacion);
        
    }
        
};


