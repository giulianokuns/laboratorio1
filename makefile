

C = g++
CCFLAGS = -Wall  -g
REQUERIMIENTOS= Clase.cpp DtClase.cpp  DtEntrenamiento.cpp \
 DtEntrenamiento.cpp  Spinning.cpp  \
DtSpinning.cpp  Socio.cpp DtSocio.cpp  Fecha.cpp \
Inscripcion.cpp  main.cpp
main: $(REQUERIMIENTOS)
	 $(CC) $(CCFLAGS) $(REQUERIMIENTOS)  -o main 
