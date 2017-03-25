#include "C.h"
#include "B.h"
#include "A.h"
using namespace std;

B C::getBfromC() {
  return B();
}

A C::getAfromC(){
	return A();
}

std::string C::quienEres() {
  return "Soy la clase C";
}