#ifndef FECHA
#define FECHA

using namespace std;

class Fecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
		Fecha(int dia,int mes,int anio);
		int getdia();
		int getmes();
		int getanio();
		void setdia(int dia);
		void setmes(int mes);
		void setanio(int anio);

		bool operator ==(const Fecha &a, const Fecha &b) const;
		bool operator  >(const Fecha &a, const Fecha &b) const;
		ostream& operator<<(ostream& os, const Fecha& fecha);
};

#endif