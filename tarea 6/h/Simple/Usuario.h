#include "Fecha.h"
#include "Hora.h"
#include "DtConversacion.h"

#include "IKey.h"
#include "IDictionary.h"

#ifndef USUARIO
#define USUARIO

using namespace std;

class Usuario: public ICollectible {
	private:
		IKey telCel;
		String nomUsuario;
		Fecha fechaRegistro;
		String imaPerfil;
		Fecha fechaUltimaConex;
		Hora horaUltimaConex;
		/*la key con la que se almacenan es el ID de su correspondiente conversacion para facilitar la busqueda*/
		IDictionary arreglo_ec;
		/*se almacenan con la key correspondiente a su numero de telefono*/
		IDictionary contactos;
		/* Key : Codigo */
		IDictionary mensajes;

	public:
		Usuario(IKey telCel, String nomUsuario, Fecha fechaRegistro, String imaPerfil, Fecha fechaUltimaConex, Hora horaUltimaConex, ICollection arreglo_ec, IDictionary contactos);
		~Usuario();
		
		IKey gettelCel();
		String getnomUsuario();
		Fecha getfechaRegistro();
		String getimaPerfil();
		Fecha getfechaUltimaConex();
		Hora gethoraUltimaConex();
		IDictionary getarreglo_ec();
		IDictionary getcontactos();
		IDictionary getMensajes();

		void settelCel(IKey cel);
		void setnomUsuario(String nombre);
		void setfechaRegistro(Fecha fechaRegistro);
		void setimaPerfil(String URL);
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
		void eliminarMensaje (IKey codigo);

}

#endif