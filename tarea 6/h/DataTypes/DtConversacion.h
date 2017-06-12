class DtConversacion: public ICollectibe {
	private:
		bool esGrupo;
		string nombre;
		string telcel;
	public:
		DtConversacion(bool esGrupo,string nombre,string telcel);
		~DtConversacion();
		bool getesGrupo();
		string getnombre();
		//en caso de ser esgrupo true no deveria tomarseen cuenta telcel
		string gettelcel();
}