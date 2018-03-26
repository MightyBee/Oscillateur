#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
using namespace std;

int main(){
  Oscillateur osc({0},{1});
  Integrateur i1(osc,0.01,0);
  IntegrateurEulerCromer ec(i1);
  for(int i(1);i<=2000;i++){
    ec.evolue();
    cout << ec << endl;
  }

  return 0;
}
