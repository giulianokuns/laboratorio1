#include "B.h"
#include "A.h"
#include "C.h"
using namespace std;

A B::getAfromB() {
  return A();
}

C B::getCfromB(){
	return C();
}

std::string B::quienEres() {
  return "Soy la clase B";
}