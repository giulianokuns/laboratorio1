#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Fecha.h"
#include "Hora.h"

#include "../DataTypes/DtConversacion.h"
#include "../DataTypes/DtInfoContacto.h"
#include "../DataTypes/DtNotificaciones.h"
#include "../Interfaces/ISuscriptos.h"

#include "../../lab6-colecciones/interfaces/IKey.h"
#include "../../lab6-colecciones/interfaces/IDictionary.h"
#include "../../lab6-colecciones/interfaces/ICollection.h"
#include "../../lab6-colecciones/collections/List.h"

#ifndef USUARIO
#define USUARIO

class Conversacion;
class FechaSistema;
class HoraSistema;

using namespace std;
class Conversacion;

class Usuario: public ICollectible, public ISuscriptos{
	private:
		IKey *telCel;
		string nomUsuario;
		Fecha fechaRegistro;
		string imaPerfil;
		Fecha fechaUltimaConex;
		Hora horaUltimaConex;
		/*la key con la que se almacenan es el ID de su correspondiente conversacion para facilitar la busqueda*/
		IDictionary *arreglo_ec;
		/*se almacenan con la key correspondiente a su numero de telefono*/
		IDictionary *contactos;
		/* Key : Codigo */
		IDictionary *mensajes;
		/*notificaciones de suscriptores*/
		ICollection *notificaciones;
        ICollection *suscriptores;

	public:
		Usuario::Usuario(IKey *telCel, string nomUsuario, Fecha fechaRegistro, string imaPerfil, Fecha fechaUltimaConex, Hora horaUltimaConex,ICollection *arreglo_ec, IDictionary *contactos, ICollection *notificaciones,ICollection *suscriptores);
		~Usuario();
		
		IKey *gettelCel();
		string getnomUsuario();
		Fecha getfechaRegistro();
		string getimaPerfil();
		Fecha getfechaUltimaConex();
		Hora gethoraUltimaConex();
		IDictionary *getarreglo_ec();
		IDictionary *getcontactos();
		IDictionary *getMensajes();

		void settelCel(IKey *cel);
		void setnomUsuario(string nombre);
		void setfechaRegistro(Fecha fechaRegistro);
		void setimaPerfil(string URL);
		void setfechaUltimaConex(Fecha fechaUltimaConex);
		void sethoraUltimaConex(Hora horaUltimaConex);
		void setarreglo_ec(IDictionary *arreglo_ec);
		void setcontactos(IDictionary *contactos);
		void setMensajes(IDictionary *mensajes);		

		ICollection *getListaArchivadas();

		/*archivar_conversacion*/
		ICollection *get_lista_activos();
		void archivar(IKey *ID);	
		
		/*agregarContacto*/
		ICollection 	*getInfoContactos();
		DtInfoContacto 	getIfoContacto(IKey *telCel);
		bool esContacto(IKey *telCel);
		void agregarContacto(Usuario u);
		
		/* Ver Mensaje */
		ICollection *mensajesCoversacion (IKey *idConv);
		int getCantidadArhivadas();
		ICollection *getReceptores(IKey *codigoMensaje);

		/* Eliminar Mensaje */
		void eliminarMensaje (IKey *codigo, IKey *idConv);

		/* Suscripciones */
		ICollection *getNotificaciones();
		void eliminarNotificaciones();
		void agregarSuscriptor(ISuscriptos *s);
		void eliminarSuscriptor(IKey *telCel);
		void agregarNotificacion(DtNotificaciones notificacion);
        void agregarNotificaciones(DtNotificaciones notificacion);

};

#endif
