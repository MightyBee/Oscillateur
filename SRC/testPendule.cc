#include <iostream>
#include "Oscillateur.h"
#include "Vecteur.h"
#include "Integrateur.h"
#include <cmath>
using namespace std;

int main(){
  try{
    Pendule p({M_PI/2},{0.0},{0.0},{0.0},1.0, 1.0, 0.0);
    IntegrateurEulerCromer euler(p, 0.1, 0);
    for(int i(1);i<=100;i++){
      euler.evolue();
      cout << euler << endl;
    }
  }catch(Erreur err){
    err.affiche("testPendule.cc");
  }
  return 0;
}
