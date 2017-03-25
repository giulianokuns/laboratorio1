#include "A.h"
#include "B.h"
#include "C.h"

#include <iostream>

int main() {
  A a;
  B b;
  C b;

  A ab = b.getAfromB();
  A ac = c.getAfromC();
  B ba = a.getBfromA();
  B bc = c.getBfromC();
  C ca = a.getCfromA();
  C cb = b.getCfromB();

  std::cout << "ab es: " << ab.quienEres() << endl;
  std::cout << "ba es: " << ba.quienEres() << endl;
  std::cout << "ac es: " << ac.quienEres() << endl;
  std::cout << "ca es: " << ca.quienEres() << endl;
  std::cout << "bc es: " << bc.quienEres() << endl;
  std::cout << "cb es: " << cb.quienEres() << endl;

  return 0;
}