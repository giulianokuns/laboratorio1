#include "Fecha.h"
#include "Hora.h"


class Usuario: public ICollectible{
	private:
		string telCel;
		string nomUsuario;
		Fecha fechaRegistro;
		string imaPerfil;
		Fecha fechaUltimaConex;
		Hora horaUltimaConex;
		ICollection arreglo_ec;
	public:
		Usuario(string telCel,string nomUsuario,Fecha fechaRegistro,string imaPerfil,Fecha fechaUltimaConex,Hora horaUltimaConex,ICollection arreglo_ec);
		~Usuario();
		string gettelCel();
		string getnomUsuario();
		Fecha getfechaRegistro();
		string getimaPerfil();
		Fecha getfechaUltimaConex();
		Hora gethoraUltimaConex();
		ICollection getarreglo_ec();
		void settelCel(string cel);
		void setnomUsuario(string nombre);
		void setfechaRegistro(Fecha fechaRegistro);
		void setimaPerfil(string URL);
		void setfechaUltimaConex(Fecha fechaUltimaConex);
		void sethoraUltimaConex(Hora horaUltimaConex);
		void setarreglo_ec(ICollection arreglo_ec);
		/*archivar_conversacion*/
		ICollection get_lista_activos();	
}