#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Mensaje.h"

#ifndef CONTACTO
#define CONTACTO

using namespace std;

class Contacto : public Mensaje {
	private:
        string  nomContacto;
        string  telContacto;

    public:
        Contacto (IKey *codigo, Fecha *fecha, Hora *hora, string nom_contacto, string tel_cont);
        ~Contacto ();
        
        string  getNomContacto() const;
        string  getTelContacto() const;

        friend ostream& operator<<(ostream& os, const Contacto& mens_contacto);
};
#endif