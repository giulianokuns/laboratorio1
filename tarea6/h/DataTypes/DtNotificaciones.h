 
#ifndef DTNOTIFICACIONES
#define DTNOTIFICACIONES

using namespace std;

class DtNotificaciones{
	private:
		Fecha fecha;
		Hora hora;
		string telCel;
                string tipo;
                string desc;
	public:
                DtNotificaciones(string telCel,string tipo,string desc);
                ~DtNotificaciones();
		Fecha getFecha();
		Hora getHora;
		string gettelCel;
                string getTipo;
                string getDesc;
}

#endif
