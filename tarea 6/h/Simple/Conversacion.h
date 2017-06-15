#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Grupo.h"
#include "Usuario.h"
#include "Mensaje.h"
#include "Multimedia.h"
#include "Simple.h"
#include "Contacto.h"
#include "Imagen.h"
#include "Video.h"
#include "Recibido.h"
#include "ICollection.h"
#include "IDictionary.h"


#ifndef CONVERSACION
#define CONVERSACION

using namespace std;

class Conversacion {
	private:
		bool visto;
		String idConversacion;
		bool esGrupo;
		Grupo grupo;
		Usuario receptor;
		// Mensjaes almacenados por Key Codigo.
		IDictionary mensajes;

	public:
		Conversacion(bool visto, String idConversacion, bool esGrupo, Grupo grupo, Usuario receptor);
		~Conversacion();

		bool 	getvisto();
		String 	getidConversacion();
		bool 	getesGrupo();
		Grupo 	getgrupo();
		Usuario getreceptor();
		IDictionary getMensajes();

		void setvisto(bool visto);
		void setidConversacion(String ID);
		void setesGrupo(bool esgrupo);
		void setgrupo(Grupo g);
		void setreceptor(Usuario u);
		void setMensajes(IDictionary mensajes);

		/* Archivar conversacion*/
		DtConversacion getinfo();

		/* Ver Mensajes */
		ICollection obtenerMensajesGrupo();
		ICollection obtenerMensajesConv();
}

#endif