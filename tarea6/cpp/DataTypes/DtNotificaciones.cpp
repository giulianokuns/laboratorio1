
DtNotificaciones::DtNotificaciones(string telCel,string tipo,string desc){
    	
    Fecha fch = new Fecha(FechaSistema::getDia(),FechaSistema::getMes(),FechaSistema::getAnio());
    Hora hr = new Hora(HoraSistema::getHora(),HoraSistema::getMinutos());
    
    this->fecha = fch;
    this->hora = hr;
    this->telCel = telCel;
    this->tipo = tipo;
    this->desc = desc;
    
}

void DtNotificaciones::~DtNotificaciones(){
    
    delete this->fecha;
    delete this->hora;
    
}

Fecha DtNotificaciones::getFecha(){
    return this->fecha;
}

Hora DtNotificaciones::getHora{
    return this->hora;
}

string DtNotificaciones::gettelCel{
    return this->telCel;
}

string DtNotificaciones::getTipo{
    return this->tipo;
}

string DtNotificaciones::getDesc{
    return this->desc;
}
