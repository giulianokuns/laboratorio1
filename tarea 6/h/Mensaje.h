#include "Fecha.h"
#include "Hora.h"


class Mensaje{
	private:
		string codigo;
		Fecha fechaMensaje;
		Hora horaMensaje;
	public:
		string getcodigo();
		Fecha getfechaMensaje();
		Hora gethoraMensaje();
		void setcodigo(string codigo);
		void setfechaMensaje(Fecha fechaMensaje);
		void sethoraMensaje(Hora horaMensaje);
}