/* Main */
#include "Clase.h";
#include "DtClase.h";
#include "Entrenamiento.h";
#include "DtEntrenamiento.h";
#include "Spinning.h";
#include "DtSpinning.h";
#include "Socio.h";
#include "DtSocio.h";
#include "Fecha.h";
#include "Incripcion.h";
#include <iostream>;
#include <string.h>

using namespace std;

#define MAX_CLASES 20
#define MAX_SOCIOS 50
	
	Clase clases[MAX_CLASES];
	Socio socios[MAX_SOCIOS];

	int tope_clases = 0;
	int tope_socios = 0;

	void agregarSocio (string ci, string nombre) 
	{
		int i = 0;
		if (tope_socios < MAX_SOCIOS) {
			while (i <= tope_socios && strcmp(socios[i].getNombre(),nombre) != 0) {
				i++;
			}

			if (i <= tope_socios) {
				throw std::invalid_argument('Ya existe el socio');
			} else {
		 		Socio *socio = new Socio(ci, nombre);
		 		socios[tope_socios] = socio;
		 		tope_socios++;
			}
		} else {
			throw std::invalid_argument('No hay mas lugar disponible');
		}
	}

	void agregarClase(DtClase& clase) {
		/* Diferenciar si la variable clases es de DtSpinning o de DtEntrenamiento */
		int i = 0;
		if (tope_clases < MAX_CLASES) {
			while (i <= tope_clases && strcmp(clases[i].getid(),clase.getid()) != 0) {
				i++;
			}	
			if (i <= tope_clases) {
				throw std::invalid_argument('Ya existe la clase');
			} else {
				if (dynamic_cast<DtEntrenamiento &> clase != null) { 
					//Entrenamiento
					Entrenamiento *entrenamiento = new Entrenamiento(clase.getenRambla(), clase.getid(), clase.getNombre(), clase.getTurno());
			 		clases[tope_clases] = entrenamiento;
					
				} else {
					//Spinning
					Spinning *spinning = new Spinning(clase.getCantBicicletas(), clase.getid(), clase.getNombre(), clase.getTurno());
					clases[tope_clases] = spinning;
				}
		 		tope_clases++;
			}
		} else {
			throw std::invalid_argument('No hay mas clases disponible');
		}
	}

	void agregarInscripcion(String ciSocio, int idClase, Fecha fecha) {

	}
	void borrarInscripcion(string ciSocio, int idClase) {

	}

	DtSocio** obtenerInfoSociosPorClase (id idClase, int& cantSocios) {

	}



int main()
{
    int opcion = 0;
    while()
    return 0
}
