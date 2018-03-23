#include <iostream>
#include "Vecteur.h"
#include "Oscillateur.h"
#include "Integrateur.h"
using namespace std;

int main(){
  Oscillateur osc({0},{1});
  IntegrateurEulerCromer ec;
  for(int i(1);i<20000;i++){
    ec.integre(osc,0.01);
    cout << i*0.01 << " " << osc.get_P() << "# parametre" << endl;
  }
  return 0;
}
