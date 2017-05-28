DtClase obtenerClase(int idClase){
	//se asume que debe existir la clase del id correspondiente
	DtClase datosClase;
	int j=0;
	while(j<=tope_clases)&&(clases[j].getid()!=idClase)
		j++;
	if (j<tope_clases)
		 if (dynamic_cast<Entrenamiento &> clases[j]!=NULL)
		 	 
	        datosClase.DtSpinning(clases[j].getCantBicicletas(),clases[j].getid(),clases[j].getNombre(),clases[j].getTurno());
	    else
	        datosClase.DtEntrenamiento(clases[j].getenRambla(),clases[j].getid(),clases[j].getNombre(),clases[j].getTurno());

}