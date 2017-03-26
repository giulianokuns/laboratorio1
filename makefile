

C = g++
CCFLAGS = -Wall  -g
REQUERIMIENTOS= DtSocio.cpp DtClase.cpp DtEntrenamiento.cpp DtSpinning.cpp \
Fecha.cpp Socio.cpp Inscripcion.cpp Clase.cpp Spinning.cpp  \
Entrenamiento.cpp main.cpp
main: $(REQUERIMIENTOS)
	 $(CC) $(CCFLAGS) $(REQUERIMIENTOS)  -o main 

    
