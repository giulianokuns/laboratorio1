#ifndef _A_H_
#define _A_H_
#include <string>

class B;  // Declaración forward de la clase B
class C;  // Declaración forward de la clase C

class A {
public:
  B getBfromA();
  C getCfromA();
  std::string quienEres();
};

#endif