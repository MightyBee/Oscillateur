#include <iostream>
#include <initializer_list>
#include "Oscillateur.h"
#include "Vecteur.h"
using namespace std;

/*##############################################################################
###                                                                          ###
###                    METHODES DE LA CLASSE Oscillateur                     ###
###                                                                          ###
##############################################################################*/

//#############################  constructeurs  ##############################//
// construit un Oscillateur à n degrés de liberté, avec tous les parametres à zéro
Oscillateur::Oscillateur(const unsigned int& n) : P(n),Q(n) {}

// construit un Oscillateur à 3 degrés de liberté
Oscillateur::Oscillateur(const double& Px, const double& Py, const double& Pz,
                         const double& Qx, const double& Qy, const double& Qz)
                        : P(Px,Py,Pz), Q(Qx,Qy,Qz) {}

// construit un Oscillateur à partir d'une liste pour les paramètres et une autre pour leurs dérivées
Oscillateur::Oscillateur(const initializer_list<double>& liP,
                         const initializer_list<double>& liQ)
                        : P(liP), Q(liQ)
                        {if(liP.size()!=liQ.size()){
                            Erreur err;
                            err.type="dimension";
                        		err.fct="Oscillateur::Oscillateur(const initializer_list<double>&, const initializer_list<double>&)";
                        		err.description="Les dimensions des vecteurs 'parametre' et 'vitesse' doivent être les mêmes ";
                        		err.description+="(ici : "+to_string(liP.size())+" et "+to_string(liQ.size())+")";
                            throw err;
                          }
                        }


//##############################  accesseurs  ################################//
// retourne le vecteur des paramètres de l'oscillateur //
Vecteur Oscillateur::get_P() const{return P;}

// retourne le vecteur des "vitesses" de l'oscillateur //
Vecteur Oscillateur::get_Q() const{return Q;}


//#############################  manipulateurs  ##############################//
// permet de modifier l'intégralités des paramètres
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

// permet de modifier l'intégralité des "vitesses"
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


//###########################  autres opérations  ############################//
// fonction P''=f(t,P,P') : détermine le mouvement de l'oscillateur
Vecteur Oscillateur::f(const double& t) const{
  Vecteur retour(P.taille());
  return retour;
}

// permet l'affichage d'un oscillateur de façon standardisée
ostream& Oscillateur::affiche(ostream& sortie)const{
  sortie << "# Oscillateur" << endl;
  sortie << P << " # parametre" << endl;
  sortie << Q << " # vitesse" << endl;
  return sortie;
}



/*##############################################################################
###                                                                          ###
###                           OPÉRATEURS EXTERNES                            ###
###                                                                          ###
##############################################################################*/

// permet l'affichage standard : sortie << oscillateur; //
ostream& operator<<(ostream& sortie, const Oscillateur& osc){
	return osc.affiche(sortie);
}
