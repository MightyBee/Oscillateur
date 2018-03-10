#include <iostream>
#include "Oscillateur.h"
#include "Vecteur.h"
using namespace std;

Oscillateur::Oscillateur() : P(3),Q(3) {}

Vecteur Oscillateur::f(const double& t) const{
  Vecteur retour(P.taille());
  return retour;
}

void Oscillateur::affiche(){
  cout << "P : "; P.affiche();
  cout << "Q : "; Q.affiche();
}
