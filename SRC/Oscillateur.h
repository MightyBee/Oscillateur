#pragma once
#include "Vecteur.h"

class Oscillateur{
public:
  Oscillateur();
  Vecteur f(const double& t) const;
  void affiche();
private:
  Vecteur P;
  Vecteur Q;
};
