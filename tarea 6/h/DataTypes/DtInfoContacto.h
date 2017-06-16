

class DtInfoContacto: public ICollectible {
	private:
		String nombre,
		IKey telCel;
		String urlImagen;
	public:
		DtInfoContacto(String nombre,IKey telCel, String urlImagen);
		~DtInfoContacto();
		String getnombre();
		String gettelCel();
		String geturlImagen();
}