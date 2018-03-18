#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
using namespace std;

int main(){
  try{
  Oscillateur o;
  o.affiche();
  //test des get et set
  cout << endl;
  Oscillateur o1;
  Vecteur p1(o1.get_P());
  Vecteur q1(o1.get_Q());
  cout << p1 << q1 << endl;
  Vecteur p(4,5,6);
  Vecteur q(1,2,3);
  q.augmente(4);
  o1.set_P(p);
  cout << o1.get_P() << endl;
  o1.set_Q(q);
  cout << o1.get_Q() << endl;
}

  catch(Erreur err){
    cerr << endl << endl << "### ERREUR FATALE ###" << endl;
    cerr << "Type d'erreur : " << err.type << endl;
    cerr << "Dans fonction : " << err.fct << endl;
    cerr << "Description   : " << err.description << endl;
    cerr << "### FIN DU PROGRAMME ###" << endl << endl;
  }
  return 0;
}
