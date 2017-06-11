class CtrlUsuario{
	private:
		static CtrlUsuario * instancia;
		CtrlUsuario();
		Usuario * usuarioLog;
		IDictionary * usuarios;
	public:
		static Singleton * getinstancia();
		Usuario * getusuariolog();
		void setusuariolog(Usuario * u);

		/* Ver Mensaje */
		ICollection mensajesCoversacion (int idConv);
}