#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <initializer_list>
#include "Vecteur.h"
using namespace std;


/*##############################################################################
###                                                                          ###
###                      METHODES DE LA CLASSE Vecteur                       ###
###                                                                          ###
##############################################################################*/

//#############################  constructeurs  ##############################//
// construit un vecteur nul de dimension n et fait office de constructeur par defaut
Vecteur::Vecteur(const unsigned int& n) : coord(n,0) {}

// construit un vecteur 3D, avec valeurs x,y,z spécifiées
Vecteur::Vecteur(const double& x, const double& y, const double& z) : coord({x,y,z}) {}

// construit un vecteur à partir d'une liste de double
Vecteur::Vecteur(const initializer_list<double>& liste) : coord(liste) {}


//##########################  opérateurs internes  ###########################//
// opérateurs de comparaison //
bool Vecteur::operator==(const Vecteur& v2) const{
	if(coord.size()!=v2.coord.size()){
		return false;
	} else {
		for(size_t i(0);i<coord.size();i++){
			if(coord[i]!=v2.coord[i]){return false;}
		}
		return true;
	}
}
bool Vecteur::operator!=(const Vecteur& v2) const{
	return not operator==(v2);
}

// retourne le produit vectoriel du vecteur courant avec un autre vecteur 3D //
Vecteur Vecteur::operator^(const Vecteur& v2) const{
	if(coord.size()==3 and v2.coord.size()==3){
		return Vecteur((coord[1]*v2.coord[2])-(coord[2]*v2.coord[1]),
                 	(coord[2]*v2.coord[0])-(coord[0]*v2.coord[2]),
                 	(coord[0]*v2.coord[1])-(coord[1]*v2.coord[0]));
	} else {
		Erreur err;
		err.type="dimension";
		err.fct="Vecteur::operator^(const Vecteur&), i.e. produit vectoriel";
		err.description="Les dimensions des vecteurs ("+to_string(coord.size())+" et "+to_string(v2.coord.size());
		err.description+=") ne correspondent pas à celles attendues (3 et 3).";
		throw err;
	}
}

// retourne produit scalaire du vecteur courant avec un autre vecteur //
double Vecteur::operator*(const Vecteur& v2) const{
	double retour(0.0);
	for(size_t i(0);i<coord.size();i++){
		retour+=coord[i]*v2.coord[i];
	}
	return retour;
}

// addition d'un vecteur au vecteur courant //
Vecteur& Vecteur::operator+=(const Vecteur& v2){
	for(size_t i(0);i<coord.size();i++){
		coord[i]+=v2.coord[i];
	}
	return *this;
}

// soustraction d'un vecteur au vecteur courant //
Vecteur& Vecteur::operator-=(const Vecteur& v2){
	operator+=(-v2);
	return *this;
}

// multiplication du vecteur courant par un scalaire //
Vecteur& Vecteur::operator*=(const double& lambda){
	for(auto& el : coord){el*=lambda;}
	return *this;
}


//##############################  accesseurs  ################################//
// accès à un paramètre
double Vecteur::get_coord(unsigned int n) const{                 //TODO excption
	return coord[n-1];
}

// retourne la dimension du vecteur //
size_t Vecteur::taille() const{
	return coord.size();
}


//#############################  manipulateurs  ##############################//
// ajoute une dimension au vecteur courant, possibilité de specifier la valeur de la nouvelle composante (par défaut : 0) //
void Vecteur::augmente(double newCoord){
	coord.push_back(newCoord);
}

// modifie la n-ieme coordonnee du vecteur //
void Vecteur::set_coord(unsigned int n, double newValeur){
	if(n>coord.size()){              //erreur : position trop grande par rapport a la dim du vecteur
		Erreur err;
		err.type="dimension";
		err.fct="Vecteur::set_cord(unsigned int, double)";
		err.description="L'indice de position fourni en argument ("+to_string(n)+") ";
		err.description+="est plus grande que la dimension du vecteur ("+to_string(coord.size())+").";
		throw err;
	}
	else{coord[n-1]=newValeur;}      //la position joue avec la dimension du vecteur
}


//###########################  autres opérations  ############################//
// affichage des coordonnees du vecteur //
ostream& Vecteur::affiche(ostream& sortie)const{
	sortie << "( ";
	for(auto el : coord){
		sortie << el << " " ;
	}
	sortie << ")";
	return sortie;
}

// retourne la norme du vecteur courant //
double Vecteur::norme() const{
	return sqrt(norme2());
}

// retourne la norme au carré du vecteur courant : c'est <v,v> //
double Vecteur::norme2() const{
	return (*this)*(*this);
}



/*##############################################################################
###                                                                          ###
###                           OPÉRATEURS EXTERNES                            ###
###                                                                          ###
##############################################################################*/

// permet l'affichage standard : sortie << vecteur; //
ostream& operator<<(ostream& sortie, const Vecteur& v){
	return v.affiche(sortie);
}

// somme de deux vecteurs //
const Vecteur operator+(Vecteur v1, const Vecteur& v2){
	v1+=v2;
	return v1;
}

// différence de deux vecteurs //
const Vecteur operator-(Vecteur v1, const Vecteur& v2){
	v1-=v2;
	return v1;
}

// opposé d'un vecteur //
const Vecteur operator-(Vecteur v){
	v*=-1;
	return v;
}

// multiplication d'un vecteur par un scalaire, cas scal*vect //
const Vecteur operator*(const double& lambda, Vecteur v){
	v*=lambda;
	return v;
}

// multiplication d'un vecteur par un scalaire, cas vect*scal //
const Vecteur operator*(const Vecteur& v, const double& lambda){
	return lambda*v;
}
