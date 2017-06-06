#include "Fecha.h"
#include "Hora.h"


class Grupo{
	private:
		string nomGrupo;
		string imagenGrupo;
		Fecha fechaCreacion;
		Hora horaCreacion;
	public:
		string getnomGrupo();
		string getimagenGrupo();
		Fecha getfechaCreacion();
		Hora gethoraCreacion();
		void setnomGrupo(string nombre);
		void setimagenGrupo(string imagen);
		void setfechaCreacion(Fecha fechaCreacion);
		void sethoraCreacion(Hora horaCreacion);
}