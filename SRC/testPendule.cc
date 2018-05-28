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
    IntegrateurRungeKutta rk(p, 0.1, 0);
    for(int i(1);i<=100;i++){
      rk.evolue();
      cout << rk << endl;
    }
    Pendule p2({M_PI/3}, {2.0}, {3.9, 0.0, 1.0}, {2.0, 1.0, 4.0}, 7.0, 3.0, 2.4);
    IntegrateurNewmark newma(p2, 0.1, 3);
    for(int i(1);i<=100;i++){
      newma.evolue();
      cout << newma << endl;
    }

    cout << p2.get_angleNutation()<<endl;



  }catch(Erreur err){
    err.affiche("testPendule.cc");
  }
  return 0;
}
