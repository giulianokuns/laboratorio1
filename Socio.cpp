#include "Socio.h"

using namespace std;

Socio::Socio(string CI, string nombre){
    this->CI = CI;
    this->nombre = nombre;
}

Socio::~Socio(){}

string Socio::getCI(){
    return CI;
} 

string Socio::getNombre(){
    return nombre
}

void Socio::setCI(string CI){
    this->CI = CI
}

void Socio::setNombre(string nombre){
    this->nombre = nombre
}
