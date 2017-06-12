class DtInfoContacto: public ICollectible{
	private:
		string nombre,
		string telCel;
		string urlImagen;
	public:
		DtInfoContacto(string nombre,string telCel, string urlImagen);
		~DtInfoContacto();
		string getnombre();
		string gettelCel();
		string geturlImagen();
}