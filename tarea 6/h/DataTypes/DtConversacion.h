class DtConversacion: public ICollectibe {
	private:
		String idConversacion;
		bool esGrupo;
		String nombre;
		String telcel;
	public:
		DtConversacion(bool esGrupo,String nombre,String telcel,String idConversacion);
		~DtConversacion();
		String getidConversacion();
		bool getesGrupo();
		String getnombre();
		//en caso de ser esgrupo true no deveria tomarseen cuenta telcel
		String gettelcel();
}