

class DtInfoContacto: public ICollectible {
	private:
		String nombre,
		String telCel;
		String urlImagen;
	public:
		DtInfoContacto(String nombre,String telCel, String urlImagen);
		~DtInfoContacto();
		String getnombre();
		String gettelCel();
		String geturlImagen();
}