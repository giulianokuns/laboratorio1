#ifndef DTCONVERSACION
#define DTCONVERSACION

using namespace std;

class DtConversacion: public ICollectibe {
	private:
		IKey idConversacion;
		bool esGrupo;
		String nombre;
		String telcel;

	public:
		DtConversacion(bool esGrupo, String nombre, String telcel, IKey idConversacion);
		~DtConversacion();
		IKey getidConversacion();
		bool getesGrupo();
		String getnombre();
		//en caso de ser esgrupo true no deveria tomarseen cuenta telcel
		String gettelcel();
}

#endif