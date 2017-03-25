#ifndef _C_H_
#define _C_H_
#include <string>

class B;  // Declaración forward de la clase B
class A;  // Declaración forward de la clase A

class C {
public:
  B getBfromC();
  A getAfromC();
  std::string quienEres();
};

#endif