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
	v.affiche(); v2.affiche();
	cout << v.prod_scal(v2) << endl;
	cout << v.prod_scal(v) << " " << v.norme2() << " " << v.norme() << endl;
	if(v.compare(v2)){cout << "Yes" << endl;}else{cout << "Non" << endl;}
	return 0;
}

// cest trop cool
