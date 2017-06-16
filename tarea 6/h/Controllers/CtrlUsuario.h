#include "Usuario.h"

class CtrlUsuario{

	private:
		static CtrlUsuario * instancia = NULL;
		CtrlUsuario();
		Usuario * usuarioLog = NULL;
		/*su key corresponde al telcel*/
		IDictionary * usuarios;


	public:

		static CtrlUsuario * getinstancia();
		Usuario * getusuarioLog();
		IDictionary getusuarios();
		void setusuarioLog(Usuario * u);
		void setusuarios(IDictionary lista_usuarios);

		/* Ver Mensaje */
		ICollection mensajesCoversacion (IKey idConv);
		int cantidadArchivadas ();
		//Info adicional de un mensaje enviado por el usuario logeado.
		ICollection obtenerInfoAdicional(IKey codigo);

		/* Eliminar Mensaje */
		void eliminarMensaje (IKey codigo);

		/*archivar_conversacion*/
		ICollection listarArchivadas();
		ICollection listarActivas();
		void archivar_conversacion(IKey ID);
		/*agregarContacto*/
		ICollection getContactos();
		bool existeUsuario(IKey telCel);
		bool esContacto(telCel);
		DtInfoContacto agregarContacto(telcel);
		void confirmarAgregarContacto(telcel);

		/*cerrar GUASAP*/
		void cerrarGuasap();

		/*abrir GUASAP*/

		bool inicioSesion();
		DtFecha altaUsuario(IKey numero, String nombre, String URL,String Descripcion);
		bool ingresar(IKey numero); 

}