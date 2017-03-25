#include <iostream>

#ifndef DTCLASE
#define DTCLASE

using namespace std;

enum Turno {Manana, Tarde, Noche};

class DtClase{
    private:
        int id;
        string nombre;
        Turno turno;
    public:
        virtual bool getEnrambla();//para poder hacer un dynamic_cast
        int getid();
        string getNombre();
        Turno getTurno();
    	void setid(int id);
    	void setNombre(string nombre);
    	void setTurno(Turno turno);
};
#endif 
