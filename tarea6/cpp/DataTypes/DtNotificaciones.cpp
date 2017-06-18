#include "../../h/DataTypes/DtNotificaciones.h"
#include "../../h/Simple/Fecha.h"
#include "../../h/Simple/Hora.h"



DtNotificaciones::DtNotificaciones(string telCel, string tipo, string desc) {
    	
    Fecha *fch   = new Fecha(FechaSistema::dia,FechaSistema::mes,FechaSistema::anio);
    Hora *hr     = new Hora(HoraSistema::hora, HoraSistema::minutos);
    
    this->fecha     = fch;
    this->hora      = hr;
    this->telCel    = telCel;
    this->tipo      = tipo;
    this->desc      = desc;
    
}

DtNotificaciones::~DtNotificaciones(){    
    delete this->fecha;
    delete this->hora;    
}

Fecha *DtNotificaciones::getFecha(){
    return this->fecha;
}

Hora *DtNotificaciones::getHora(){
    return this->hora;
}

string DtNotificaciones::gettelCel (){
    return this->telCel;
}

string DtNotificaciones::getTipo (){
    return this->tipo;
}

string DtNotificaciones::getDesc (){
    return this->desc;
}