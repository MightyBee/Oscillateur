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
  cout << "P : " << P;
  cout << "Q : " << Q;
}

Vecteur Oscillateur::get_P() const{return P;}
Vecteur Oscillateur::get_Q() const{return Q;}

void Oscillateur::set_P(Vecteur const& p){
  if(p.taille() != P.taille()){
    Erreur r;
    r.type="dimension";
    r.fct="Oscillateur::set_P(Vecteur const&)";
    r.description="Les dimensions des vecteurs ("+to_string(p.taille())+" et "+to_string(P.taille())+")";
    r.description+=" ne sont pas les mêmes.";
    throw r;
  }
  else{
    P=p;}
}
void Oscillateur::set_Q(Vecteur const& q){
  if(q.taille() != Q.taille()){
    Erreur r;
    r.type="dimension";
    r.fct="Oscillateur::set_Q(Vecteur const&)";
    r.description="Les dimensions des vecteurs ("+to_string(q.taille())+" et "+to_string(Q.taille())+")";
    r.description+=" ne sont pas les mêmes.";
    throw r;
  }
  else{
    Q=q;}
}
