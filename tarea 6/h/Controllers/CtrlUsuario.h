class CtrlUsuario{
	private:
		static CtrlUsuario * instancia;
		CtrlUsuario();
		Usuario * usuarioLog;
		IDictionary * usuarios;
	public:
		static Singleton * getinstancia();
		Usuario * getusuarioLog();
		void setusuarioLog(Usuario * u);

		/* Ver Mensaje */
		ICollection mensajesCoversacion (int idConv);
		/*archivar_conversacion*/
		ICollection listarActivas();
}