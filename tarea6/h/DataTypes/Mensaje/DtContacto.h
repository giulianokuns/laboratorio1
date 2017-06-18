#include "DtMensaje.h"

#ifndef DTCONTACTO
#define DTCONTACTO

using namespace std;

class DtContacto : public DtMensaje {
	private:
        String  dtNomContacto;
        String  dtTelContacto;
        
    public:
        DtContacto (IKey codigo, Fecha fecha, Hora hora, String nom_contacto, String tel_cont) : DtMensaje (codigo, fecha, hora) {};
        ~DtContacto ();
        
        String  getNomContacto() const;
        String  getTelContacto() const;
};
#endif