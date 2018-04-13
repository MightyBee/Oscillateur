#include <iostream>
#include "Integrateur.h"
#include "Oscillateur.h"
#include "Vecteur.h"
using namespace std;

/*##############################################################################
###                                                                          ###
###                    METHODES DE LA CLASSE Integrateur                     ###
###                                                                          ###
##############################################################################*/

//#############################  constructeurs  ##############################//
// construit un intégrateur en initilisant tous ses attributs
Integrateur::Integrateur(const Oscillateur& osc, const double& pdt, const double t)
                        : osc(osc), pdt(pdt), t_abs(t) {}


//##############################  accesseurs  ################################//
// retourne le temps absolu de l'intégrateur
double Integrateur::get_t(){
  return t_abs;
}

// retourne l'oscillateur associé à l'intégrateur
Oscillateur Integrateur::get_osc(){
  return osc;
}


//############################  autres méthodes  #############################//
// méthode qui fait évoluer l'intégrateur d'un pas de temps
void Integrateur::evolue(){
  t_abs+=pdt;
}

// permet l'affichage standard : sortie << integrateur;
ostream& Integrateur::affiche(ostream& sortie) const{
  sortie << "# Integrateur, \"pas de temps\" : " << pdt << endl;
  sortie << t_abs << " # temps absolu" << endl;
  sortie << osc;
  return sortie;
}



/*##############################################################################
###                                                                          ###
###                           OPÉRATEURS EXTERNES                            ###
###                                                                          ###
##############################################################################*/

// permet l'affichage standard : sortie << integrateur; //
ostream& operator<<(ostream& sortie, const Integrateur& integrat){
	return integrat.affiche(sortie);
}



/*##############################################################################
###                                                                          ###
###              METHODES DE LA CLASSE IntegrateurEulerCromer                ###
###                                                                          ###
##############################################################################*/

// permet de construire un intégrateur Euler-Cromer à partir d'un intégrateur générique
IntegrateurEulerCromer::IntegrateurEulerCromer(const Integrateur& integrat)
                                              : Integrateur(integrat) {}

// construit un intégrateur Euler-Cromer en initilisant tous ses attributs
IntegrateurEulerCromer::IntegrateurEulerCromer(const Oscillateur& osc, const double& pdt, const double t)
                                              : Integrateur(osc,pdt,t) {}

// spécialisation de la méthode "evolue()" de la super-classe, avance d'un pas de temps avec la méthode d'intégration d'Euler-Cromer
void IntegrateurEulerCromer::evolue(){
  osc.set_Q(osc.get_Q()+pdt*osc.f());
  osc.set_P(osc.get_P()+pdt*osc.get_Q());
  t_abs+=pdt;
}



/*##############################################################################
###                                                                          ###
###               METHODES DE LA CLASSE IntegrateurRungeKutta                ###
###                                                                          ###
##############################################################################*/

/*
void IntergrateurRungeKutta::evolue(){
  Vecteur P(osc.get_P());
  Vecteur Q(osc.get_Q());
  Vecteur k1(Q);
  Vecteur kk1(f(t_abs,P,Q));
  Vecteur k2(Q+pdt/2*kk1);
  Vecteur kk2(f(t_abs+pdt/2,P+pdt/2*k1,Q+pdt/2*kk1));
  Vecteur k3(Q+pdt/2*kk2);
  Vecteur kk3(f(t_abs+pdt/2,P+pdt/2*k2,Q+pdt/2*kk2));
  Vecteur k4(Q+pdt*kk3);
  Vecteur kk4(f(t_abs+pdt,P+pdt*k3,Q+pdt*kk3));
  osc.set_P(P+pdt/6*(k1+2*k2+2*k3+k4));
  osc.set_Q(Q+pdt/6*(kk1+2*kk2+2*kk3+kk4));
  t_abs+=pdt;
} */
