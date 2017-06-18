#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "Multimedia.h"

#ifndef IMAGEN
#define IMAGEN

using namespace std;

class Imagen : public Multimedia {
	private:
        String  formato;
        int  	tamanio;
        String  textMulti;
        String  URLpicture;

    public:
        Imagen (IKey codigo, Fecha fecha, Hora hora, String formato, int tamanio, String textmulti, String urlpicture) : Mensaje (codigo, fecha, hora) {};
        ~Imagen ();
        
        String  getFormato() const;
        int  	getTamanio() const;
        String  getTextMulti() const;
        String  getURLpicture() const;

        friend ostream& operator<<(ostream& os, const Imagen& mens_img);
};
#endif