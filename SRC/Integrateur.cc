#include <iostream>
#include "Integrateur.h"
#include "Oscillateur.h"
#include "Vecteur.h"
using namespace std;

Integrateur::Integrateur(const Oscillateur& osc, const double& pdt, const double t)
                        : osc(osc), pdt(pdt), t_abs(t) {}

void Integrateur::evolue(){
  t_abs+=pdt;
}

Oscillateur Integrateur::get_osc(){
  return osc;
}

double Integrateur::get_t(){
  return t_abs;
}

ostream& Integrateur::affiche(ostream& sortie) const{
  sortie << "# Integrateur, \"pas de temps\" : " << pdt << endl;
  sortie << t_abs << " # temps absolu" << endl;
  sortie << osc;
  return sortie;
}

// permet l'affichage standard : sortie << integrateur; //
ostream& operator<<(ostream& sortie, const Integrateur& integrat){
	return integrat.affiche(sortie);
}


IntegrateurEulerCromer::IntegrateurEulerCromer(const Integrateur& integrat)
                                              : Integrateur(integrat) {}

IntegrateurEulerCromer::IntegrateurEulerCromer(const Oscillateur& osc, const double& pdt, const double t)
                                              : Integrateur(osc,pdt,t) {}

void IntegrateurEulerCromer::evolue(){
  osc.set_Q(osc.get_Q()+pdt*osc.f());
  osc.set_P(osc.get_P()+pdt*osc.get_Q());
  t_abs+=pdt;
}


void IntergrateurRungeKutta::evolue(){
  Vecteur P(osc.get_P());
  Vecteur Q(osc.get_Q());
  /*Vecteur k1(Q);
  Vecteur kk1(f(t_abs,P,Q));
  Vecteur k2(Q+pdt/2*kk1);
  Vecteur kk2(f(t_abs+pdt/2,P+pdt/2*k1,Q+pdt/2*kk1));
  Vecteur k3(Q+pdt/2*kk2);
  Vecteur kk3(f(t_abs+pdt/2,P+pdt/2*k2,Q+pdt/2*kk2));
  Vecteur k4(Q+pdt*kk3);
  Vecteur kk4(f(t_abs+pdt,P+pdt*k3,Q+pdt*kk3));
  osc.set_P(P+pdt/6*(k1+2*k2+2*k3+k4));
  osc.set_Q(Q+pdt/6*(kk1+2*kk2+2*kk3+kk4));
  t_abs+=pdt; */
}
