#include <iostream>
#include <vector>
#include "Vecteur.h"
using namespace std;

// manipulateurs /

void Vecteur::augmente(double newCoord){
	coord.push_back(newCoord);
}

void Vecteur::set_coord(int n, double newValeur){ // gerer les erreurs
	coord[n-1]=newValeur;
}

// autres operations /

void Vecteur::affiche(){
	for(auto el : coord){
		cout << el << " " ;
	}
	cout << endl;
}
