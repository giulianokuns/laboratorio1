#ifndef HORA
#define HORA

using namespace std;

class Hora{
	private:
		int horas;
		int minutos;
	public:
		Hora(int horas, int minutos);
		int gethoras();
		int getminutos();
		void sethoras(int hora);
		void setminutos(int minutos);

		bool operator ==(const Hora &a) const;
		bool operator  >(const Hora &a) const;
		ostream& operator<<(ostream& os);
};

#endif