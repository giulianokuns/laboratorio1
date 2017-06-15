#include "Fecha.h"
#include "Hora.h"
#include "Recibido.h"
#include "DtInfoIngreso.h"

#include "IDictionary.h"

#ifndef MENSAJES
#define MENSAJES

using namespace std;

class Mensaje {
	private:
		String codigo;
		Fecha fechaMensaje;
		Hora horaMensaje;
		IDictionary recibidos;

	public:
		String getcodigo();
		Fecha getfechaMensaje();
		Hora gethoraMensaje();
		IDictionary getRecibidos();

		void setcodigo(String codigo);
		void setfechaMensaje(Fecha fechaMensaje);
		void sethoraMensaje(Hora horaMensaje);
		void setRecibidos(IDictionary recibidos);		

		bool validarFechaHoraMensaje(DtInfoIngreso fecha_hora_ingreso);
}

#endif