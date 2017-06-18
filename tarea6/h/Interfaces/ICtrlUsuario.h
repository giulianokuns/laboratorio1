class ICtrlUsuario{
	virtual Usuario * getusuarioLog() = 0;
	virtual	IDictionary getusuarios() = 0;
	virtual	void setusuarioLog(Usuario * u) =0;
	virtual	void setusuarios(IDictionary lista_usuarios) =0;

		/* Ver Mensaje */
	virtual	ICollection mensajesCoversacion (IKey idConv) = 0;
		
		/*archivar_conversacion*/
	virtual	ICollection listarActivas() = 0;
		void archivar_conversacion(IKey ID) = 0;

		/*agregarContacto*/
	virtual	ICollection getContactos() = 0;
	virtual	bool existeUsuario(IKey telCel) = 0;
	virtual	bool esContacto(IKeytelCel) = 0;
	virtual	DtInfoContacto agregarContacto(IKeytelcel) = 0;
	virtual	void confirmarAgregarContacto(IKey telcel) = 0;

		/*cerrar GUASAP*/
	virtual	void cerrarGuasap() = 0;

		/*abrir GUASAP*/

	virtual	bool inicioSesion() = 0;
	virtual	DtFecha altaUsuario(IKey numero, String nombre, String URL, String Descripcion) = 0;
	virtual	bool ingresar(IKey numero) = 0; 
}