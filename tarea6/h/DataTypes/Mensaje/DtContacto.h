#include <iostream>
#include <cstring>
#include <string.h>

#include "DtMensaje.h"

#ifndef DTCONTACTO
#define DTCONTACTO

using namespace std;

class DtContacto : public DtMensaje {
	private:
        string  dtNomContacto;
        string  dtTelContacto;
        
    public:
        DtContacto (string codigo, Fecha *fecha, Hora *hora, string nom_contacto, string tel_cont);
        ~DtContacto ();
        
        string  getNomContacto() const;
        string  getTelContacto() const;
};
#endif