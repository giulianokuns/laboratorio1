#ifndef _B_H_
#define _B_H_
#include <string>

class A;  // Declaración forward de la clase A 
class C; // Declaración forward de la clase C

class B {
public:
  A getAfromB();
  C getCfromB();
  std::string quienEres();
};

#endif