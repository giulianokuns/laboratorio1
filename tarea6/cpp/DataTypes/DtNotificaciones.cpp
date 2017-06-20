 
#include "../../h/DataTypes/DtNotificaciones.h"
#include "../../h/Simple/Fecha.h"
#include "../../h/Simple/Hora.h"
#include "../../h/Simple/HoraSistema.h"
#include "../../h/Simple/FechaSistema.h"



DtNotificaciones::DtNotificaciones(string telCel, string tipo, string desc) : fecha(FechaSistema::dia,FechaSistema::mes,FechaSistema::anio), hora(HoraSistema::hora, HoraSistema::minutos){
    this->telCel    = telCel;
    this->tipo      = tipo;
    this->desc      = desc;
}

DtNotificaciones::~DtNotificaciones(){    
    fecha.~Fecha();
    hora.~Hora();    
}

Fecha DtNotificaciones::getFecha(){
    return this->fecha;
}

Hora DtNotificaciones::getHora(){
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
