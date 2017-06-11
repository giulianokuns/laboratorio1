#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtMensaje.h"

#ifndef DTCONTACTO
#define DTCONTACTO

using namespace std;

class DtContacto : public DtMensaje {
	private:
        string  dtNomContacto;
        string  dtTelContacto;

    public:
        virtual ~DtContacto() {};

        string  getNomContacto() const;
        string  getTelContacto() const;

        void setNomContacto (string text);
        void setTelContacto (string text);
};
#endif