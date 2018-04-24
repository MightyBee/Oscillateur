#include <iostream>
#include "Oscillateur.h"
#include "Vecteur.h"
#include "Integrateur.h"
#include <cmath>
using namespace std;

int main(){
  try{
    Ressort r({0.18}, {0}, {0.8,0,0.6}, {0,0,0}, 0.33, 0.25, 0.15);
    IntegrateurEulerCromer euler(&r, 0.1, 0);
    for(int i(1);i<=100;i++){
      euler.evolue();
      cout << euler << endl;
    }
  }catch(Erreur err){
    err.affiche("testRessort.cc");
  }

  return 0;
}
