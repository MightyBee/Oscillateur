#include <iostream>
#include "Oscillateur.h"
#include "TextViewer.h"
#include "constantes.h"
using namespace std;

int main(){
  try{
  /*
  Oscillateur o;
  o.affiche(cout);
  //test des get et set
  cout << endl;
  Oscillateur o1(3);
  Vecteur p1(o1.get_P());
  Vecteur q1(o1.get_Q());
  cout << p1 << q1 << endl;
  Vecteur p(4,5,6);
  Vecteur q({1,2});
  o1.set_P(1,1.9);
  q.augmente(4);
  o1.set_P(p);
  cout << o1 << endl;
  o1.set_Q(q);
  cout << o1.get_Q() << endl;

  Oscillateur osc1;
  Oscillateur osc2(5);
  Oscillateur osc3(1.1,2.2,3.3,4.4,5.5,6.6);
  cout << osc1 << osc2 << osc3 << endl;
  Oscillateur osc4({1,2},{3,4});
  cout << osc4 << endl;
  Oscillateur osc5({1,2},{3,4});
  cout << osc5 << endl;
  */
  Vecteur v({2,2,3,4});
  cout << v << endl;
  TextViewer tv(cout);
  Pendule p(&tv,{M_PI/3});
  cout << p.position() << endl;
  }catch(Erreur err){
    err.affiche("testOscillateur.cc");
  }
  return 0;
}
