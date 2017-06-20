#include "A.h"
#include "B.h"
#include "C.h"

#include <iostream>

using namespace std;

int main() {
  A a;
  B b;
  C c;

  A ab = b.getAfromB();
  A ac = c.getAfromC();
  B ba = a.getBfromA();
  B bc = c.getBfromC();
  C ca = a.getCfromA();
  C cb = b.getCfromB();

  cout << "ab es: " << ab.quienEres() << endl;
  cout << "ba es: " << ba.quienEres() << endl;
  cout << "ac es: " << ac.quienEres() << endl;
  cout << "ca es: " << ca.quienEres() << endl;
  cout << "bc es: " << bc.quienEres() << endl;
  cout << "cb es: " << cb.quienEres() << endl;

  return 0;
}
