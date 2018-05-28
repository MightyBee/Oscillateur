#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
using namespace std;

int main(){
  try{
  Pendule p({M_PI/3});
  Ressort r({1});
  double dt=0.01, t=0;
  //test d'Euler Cromer
  IntegrateurEulerCromer ec(r,dt,t);
  cout << ec << p.position() << endl;
  for(int i(1);i<=100;i++){
    ec.evolue();
    cout << r.position().get_coord(1) << " " << dt*i+t << " # parametre" << endl;
  }
  cout << endl<<endl<<endl;
  //test de Newmark
  IntegrateurNewmark en(r,dt,t);
  for(int i(1); i<=100;i++){
    en.evolue();
    cout << r.position().get_coord(1) << " " << dt*i+t << " # parametre" << endl;
  }
  cout << endl<<endl<<endl;
  // test de Runge-Kutta
  IntegrateurRungeKutta erk(r,dt,t);
  for (int i(1); i<= 100; i++){
    erk.evolue();
    cout << r.position().get_coord(1) << " " << dt*i+t << " # parametre" << endl;
  }
  cout << endl << endl << endl;
//tests variés
IntegrateurNewmark newmark(p, 0.0, 0.0);
for(int i(1); i<=10;i++){
  newmark.evolue();
  cout << p.position().get_coord(1) << " " << dt*i+t << " # parametre" << endl;
}
cout << endl<<endl<<endl;
PenduleDouble pd({M_PI, M_PI/3});
IntegrateurRungeKutta rungek(pd, dt, t);
for(int i(1); i<=10;i++){
  rungek.evolue();
  cout << pd.position().get_coord(1) << " " << dt*i+t << " # parametre" << endl;
}
}
catch(Erreur err){
  err.affiche("testIntegrateur.cc");
}
  return 0;
}
