#include <iostream>
#include <vector>
#include <math.h>
#include "Vecteur.h"
using namespace std;

const int ERRDIM(111);

// accesseurs //

size_t Vecteur::taille() const{
	return coord.size();
}

bool Vecteur::compare(Vecteur v2) const{
	if(coord.size()!=v2.coord.size()){
		return false;
	} else {
		for(size_t i(0);i<coord.size();i++){
			if(coord[i]!=v2.coord[i]){return false;}
		}
		return true;
	}
}

// manipulateurs //

void Vecteur::augmente(double newCoord){
	coord.push_back(newCoord);
}

void Vecteur::set_coord(unsigned int n, double newValeur){
	if(n>coord.size()){throw ERRDIM;}  //erreur : position trop grande par rapport a la dim du vecteur
	else{coord[n-1]=newValeur;}      //la position joue avec la dimension du vecteur
}

//addition de deux vecteurs
Vecteur Vecteur::addition(Vecteur autre) const{
	Vecteur retour;
	if(coord.size()!= autre.coord.size()){
		cerr << "Attention: les dimensions des deux vecteurs n'étaient pas les mêmes. Des zéros ont été rajoutés aux dimensions manquantes." << endl;
	} //gère si les dimenesions sont pas les mêmes: rajoute des zéros
	double ajout(0.0);
	for(size_t i(0); i<coord.size() or i<autre.coord.size();i++, ajout=0){
		if(i<coord.size()) ajout+=coord[i];
		if(i<autre.coord.size()) ajout+=autre.coord[i];
		retour.augmente(ajout);
	}
	return retour;
}

//calcul l'opposé d'un vecteur
Vecteur Vecteur::oppose() const{
	Vecteur retour;
	for(auto el : coord){
		retour.augmente((-1)*el);
	}
	return retour;
}

Vecteur Vecteur::soustraction(Vecteur autre) const{
	return addition(autre.oppose());
}

//calcul le produit vectoriel uniquement de deux vecteurs de dimension 3
Vecteur Vecteur::prod_vect(Vecteur autre) const{
	Vecteur retour;
	if(coord.size()==3 and autre.coord.size()==3){
		retour.augmente((coord[1]*autre.coord[2])-(coord[2]*autre.coord[1]));
		retour.augmente((coord[2]*autre.coord[0])-(coord[0]*autre.coord[2]));
		retour.augmente((coord[0]*autre.coord[1])-(coord[1]*autre.coord[0]));
	}
	//LANCER UNE ERREUR POUR DIM AUTRE QUE 3
	return retour;
}

// autres operations /

// affichage des coordonnees du vecteur
void Vecteur::affiche(){
	for(auto el : coord){
		cout << el << " " ;
	}
	cout << endl;
}

// multiplication du vecteur par un scalaire
Vecteur Vecteur::mult(double lambda) const{
	Vecteur retour;
	for(auto el : coord){
		retour.augmente(lambda*el);
	}
	return retour;
}

/* produit scalaire entre deux vecteurs, si ils n'ont pas la meme dim, pas
besoin de rajouter des zeros au vecteur de dim plus petite car alors toutes
les contributions des coordonnees des dims "sup" apporteraient une
contribution nulle*/
double Vecteur::prod_scal(Vecteur autre) const{
	double retour(0.0);
	for(size_t i(0);i<coord.size() and i<autre.taille();i++){
		retour+=coord[i]*autre.coord[i];
	}
	return retour;
}

// retourne la norme d'un vecteur
double Vecteur::norme() const{
	return sqrt(norme2());
}

// retourne la norme au carre d'un vecteur : c'est <v,v>
double Vecteur::norme2() const{
	return prod_scal(*this);
}
