#include "A.h"
#include "B.h"
#include "C.h"

B A::getBfromA() {
  return B();
}

C A::getCfromA(){
	return C();
}

std::string A::quienEres() {
  return "Soy la clase A";
}