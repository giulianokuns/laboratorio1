class DtConversacion: public ICollectibe {
	private:
		string idConversacion;
		bool esGrupo;
		string nombre;
		string telcel;
	public:
		DtConversacion(bool esGrupo,string nombre,string telcel,string idConversacion);
		~DtConversacion();
		string getidConversacion();
		bool getesGrupo();
		string getnombre();
		//en caso de ser esgrupo true no deveria tomarseen cuenta telcel
		string gettelcel();
}