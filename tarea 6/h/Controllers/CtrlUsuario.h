class CtrlUsuario{
	private:
		static CtrlUsuario * instancia;
		CtrlUsuario();
		Usuario * usuarioLog;
		/*su key corresponde al telcel*/
		IDictionary * usuarios;
	public:
		static Singleton * getinstancia();
		Usuario * getusuarioLog();
		IDictionary getusuarios();
		void setusuarioLog(Usuario * u);
		void setusuarios(IDictionary lista_usuarios);

		/* Ver Mensaje */
		ICollection mensajesCoversacion (int idConv);
		
		/*archivar_conversacion*/
		ICollection listarActivas();
		void archivar_conversacion(string ID);
		/*agregarContacto*/
		ICollection getContactos();
		bool existeUsuario(string telCel);
		bool esContacto(telCel);
		DtInfoContacto agregarContacto(telcel);
		void confirmarAgregarContacto(telcel);
}