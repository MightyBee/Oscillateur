#pragma once
#include "Vecteur.h"

class Oscillateur{
public:
  Oscillateur();
  Vecteur f(const double& t) const;
  void affiche();
  //accesseurs
  Vecteur get_P() const;
  Vecteur get_Q() const;
  //manipulateurs
  void set_P(Vecteur const& p);
  void set_Q(Vecteur const& q);
private:
  Vecteur P;
  Vecteur Q;
};
