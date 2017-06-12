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
		/*la key con la que se almacenan es el ID de su correspondiente conversacion para facilitar la busqueda*/
		IDictionary arreglo_ec;
		/*se almacenan con la key correspondiente a su numero de telefono*/
		IDictionary contactos;
	public:
		Usuario(string telCel,string nomUsuario,Fecha fechaRegistro,string imaPerfil,Fecha fechaUltimaConex,Hora horaUltimaConex,ICollection arreglo_ec, IDictionary contactos);
		~Usuario();
		string gettelCel();
		string getnomUsuario();
		Fecha getfechaRegistro();
		string getimaPerfil();
		Fecha getfechaUltimaConex();
		Hora gethoraUltimaConex();
		IDictionary getarreglo_ec();
		IDictionary getcontactos();
		void settelCel(string cel);
		void setnomUsuario(string nombre);
		void setfechaRegistro(Fecha fechaRegistro);
		void setimaPerfil(string URL);
		void setfechaUltimaConex(Fecha fechaUltimaConex);
		void sethoraUltimaConex(Hora horaUltimaConex);
		void setarreglo_ec(ICollection arreglo_ec);
		void setcontactos(IDictionary contactos);
		/*archivar_conversacion*/
		ICollection get_lista_activos();
		void archivar(string ID);	
		/*agregarContacto*/
		ICollection getInfoContactos();
		bool esContacto(telCel);
		DtInfoContacto getIfoContacto(telCel);
		void agregarContacto(Usuario u);
}