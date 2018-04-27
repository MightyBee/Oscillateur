#include "Systeme.h"
using namespace std;

Systeme::Systeme(SupportADessin* sup, Integrateur const& integrat, double t)
                : Dessinable(sup), integrateur(integrat.copie()), temps(t) {}

void Systeme::add(Oscillateur const& osc){
  collection.push_back(osc.copie());
}

void Systeme::evolue(double dt){
  for(auto& osc : collection){
    integrateur->evolue(*osc, dt); //TODO changer methode evolue dans integrateur, ATTENTION osc est une ref sur unique ptr
  }
  temps+=dt;
}
