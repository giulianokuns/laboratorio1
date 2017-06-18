#include "Fecha.h"
#include "Hora.h"
#include "DtConversacion.h"

#include "IKey.h"
#include "IDictionary.h"
#include "ICollection.h"

#ifndef USUARIO
#define USUARIO

using namespace std;

class Usuario: public ICollectible, public ISuscriptos{
	private:
		IKey telCel;
		string nomUsuario;
		Fecha fechaRegistro;
		string imaPerfil;
		Fecha fechaUltimaConex;
		Hora horaUltimaConex;
		/*la key con la que se almacenan es el ID de su correspondiente conversacion para facilitar la busqueda*/
		IDictionary arreglo_ec;
		/*se almacenan con la key correspondiente a su numero de telefono*/
		IDictionary contactos;
		/* Key : Codigo */
		IDictionary mensajes;
		/*notificaciones de suscriptores*/
		ICollection notificaciones;

	public:
		Usuario(IKey telCel, string nomUsuario, Fecha fechaRegistro, string imaPerfil, Fecha fechaUltimaConex, Hora horaUltimaConex, ICollection arreglo_ec, IDictionary contactos);
		~Usuario();
		
		IKey gettelCel();
		string getnomUsuario();
		Fecha getfechaRegistro();
		string getimaPerfil();
		Fecha getfechaUltimaConex();
		Hora gethoraUltimaConex();
		IDictionary getarreglo_ec();
		IDictionary getcontactos();
		IDictionary getMensajes();

		void settelCel(IKey cel);
		void setnomUsuario(string nombre);
		void setfechaRegistro(Fecha fechaRegistro);
		void setimaPerfil(string URL);
		void setfechaUltimaConex(Fecha fechaUltimaConex);
		void sethoraUltimaConex(Hora horaUltimaConex);
		void setarreglo_ec(IDictionary arreglo_ec);
		void setcontactos(IDictionary contactos);
		void setMensajes(IDictionary mensajes);		

		ICollection getListaArchivadas();

		/*archivar_conversacion*/
		ICollection get_lista_activos();
		void archivar(IKey ID);	
		
		/*agregarContacto*/
		ICollection 	getInfoContactos();
		DtInfoContacto 	getIfoContacto(IKey telCel);
		bool esContacto(IKey telCel);
		void agregarContacto(Usuario u);
		
		/* Ver Mensaje */
		ICollection mensajesCoversacion (IKey idConv);
		int getCantidadArhivadas();
		ICollection getReceptores(IKey codigoMensaje);

		/* Eliminar Mensaje */
		void eliminarMensaje (IKey codigo, IKey idConv);

		/* Suscripciones */
		ICollection getNotificaciones();
		void eliminarNotificaciones();
		void agregarSuscriptor(ISuscriptos *s);
		void eliminarSuscriptor(IKey telCel);
		void agregarNotificacion(DtNotificaciones notificacion);

}

#endif