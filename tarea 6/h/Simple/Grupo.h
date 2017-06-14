#include "Fecha.h"
#include "Hora.h"


class Grupo{
	private:
		String nomGrupo;
		String imagenGrupo;
		Fecha fechaCreacion;
		Hora horaCreacion;
	public:
		String getnomGrupo();
		String getimagenGrupo();
		Fecha getfechaCreacion();
		Hora gethoraCreacion();
		void setnomGrupo(String nombre);
		void setimagenGrupo(String imagen);
		void setfechaCreacion(Fecha fechaCreacion);
		void sethoraCreacion(Hora horaCreacion);
}