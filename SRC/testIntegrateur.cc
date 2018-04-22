#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
using namespace std;

int main(){
  Pendule p({M_PI/3});
  Ressort r({1});
  double dt=0.01, t=0;
  IntegrateurEulerCromer ec(&r,dt,t);
  cout << ec << p.position() << endl;
  for(int i(1);i<=10000;i++){
    ec.evolue();
    cout << r.position().get_coord(1) << " " << dt*i+t << " # parametre" << endl;
  }

  return 0;
}
