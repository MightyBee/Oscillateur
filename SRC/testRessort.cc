#include <iostream>
#include "TextViewer.h"
#include "Integrateur.h"
#include <cmath>
using namespace std;

int main(){
  try{
    TextViewer tv(cout);
    Ressort r({0.18}, {0}, {0.8,0,0}, {0,0,0}, 1, 0.25, 0, &tv);
    IntegrateurEulerCromer euler;
    for(int i(1);i<=100;i++){
      euler.evolue(r,0.1);
      r.dessine();
    }
    Ressort r2;
    cout << r2.position() << endl;
    cout << r2.get_angleNutation() << endl;
    IntegrateurNewmark nmk(r2, 0.1, 0);
    for(int i(1);i<=100;i++){
      nmk.evolue();
      cout << nmk << endl;
    }
    

  }catch(Erreur err){
    err.affiche("testRessort.cc");
  }

  return 0;
}
