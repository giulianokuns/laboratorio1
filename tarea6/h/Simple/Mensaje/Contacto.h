#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Mensaje.h"

#ifndef CONTACTO
#define CONTACTO

using namespace std;

class Contacto : public Mensaje {
	private:
        String  nomContacto;
        String  telContacto;

    public:
        Contacto (IKey codigo, Fecha fecha, Hora hora, String nom_contacto, String tel_cont) : Mensaje (codigo, fecha, hora) {};
        ~Contacto ();
        
        String  getNomContacto() const;
        String  getTelContacto() const;

        friend ostream& operator<<(ostream& os, const Contacto& mens_contacto);
};
#endif