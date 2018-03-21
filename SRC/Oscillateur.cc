#include <iostream>
#include <initializer_list>
#include "Oscillateur.h"
#include "Vecteur.h"
using namespace std;

Oscillateur::Oscillateur(const unsigned int& n) : P(n),Q(n) {}
Oscillateur::Oscillateur(const double& Px, const double& Py, const double& Pz,
                         const double& Qx, const double& Qy, const double& Qz)
                        : P(Px,Py,Pz), Q(Qx,Qy,Qz) {}
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


Vecteur Oscillateur::f(const double& t) const{
  Vecteur retour(P.taille());
  return retour;
}

ostream& Oscillateur::affiche(ostream& sortie)const{
  sortie << "# Oscillateur" << endl;
  sortie << P << " # parametre" << endl;
  sortie << Q << " # vitesse" << endl;
  return sortie;
}


// permet l'affichage standard : sortie << oscillateur; //
ostream& operator<<(ostream& sortie, const Oscillateur& osc){
	return osc.affiche(sortie);
}

Vecteur Oscillateur::get_P() const{return P;}
Vecteur Oscillateur::get_Q() const{return Q;}

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
