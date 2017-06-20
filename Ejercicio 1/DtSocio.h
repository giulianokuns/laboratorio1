#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#ifndef DTSOCIO
#define DTSOCIO

using namespace std;

class DtSocio{
    private:
        string CI;
        string nombre;
    public:
        DtSocio(string CI, string nombre);
        ~DtSocio();
        string getCI();
        string getNombre();
    	void setCI(string CI);
    	void setNombre(string nombre);
};

#endif  


