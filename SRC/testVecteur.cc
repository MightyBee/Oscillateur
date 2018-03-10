#include <iostream>
#include "Vecteur.h"
using namespace std;


int main(){
	Vecteur v;
	v.augmente(2.0); v.augmente(3.0);
	v.affiche();
	v.set_coord(2,4.0); v.augmente(6.0);
	v.affiche();
	try{v.set_coord(4,20.0);}
	catch(int i){
		if(i==111){
			cerr << "La position est plus grande que la dimension de vecteur." << endl;
		}
	}
	cout << v.taille() << " " <<  endl;
	Vecteur v2;
	v2.augmente(2.0); v2.augmente(4.0); v2.augmente(2);
	if(v.compare(v2)){cout << "Yes" << endl;}else{cout << "Non" << endl;}
	v.affiche(); v2.affiche();
	v.addition(v2).oppose().affiche();
	v.soustraction(v2).affiche();
	Vecteur v3(4); v3.affiche(); // test du constructeur n-D initilisant avec des zeros
	Vecteur v4(2.0,0,-3.23); v4.affiche(); //test du constructeur 3D
	Vecteur v5({2.0,0,-3.24,6,7}); v5.affiche(); //test du constructeur par liste
	Vecteur v6(v5); v6.affiche(); //test du constructeur de copie par defaut
	return 0;
}
