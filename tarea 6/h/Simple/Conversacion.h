class Conversacion{
	private:
		bool visto;
		String idConversacion;
		bool esGrupo;
		Grupo grupo;
		Usuario receptor;
	public:
		Conversacion(bool visto,String idConversacion,bool esGrupo,Grupo grupo,Usuario receptor);
		~Conversacion();
		bool getvisto();
		String getidConversacion();
		bool getesGrupo();
		Grupo getgrupo();
		Usuario getreceptor();
		void setvisto(bool visto);
		void setidConversacion(String ID);
		void setesGrupo(bool esgrupo);
		void setgrupo(Grupo g);
		void setreceptor(Usuario u);
			/*archivar_conversacion*/
		DtConversacion getinfo();
}