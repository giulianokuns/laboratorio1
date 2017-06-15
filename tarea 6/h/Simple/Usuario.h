#include "Fecha.h"
#include "Hora.h"
#include "IDictionary.h"

#ifndef USUARIO
#define USUARIO

using namespace std;

class Usuario: public ICollectible{
	private:
		String telCel;
		String nomUsuario;
		Fecha fechaRegistro;
		String imaPerfil;
		Fecha fechaUltimaConex;
		Hora horaUltimaConex;
		/*la key con la que se almacenan es el ID de su correspondiente conversacion para facilitar la busqueda*/
		IDictionary arreglo_ec;
		/*se almacenan con la key correspondiente a su numero de telefono*/
		IDictionary contactos;
	public:
		Usuario(String telCel,String nomUsuario,Fecha fechaRegistro,String imaPerfil,Fecha fechaUltimaConex,Hora horaUltimaConex,ICollection arreglo_ec, IDictionary contactos);
		~Usuario();
		
		String gettelCel();
		String getnomUsuario();
		Fecha getfechaRegistro();
		String getimaPerfil();
		Fecha getfechaUltimaConex();
		Hora gethoraUltimaConex();
		IDictionary getarreglo_ec();
		IDictionary getcontactos();
		
		void settelCel(String cel);
		void setnomUsuario(String nombre);
		void setfechaRegistro(Fecha fechaRegistro);
		void setimaPerfil(String URL);
		void setfechaUltimaConex(Fecha fechaUltimaConex);
		void sethoraUltimaConex(Hora horaUltimaConex);
		void setarreglo_ec(ICollection arreglo_ec); // ????? ICollection bien ?
		void setcontactos(IDictionary contactos);
		
		/*archivar_conversacion*/
		ICollection get_lista_activos();
		void archivar(String ID);	
		
		/*agregarContacto*/
		ICollection getInfoContactos();
		bool esContacto(telCel);
		DtInfoContacto getIfoContacto(telCel);
		void agregarContacto(Usuario u);
		
		/* Ver Mensaje */
		ICollection mensajesCoversacion (int idConv);
}

#endif