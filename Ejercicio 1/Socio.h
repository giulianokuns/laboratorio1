#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#ifndef SOCIO
#define SOCIO

using namespace std;

class Socio{
    private:
        string CI;
        string nombre;
    public:
        Socio(string CI, string nombre);
        ~Socio();
        string getCI();
        string getNombre();
    	void setCI(string CI);
    	void setNombre(string nombre);
};

#endif  
