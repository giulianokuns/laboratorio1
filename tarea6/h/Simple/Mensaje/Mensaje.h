#include "../Fecha.h"
#include "../Hora.h"
#include "../Recibido.h"

#include "../../DataTypes/DtInfoIngreso.h"
#include "../../DataTypes/DtReceptor.h"

#include "../../../lab6-colecciones/interfaces/IKey.h"
#include "../../../lab6-colecciones/interfaces/ICollectible.h"
#include "../../../lab6-colecciones/interfaces/ICollection.h"
#include "../../../lab6-colecciones/interfaces/IDictionary.h"

#ifndef MENSAJES
#define MENSAJES

using namespace std;
class Recibido;

class Mensaje : public ICollectible {
	private:
		IKey *codigo; 
		Fecha *fechaMensaje;
		Hora *horaMensaje;
		//El IKey es el telcel del usuario asociado.
		IDictionary *recibidos;

	public:
		IKey 		*getcodigo();
		Fecha 		*getfechaMensaje();
		Hora  		*gethoraMensaje();
		IDictionary *getRecibidos();

		void setcodigo(IKey *codigo);
		void setfechaMensaje(Fecha *fechaMensaje);
		void sethoraMensaje(Hora *horaMensaje);
		void setRecibidos(IDictionary *recibidos);		

		bool validarFechaHoraMensaje(DtInfoIngreso fecha_hora_ingreso);
		ICollection *getReceptores();
		void eliminarMensajeEmisor();
		void eliminarMensajeReceptor(Conversacion * conversacion);
};

#endif
