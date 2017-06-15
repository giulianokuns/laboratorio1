class FechaSistema{
	private:
		static int hora;
		static int minutos;

	public:
		static int getHora();
		static int getMinutos();
		static void setHora(int hora);
		static void setMinutos(int minutos);
}

int FechaSistema::getHora(){
	return hora;
}

int FechaSistema::getMinutos(){
	return minutos;
}

void FechaSistema::setHora(int hora){
	this->hora = hora;
}

void FechaSistema::setMinutos(int minutos){
	this->minutos = minutos;
}