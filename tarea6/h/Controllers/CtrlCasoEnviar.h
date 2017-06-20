#include <iostream>
#include <cstring>

#include "../DataTypes/Mensaje/DtSimple.h"
#include "../DataTypes/Mensaje/DtContacto.h"
#include "../DataTypes/Mensaje/DtVideo.h"
#include "../DataTypes/Mensaje/DtImagen.h"

#include "../Simple/Mensaje/Mensaje.h"
#include "../Simple/Usuario.h"
#include "../Simple/Recibido.h"
#include "../Simple/EstadoConversacion.h"

#include "CtrlUsuario.h"

#include "../../lab6-colecciones/interfaces/ICollection.h"
#include "../../lab6-colecciones/interfaces/IKey.h"
#include "../../lab6-colecciones/interfaces/IDictionary.h"

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
};

#endif