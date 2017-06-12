class Conversacion{
	private:
		bool visto;
		string idConversacion;
		bool esGrupo;
		Grupo grupo;
		Usuario receptor;
	public:
		Conversacion(bool visto,string idConversacion,bool esGrupo,Grupo grupo,Usuario receptor);
		~Conversacion();
		bool getvisto();
		string getidConversacion();
		bool getesGrupo();
		Grupo getgrupo();
		Usuario getreceptor();
		void setvisto(bool visto);
		void setidConversacion(string ID);
		void setesGrupo(bool esgrupo);
		void setgrupo(Grupo g);
		void setreceptor(Usuario u);
			/*archivar_conversacion*/
		DtConversacion getinfo();
}