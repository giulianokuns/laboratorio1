#include "DtSocio.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

using namespace std;

DtSocio::DtSocio(string CI, string nombre){
    this->CI = CI;
    this->nombre = nombre;
}

DtSocio::~DtSocio(){}

string DtSocio::getCI(){
    return CI;
} 

string DtSocio::getNombre(){
    return nombre;
}

void DtSocio::setCI(string CI){
    this->CI = CI;
}

void DtSocio::setNombre(string nombre){
    this->nombre = nombre;
}
