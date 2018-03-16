#include <iostream>
#include "Vecteur.h"
using namespace std;


int main(){
	/*
	//essai des methodes augmente et affiche
	cout << "Ajout de dimensions au 1er vecteur : " << endl;
	Vecteur v1; v1.augmente(2.0); v1.affiche(); v1.augmente(3.0); v1.affiche(); v1.augmente(6.0); v1.affiche();
	//essai de la methode set_coord et lancement d'erreur
	try{cout << "Modification de la 2eme coordonnee : " << endl;
	v1.set_coord(2,4.0); v1.affiche();
	cout << "Modification de la 4eme coordonnee : " << endl;
	v1.set_coord(4,20.0); v1.affiche();}
	catch(int i){
		if(i==111){
			cerr << "La position est plus grande que la dimension de vecteur." << endl;
		}
	}
	// Essai de la methode taille
	cout << "Taille du 1er vecteur : " << v1.taille() << " " <<  endl;
	//Essai de la fonction compare
	Vecteur v2; v2.augmente(2.0); v2.augmente(4.0); v2.augmente(2);
	cout << "Création du 2eme vecteur ... --> "; v2.affiche();
	cout << "v1 : "; v1.affiche();
	cout << "v2 : "; v2.affiche();
	cout << "v1 et v2 sont-ils égaux ?" << endl;
	if(v1.compare(v2)){cout << "Yes" << endl;}else{cout << "Non" << endl;}
	//Essai des methode addition, opppose et soustraction
	v1.addition(v2).oppose().affiche();
	v1.soustraction(v2).affiche();
	Vecteur v3(4); v3.affiche(); // test du constructeur n-D initilisant avec des zeros
	Vecteur v4(2.0,0,-3.23); v4.affiche(); //test du constructeur 3D
	Vecteur v5({2.0,0,-3.24,6,7}); v5.affiche(); //test du constructeur par liste
	Vecteur v6(v5); v6.affiche(); //test du constructeur de copie par defaut
	*/
	Vecteur v(2,4,5);
	cout << v;
	Vecteur v2(2,4,5);
	if(v==v2){
		cout << "Noice" << endl;
	} //test de l'operator ==
	Vecteur v3(2,3,5);
	if (v!=v3){
		cout << v3 << "différent de" << v << endl;
	} // je veux voir si != est compris automatiquement
	//conclustion != n'est pas compris automatiquement :)
	Vecteur v4(1,1,1);
	v4-=v;
	v4*=2.5;
	cout << v4 << endl;

	//v -= v4;
	cout << v << endl;
	cout << v + v4 << endl;
	//cout << v - v4 << endl;
	cout << -v << endl;
	//cout << 7 * v << endl;

	return 0;
}
