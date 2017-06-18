#include "Fecha.h"
#include "Hora.h"
#include "Recibido.h"
#include "DtInfoIngreso.h"
#include "DtReceptor.h"

#include "IKey.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "IDictionary.h"

#ifndef MENSAJES
#define MENSAJES

using namespace std;

class Mensaje : public ICollectible {
	private:
		IKey codigo; 
		Fecha fechaMensaje;
		Hora horaMensaje;
		//El IKey es el telcel del usuario asociado.
		IDictionary recibidos;

	public:
		IKey getcodigo();
		Fecha getfechaMensaje();
		Hora gethoraMensaje();
		IDictionary getRecibidos();

		void setcodigo(IKey codigo);
		void setfechaMensaje(Fecha fechaMensaje);
		void sethoraMensaje(Hora horaMensaje);
		void setRecibidos(IDictionary recibidos);		

		bool validarFechaHoraMensaje(DtInfoIngreso fecha_hora_ingreso);
		ICollection getReceptores();
		void eliminarMensajeEmisor();
		void eliminarMensajeReceptor(Conversacion * conversacion);
}

#endif