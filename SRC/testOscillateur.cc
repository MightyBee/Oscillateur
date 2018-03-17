#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
using namespace std;

int main(){
  try{
  Oscillateur osc1;
  Oscillateur osc2(5);
  Oscillateur osc3(1.1,2.2,3.3,4.4,5.5,6.6);
  cout << osc1 << osc2 << osc3 << endl;
  Oscillateur osc4({1,2},{3,4});
  cout << osc4 << endl;
  Oscillateur osc5({1,2},{3,4,5});
  cout << osc5 << endl;
  }catch(Erreur err){
    cerr << endl << endl << "### ERREUR FATALE ###" << endl;
		cerr << "Type d'erreur : " << err.type << endl;
    cerr << "Dans fichier  : testOscillateur.cc" << endl;
		cerr << "Dans fonction : " << err.fct << endl;
		cerr << "Description   : " << err.description << endl;
		cerr << "### FIN DU PROGRAMME ###" << endl << endl;
  }
  return 0;
}
