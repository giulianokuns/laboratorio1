#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Grupo.h"
#include "Usuario.h"
#include "Mensaje/Mensaje.h"
#include "Mensaje/Simple.h"
#include "Mensaje/Contacto.h"
#include "Mensaje/Imagen.h"
#include "Mensaje/Video.h"
#include "Recibido.h"
#include "InfoIngreso.h"

#include "../../../lab6-colecciones/interfaces/ICollection.h"
#include "../../../lab6-colecciones/interfaces/IDictionary.h"

#ifndef CONVERSACION
#define CONVERSACION

using namespace std;

class Conversacion {
	private:
		bool visto;
		IKey *idConversacion;
		bool esGrupo;
		Grupo grupo;
		IDictionary *participantes;
		// Mensjaes almacenados por Key Codigo.
		IDictionary *mensajes;

	public:
		Conversacion(bool visto, IKey *idConversacion, bool esGrupo, Grupo grupo, IDictionary *participantes,IDictionary *mensajes);
		~Conversacion();

		bool 	getvisto();
		IKey 	*getidConversacion();
		bool 	getesGrupo();
		Grupo 	getgrupo();
		IDictionary *getparticipantes();
		IDictionary *getMensajes();

		void setvisto(bool visto);
		void setidConversacion(IKey *idConv);
		void setesGrupo(bool esgrupo);
		void setgrupo(Grupo g);
		void setparticipantes(IDictionary *participantes);
		void setMensajes(IDictionary *mensajes);

		/* Archivar conversacion*/
		DtConversacion getinfo();

		/* Ver Mensajes */
		ICollection *obtenerMensajesGrupo();
		ICollection *obtenerMensajesConv();
};

#endif