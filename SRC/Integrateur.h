#pragma once
#include "Oscillateur.h"
#include "Vecteur.h"

class Integrateur{
  public:
    void integre(const Oscillateur& osc, const double& pdt) const;
  private:
    //jjj
};

class IntegrateurEulerCromer : public Integrateur{
  public:
    void integre(Oscillateur& osc, const double& pdt) const;
  private:
    //uu
};
