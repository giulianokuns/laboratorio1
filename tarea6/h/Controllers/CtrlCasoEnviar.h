#include <iostream>
#include <cstring>

#include "CtrlCasoEnviar.h"
#include "DtSimple.h"
#include "DtContacto.h"
#include "DtVideo.h"
#include "DtImagen.h"
#include "DtMultimedia.h"

#include "ICollection.h"
#include "IKey"

#ifndef CTRLCASOENVIAR
#define CTRLCASOENVIAR

using namespace std;

class CtrlCasoEnviar{
private:
    static CtrlCasoEnviar *instancia = NULL;
    CtrlCasoEnviar();
    IKey idContact;
    IKey *idConver;
public:
	    static CtrlCasoEnviar *getInstancia();
	    int cantidadArchivadas();
	    ICollection * listarArchivadas();
	    ICollection * listarActivas();
	    ICollection * listarContactos();
	    IKey crearConversacion(IKey tel, IKey idConver);
	    void crearMensajeContact(string tel, IKey codigo, Fecha fechaSist, Hora horaSist);
	    void crearMensajeImagen(string formato, int tamanio, string textMulti, string urlImg, IKey codigo, Fecha fechaSist, Hora horaSist);
	    void crearMensajeSimple(string simCont, IKey codigo, Fecha fechaSist, Hora horaSist);
	    void crearMensajeVideo(string urlVideo, int duracion, IKey codigo, Fecha fechaSist, Hora horaSist);
	    void ingresarIDContacto(IKey idContact);
	    void ingresarIDArchi(IKey idArchi);
	    void ingresarIDActiva(IKey idActiva);	    
}

#endif