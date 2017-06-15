#ifndef DTCONVERSACION
#define DTCONVERSACION

using namespace std;

class DtConversacion: public ICollectibe {
	private:
		int idConversacion;
		bool esGrupo;
		String nombre;
		String telcel;

	public:
		DtConversacion(bool esGrupo, String nombre, String telcel, int idConversacion);
		~DtConversacion();
		int getidConversacion();
		bool getesGrupo();
		String getnombre();
		//en caso de ser esgrupo true no deveria tomarseen cuenta telcel
		String gettelcel();
}

#endif