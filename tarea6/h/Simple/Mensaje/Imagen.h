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
        string  formato;
        int  	tamanio;
        string  textMulti;
        string  URLpicture;

    public:
        Imagen (IKey codigo, Fecha fecha, Hora hora, string formato, int tamanio, string textmulti, string urlpicture) : Mensaje (codigo, fecha, hora) {};
        ~Imagen ();
        
        string  getFormato() const;
        int  	getTamanio() const;
        string  getTextMulti() const;
        string  getURLpicture() const;

        friend ostream& operator<<(ostream& os, const Imagen& mens_img);
};
#endif