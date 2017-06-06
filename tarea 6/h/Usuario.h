class Usuario{
	private:
		string telCel;
		string nomUsuario;
		Fecha fechaRegistro;
		string imaPerfil;
		Fecha fechaUltimaConex;
		Hora horaUltimaConex;
	public:
		string getTelCel();
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