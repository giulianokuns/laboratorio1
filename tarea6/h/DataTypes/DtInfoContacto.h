

class DtInfoContacto: public ICollectible {
	private:
		string nombre,
		IKey telCel;
		string urlImagen;
	public:
		DtInfoContacto(string nombre,IKey telCel, string urlImagen);
		~DtInfoContacto();
		string getnombre();
		string gettelCel();
		string geturlImagen();
}