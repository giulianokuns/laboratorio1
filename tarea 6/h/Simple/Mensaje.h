#include "Fecha.h"
#include "Hora.h"


class Mensaje{
	private:
		String codigo;
		Fecha fechaMensaje;
		Hora horaMensaje;
	public:
		String getcodigo();
		Fecha getfechaMensaje();
		Hora gethoraMensaje();
		void setcodigo(String codigo);
		void setfechaMensaje(Fecha fechaMensaje);
		void sethoraMensaje(Hora horaMensaje);
}