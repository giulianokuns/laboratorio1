#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

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
        //virtual DtClase(int id, string nombre, Turno turno);
        virtual ~DtClase();
        //virtual bool getEnrambla();//para poder hacer un dynamic_cast
        int getid() const;
        string getNombre() const;
        Turno getTurno() const;
    	void setid(int id);
    	void setNombre(string nombre);
    	void setTurno(Turno turno);
};
#endif 
