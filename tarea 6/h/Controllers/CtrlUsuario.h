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
		ICollection mensajesCoversacion (int idConv);
		
		/*archivar_conversacion*/
		ICollection listarActivas();
		void archivar_conversacion(String ID);

		/*agregarContacto*/
		ICollection getContactos();
		bool existeUsuario(String telCel);
		bool esContacto(telCel);
		DtInfoContacto agregarContacto(telcel);
		void confirmarAgregarContacto(telcel);

		/*cerrar GUASAP*/
		void cerrarGuasap();

		/*abrir GUASAP*/

		bool inicioSesion();
		DtFecha altaUsuario(String numero, String nombre, String URL,String Descripcion);
		bool ingresar(String numero); 

}