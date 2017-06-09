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
	public:
		Usuario(string telCel,string nomUsuario,Fecha fechaRegistro,string imaPerfil,Fecha fechaUltimaConex,Hora horaUltimaConex);
		~Usuario();
		string gettelCel();
		string getnomUsuario();
		Fecha getfechaRegistro();
		string getimaPerfil();
		Fecha getfechaUltimaConex();
		Hora gethoraUltimaConex();
		void settelCel(string cel);
		void setnomUsuario(string nombre);
		void setfechaRegistro(Fecha fechaRegistro);
		void setimaPerfil(string URL);
		void setfechaUltimaConex(Fecha fechaUltimaConex);
		void sethoraUltimaConex(Hora horaUltimaConex);		
}