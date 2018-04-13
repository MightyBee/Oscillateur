#include <iostream>
#include <initializer_list>
#include <cmath>
#include "Oscillateur.h"
#include "Vecteur.h"
#include "constantes.h"
#include <cmath>
using namespace std;

/*##############################################################################
###                                                                          ###
###                    METHODES DE LA CLASSE Oscillateur                     ###
###                                                                          ###
##############################################################################*/

//#############################  constructeurs  ##############################//
// construit un Oscillateur à n degrés de liberté, avec tous les parametres à zéro //
Oscillateur::Oscillateur(const unsigned int& n) : P(n),Q(n) {}
// construit un Oscillateur à partir d'une liste pour les paramètres et une autre pour leurs dérivées //
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

Oscillateur::Oscillateur(const initializer_list<double>& liP,
                         const initializer_list<double>& liQ,
                         const initializer_list<double>& liO,
                         const initializer_list<double>& lia)
                        : P(liP), Q(liQ), O(liO), a(lia)
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
// permet de modifier l'intégralité des paramètres //
void Oscillateur::set_P(const Vecteur& p){
  if(p.taille() != P.taille()){
    Erreur r;
    r.type="dimension";
    r.fct="Oscillateur::set_P(Vecteur const&)";
    r.description="La dimension attendue du vecteur passé en paramètre était "+to_string(P.taille())+", ";
    r.description+="et non pas "+to_string(p.taille());
    throw r;
  }
  else{
    P=p;}
}

// permet de modifier un paramètre de l'Oscillateur
void Oscillateur::set_P(unsigned int n, double newValeur){
  try{P.set_coord(n,newValeur);}
  catch(Erreur err){
    err.fct+=" appelée par Oscillateur::set_P(unsigned int, double)";
    throw err;
  }
}

// permet de modifier l'intégralité des "vitesses" //
void Oscillateur::set_Q(const Vecteur& q){
  if(q.taille() != Q.taille()){
    Erreur r;
    r.type="dimension";
    r.fct="Oscillateur::set_Q(Vecteur const&)";
    r.description="La dimension attendue du vecteur passé en paramètre était "+to_string(Q.taille())+", ";
    r.description+="et non pas "+to_string(q.taille());
    throw r;
  }
  else{
    Q=q;}
}

// permet de modifier une vitesse de l'Oscillateur
void Oscillateur::set_Q(unsigned int n, double newValeur){
  try{Q.set_coord(n,newValeur);}
  catch(Erreur err){
    err.fct+=" appelée par Oscillateur::set_Q(unsigned int, double)";
    throw err;
  }
}


//###########################  autres opérations  ############################//
// fonction P''=f(t,P,P') : détermine le mouvement de l'oscillateur //
Vecteur Oscillateur::f(const double& t) const{
  Vecteur retour({-P.get_coord(1)-0.1*Q.get_coord(1)});
  return retour;
}

// permet l'affichage d'un oscillateur de façon standardisée //
ostream& Oscillateur::affiche(ostream& sortie)const{
  sortie << "# Oscillateur :" << endl;
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


/*##############################################################################
###                                                                          ###
###                    METHODES DE LA CLASSE Pendule                         ###
###                                                                          ###
##############################################################################*/
//constructeur
Pendule::Pendule(const std::initializer_list<double>& liP
                ,const std::initializer_list<double>& liQ
                ,const std::initializer_list<double>& liO
                ,const std::initializer_list<double>& lia
                ,double longueur, double masse, double frottement)
                    :Oscillateur(liP, liQ, liO, lia) //TODO ERREUR
                    , L(longueur), m(masse), frott(frottement){}

//fonction d'évolution
Vecteur Pendule::f(const double& t) const{
    Vecteur retour(1);
    retour.set_coord(1,(-(g.get_coord(3)/L)*sin(P.get_coord(1))-(frott*Q.get_coord(1)/m*L*L)));
    return retour;
}
//retourne position d'un pendule
Vecteur Pendule::position()const{
  return O + L*cos(P.get_coord(1))*g+L*sin(P.get_coord(1))*a;
}

/*##############################################################################
###                                                                          ###
###                    METHODES DE LA CLASSE Ressort                         ###
###                                                                          ###
##############################################################################*/
//constructeur
Ressort::Ressort(const std::initializer_list<double>& liP
                ,const std::initializer_list<double>& liQ
                ,const std::initializer_list<double>& liO
                ,const std::initializer_list<double>& lia
                ,double raideur,double masse, double frottement)
                    :Oscillateur(liP,liQ,liO,lia)//TODO ERREUR
                    ,k(raideur), m(masse), frott(frottement){}
//fonction d'évolution
Vecteur Ressort::f(const double& t) const{
    Vecteur retour(1);
    retour.set_coord(1,(-(k/m)*P.get_coord(1)-(frott/m)*Q.get_coord(1)+g*a));
    return retour;
}
//retourne la position d'un ressort
Vecteur Ressort::position()const{
    return O + P.get_coord(1)*a;
}
