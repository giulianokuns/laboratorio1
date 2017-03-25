#ifndef A_H
#define A_H
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