#include "Erreur.h"
#include <iostream>
#include <string>
using namespace std;

Erreur::Erreur(std::string type, std::string fonction, std::string dscrpt)
              : type(type), fct(fonction), description(dscrpt) {}

void Erreur::affiche(string program) const {
  cerr << endl << endl << "### ERREUR FATALE ###" << endl;
  cerr << "Type d'erreur : " << type << endl;
  cerr << "Dans fichier  : "+program << endl;
  cerr << "Dans fonction : " << fct << endl;
  cerr << "Description   : " << description << endl;
  cerr << "### FIN DU PROGRAMME ###" << endl << endl;
}

void Erreur::add_fct(string newFct){
  fct+=" appelée par "+newFct;
}

void Erreur::set_fct(std::string newFct){
  fct=newFct;
}

void Erreur::set_dscrpt(std::string dscrpt){
  description=dscrpt;
}
