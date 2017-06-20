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

#include "DtNotificacion.h"


using namespace std;

/*class DtNotificacion : public ICollectible {
    private:
        String  telCel;
        Fecha   fecha;
        Hora    hora;
        String  info;
        String  tipo;

    public:
    	DtNotificacion(String telCel, String info, String tipo);
        virtual ~DtNotificacion() {};

        String  getTelCel() const;
        Fecha   getFecha() const;
        Hora    getHora() const;
        String  getInfo() const;
        Fecha   getTipo() const;
};*/

DtNotificacion::DtNotificacion(String telCel, String info, String tipo){

	//Hora y Fecha actual
	Fecha fch = new Fecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());
	Hora hr = new Hora(HoraSistema::getHora(),HoraSistema::getMinutos());

	this->telCel = telCel;
	this->fecha = fch;
	this->hora = hr;
	this->info = info;
	this->tipo = tipo;

}

DtNotificacion::~DtNotificacion(){

	delete this->fecha;
	delete this->hora;

}

//GETERS

String DtNotificacion::getTelCel(){
	return this->telCel;
}

Fecha DtNotificacion::getFecha(){
	return this->fecha;
}

Hora DtNotificacion::getHora(){
	return this->hora;
}

String DtNotificacion::getInfo(){
	return this->info;
}

String DtNotificacion::getTipo(){
	return this->tipo;
}