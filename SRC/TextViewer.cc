#include <iostream>
#include "TextViewer.h"
using namespace std;

TextViewer::TextViewer(ostream& flot) : flot(flot) {}

void TextViewer::dessine(Pendule const& p){
  flot << p << endl;
}

void TextViewer::dessine(Ressort const& r){
  flot << r << endl;
}
