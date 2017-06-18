#ifndef DTFECHA
#define DTFECHA

using namespace std;

class DtFecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
		DtFecha(int dia,int mes,int anio);
		int getdia();
		int getmes();
		int getanio();
}

#endif