#include <iostream>
#include <vector>
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

// autres operations /

void Vecteur::affiche(){
	for(auto el : coord){
		cout << el << " " ;
	}
	cout << endl;
}
