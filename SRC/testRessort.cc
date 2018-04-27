#include <iostream>
#include "TextViewer.h"
#include "Integrateur.h"
#include <cmath>
using namespace std;

int main(){
  try{
    TextViewer tv(cout);
    Ressort r(&tv,{0.18}, {0}, {0.8,0,0}, {0,0,0}, 1, 0.25, 0);
    IntegrateurEulerCromer euler;
    for(int i(1);i<=100;i++){
      euler.evolue(r,0.1);
      cout << r << endl;
    }
  }catch(Erreur err){
    err.affiche("testRessort.cc");
  }

  return 0;
}
