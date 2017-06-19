#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Fecha.h"
#include "Hora.h"
#include "FechaSistema.h"
#include "HoraSistema.h"

#include "IKey.h"
#include "IDictionary.h"
#include "ICollection.h"

#ifndef DTNOTIFICACION
#define DTNOTIFICACION

using namespace std;

class DtNotificacion : public ICollectible {
    private:
        String  telCel;
        Fecha   fecha;
        Hora    hora;
        String  info;
        String  tipo;

    public:
    	DtNotificacion(String telCel, String info, String tipo);
        ~DtNotificacion() {};

        String  getTelCel() const;
        Fecha   getFecha() const;
        Hora    getHora() const;
        String  getInfo() const;
        Fecha   getTipo() const;
};
#endif