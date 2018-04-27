#include <iostream>
#include <initializer_list>
#include <cmath>
#include "Oscillateur.h"
#include "constantes.h"
using namespace std;

/*##############################################################################
###                                                                          ###
###                    METHODES DE LA CLASSE Oscillateur                     ###
###                                                                          ###
##############################################################################*/

//#############################  constructeurs  ##############################//
// construit un Oscillateur à partir d'une liste pour les paramètres et une autre pour leurs dérivées //
Oscillateur::Oscillateur(SupportADessin* support,
                         const initializer_list<double>& liP,
                         const initializer_list<double>& liQ,
                         const initializer_list<double>& lia,
                         const initializer_list<double>& liO)
                        : Dessinable(support), P(liP), Q(liQ), a(~Vecteur(lia)), O(liO)
                        {if(liP.size()!=liQ.size()){
                          Erreur err("dimension", "Oscillateur::Oscillateur(const initializer_list<double>& x4)",
                    		             "Les dimensions des vecteurs 'parametre' et 'vitesse' doivent être les mêmes (ici : "+to_string(liP.size())+" et "+to_string(liQ.size())+")");
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
    Erreur r("dimension", "Oscillateur::set_P(const Vecteur&)",
             "La dimension attendue du vecteur passé en paramètre était "+to_string(P.taille())+", et non pas "+to_string(p.taille()));
    throw r;
  }
  else{
    P=p;}
}

// permet de modifier un paramètre de l'Oscillateur
void Oscillateur::set_P(unsigned int n, double newValeur){
  try{P.set_coord(n,newValeur);}
  catch(Erreur err){
    err.add_fct("Oscillateur::set_P(unsigned int, double)");
    throw err;
  }
}

// permet de modifier l'intégralité des "vitesses" //
void Oscillateur::set_Q(const Vecteur& q){
  if(q.taille() != Q.taille()){
    Erreur r("dimension", "Oscillateur::set_Q(const Vecteur&)",
             "La dimension attendue du vecteur passé en paramètre était "+to_string(Q.taille())+", et non pas "+to_string(q.taille()));
    throw r;
  }
  else{
    Q=q;}
}

// permet de modifier une vitesse de l'Oscillateur
void Oscillateur::set_Q(unsigned int n, double newValeur){
  try{Q.set_coord(n,newValeur);}
  catch(Erreur err){
    err.add_fct("Oscillateur::set_Q(unsigned int, double)");
    throw err;
  }
}



// permet l'affichage d'un oscillateur de façon standardisée //
ostream& Oscillateur::affiche(ostream& sortie) const{
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
Pendule::Pendule(SupportADessin* support,
                 const std::initializer_list<double>& liP,
                 const std::initializer_list<double>& liQ,
                 const std::initializer_list<double>& lia,
                 const std::initializer_list<double>& liO,
                 double longueur, double masse, double frottement)
                 : Oscillateur(support,liP, liQ, lia, liO), L(longueur), m(masse), frott(frottement) //TODO ERREUR : dimensions, a*g=0
                 {} //TODO question : comment catcher une erreur lancée par le constructeur de Oscillateur ?

unique_ptr<Pendule> Pendule::clone() const{
  return unique_ptr<Pendule>(new Pendule(*this));
}

unique_ptr<Oscillateur> Pendule::copie() const{
  return clone();
}

void Pendule::dessine(){
  if(support!=nullptr){
    support->dessine(*this);
  }
}

//fonction d'évolution
Vecteur Pendule::f(const double& t) const{
    Vecteur retour({-(g.norme()/L)*sin(P.get_coord(1))-(frott*Q.get_coord(1)/(m*L*L))});
    return retour;
}
//retourne position d'un pendule
Vecteur Pendule::position() const {
  Vecteur retour(O + L*cos(P.get_coord(1))*(~g) + L*sin(P.get_coord(1))*a);
  return retour;
}

// permet l'affichage d'un oscillateur de façon standardisée //
ostream& Pendule::affiche(ostream& sortie) const{
  sortie << "# Pendule :" << endl;
  sortie << P << " # parametre (angle)" << endl;
  sortie << Q << " # vitesse angulaire" << endl;
  sortie << position() << "# position" << endl;
  return sortie;
}

/*##############################################################################
###                                                                          ###
###                    METHODES DE LA CLASSE Ressort                         ###
###                                                                          ###
##############################################################################*/
//constructeur
Ressort::Ressort(SupportADessin* support,
                 const std::initializer_list<double>& liP,
                 const std::initializer_list<double>& liQ,
                 const std::initializer_list<double>& lia,
                 const std::initializer_list<double>& liO,
                 double raideur,double masse, double frottement)
                  : Oscillateur(support, liP,liQ,lia,liO)//TODO ERREUR
                  ,k(raideur), m(masse), frott(frottement){}

unique_ptr<Ressort> Ressort::clone() const{
  return unique_ptr<Ressort>(new Ressort(*this));
}

unique_ptr<Oscillateur> Ressort::copie() const{
  return clone();
}

void Ressort::dessine(){
  if(support!=nullptr){
    support->dessine(*this);
  }
}

//fonction d'évolution
Vecteur Ressort::f(const double& t) const{
    Vecteur retour({(-(k/m)*P.get_coord(1)-(frott/m)*Q.get_coord(1)+g*a)});
    return retour;
}
//retourne la position d'un ressort
Vecteur Ressort::position()const{
    return O + P.get_coord(1)*a;
}

// permet l'affichage d'un oscillateur de façon standardisée //
ostream& Ressort::affiche(ostream& sortie) const{
  sortie << "# Ressort :" << endl;
  sortie << P << " # parametre (distance de l'origine)" << endl;
  sortie << Q << " # vitesse" << endl;
  sortie << position() << "# position" << endl;
  return sortie;
}
