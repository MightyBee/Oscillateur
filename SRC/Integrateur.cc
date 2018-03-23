#include <iostream>
#include "Integrateur.h"
#include "Oscillateur.h"
#include "Vecteur.h"
using namespace std;


void IntegrateurEulerCromer::integre(Oscillateur& osc, const double& pdt) const{
  osc.set_Q(osc.get_Q()+pdt*osc.f());
  osc.set_P(osc.get_P()+pdt*osc.get_Q());
}
