#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
/*Incluir fecha y hora*/

#ifndef DTMENSAJE
#define DTMENSAJE

using namespace std;

class DtMensaje : public ICollectible{
    private:
        string  dtCodigo;
        Fecha   dtFechaMens;
        Hora    dtHora;
    public:
        virtual ~DtMensaje() {};

        string  getCodigo() const;
        Fecha   getFecha() const;
        Hora    getHora() const;
    	
        void setCodigo(int id);
    	void setFecha(string nombre);
    	void setHora(Turno turno);
};
#endif