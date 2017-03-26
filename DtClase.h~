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
        virtual ~DtClase() = 0;
        int getid() const;
        string getNombre() const;
        Turno getTurno() const;
    	void setid(int id);
    	void setNombre(string nombre);
    	void setTurno(Turno turno);
};
#endif 
