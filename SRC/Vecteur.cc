#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <initializer_list>
#include "Vecteur.h"
using namespace std;


// constructeurs
Vecteur::Vecteur(const unsigned int& n) : coord(n,0) {}
Vecteur::Vecteur(const double& x, const double& y, const double& z) : coord({x,y,z}) {}
Vecteur::Vecteur(const initializer_list<double>& liste) : coord(liste) {}
// accesseurs //

size_t Vecteur::taille() const{
	return coord.size();
}

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

// manipulateurs //

void Vecteur::augmente(double newCoord){
	coord.push_back(newCoord);
}

void Vecteur::set_coord(unsigned int n, double newValeur){
	if(n>coord.size()){              //erreur : position trop grande par rapport a la dim du vecteur
		Erreur err;
		err.type="dimension";
		err.fct="Vecteur::set_cord(unsigned int n, double newValeur)";
		err.description="L'indice de position fourni en argument ("+to_string(n)+") ";
		err.description+="est plus grande que la dimension du vecteur ("+to_string(coord.size())+").";
		throw err;
	}
	else{coord[n-1]=newValeur;}      //la position joue avec la dimension du vecteur
}

//calcul le produit vectoriel uniquement de deux vecteurs de dimension 3
Vecteur Vecteur::operator^(const Vecteur& v2) const{
	if(coord.size()==3 and v2.coord.size()==3){
		return Vecteur((coord[1]*v2.coord[2])-(coord[2]*v2.coord[1]),
                 	(coord[2]*v2.coord[0])-(coord[0]*v2.coord[2]),
                 	(coord[0]*v2.coord[1])-(coord[1]*v2.coord[0]));
	} else {
		Erreur err;
		throw err;
	}
}

// autres operations /

// affichage des coordonnees du vecteur
ostream& Vecteur::affiche(ostream& sortie)const{
	sortie << "( ";
	for(auto el : coord){
		sortie << el << " " ;
	}
	sortie << ")";
	return sortie;
}

<<<<<<< HEAD
=======
string Vecteur::to_str() const{
	string retour("(");
	for (auto el : coord){
		retour+=to_string(el)+" ";
	}
	return retour.substr(0,retour.size()-1)+")";
}

// multiplication du vecteur par un scalaire
Vecteur Vecteur::mult(double lambda) const{
	Vecteur retour;
	for(auto el : coord){
		retour.augmente(lambda*el);
	}
	return retour;
}
>>>>>>> eff55a92b60b1ebfe2fa131684623ae5bfe30398

// produit scalaire entre deux vecteurs
double Vecteur::operator*(const Vecteur& v2) const{
	double retour(0.0);
	for(size_t i(0);i<coord.size();i++){
		retour+=coord[i]*v2.coord[i];
	}
	return retour;
}

// retourne la norme d'un vecteur
double Vecteur::norme() const{
	return sqrt(norme2());
}

// retourne la norme au carre d'un vecteur : c'est <v,v>
double Vecteur::norme2() const{
	return (*this)*(*this);
}


//opérateur << pour afficher
ostream& operator<<(ostream& sortie, const Vecteur& v){
	return v.affiche(sortie);
}

Vecteur& Vecteur::operator+=(const Vecteur& v2){
	for(size_t i(0);i<coord.size();i++){
		coord[i]+=v2.coord[i];
	}
	return *this;
}


Vecteur& Vecteur::operator-=(const Vecteur& v2){
	operator+=(-v2);
	return *this;
}

Vecteur& Vecteur::operator*=(const double& lambda){
	for(auto& el : coord){
		el*=lambda;
	}
	return *this;
}

//ooperator + passé en surcharge externe
const Vecteur operator+(Vecteur v1, const Vecteur& v2){
	v1+=v2;
	return v1;
}

//operator - passé en surchage interne
const Vecteur operator-(Vecteur v1, const Vecteur& v2){
	v1-=v2;
	return v1;
}

//operator - en interne. cette fois pour remplacer oppose()
const Vecteur operator-(Vecteur v){
	v*=-1;
	return v;
}

//multiplication en externe
const Vecteur operator*(const double& lambda, Vecteur v){
	v*=lambda;
	return v;
}

const Vecteur operator*(const Vecteur& v, const double& lambda){
	return lambda*v;
}
