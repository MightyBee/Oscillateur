#include <iostream>
#include "TextViewer.h"
#include "Integrateur.h"
#include <cmath>
using namespace std;

int main(){
  try{
    TextViewer tv(cout);
    Pendule p(&tv,{M_PI/2});
    IntegrateurEulerCromer euler;
    for(int i(1);i<=100;i++){
      euler.evolue(p,0.1);
      p.dessine();
    }
  }catch(Erreur err){
    err.affiche("testPendule.cc");
  }
  return 0;
}
