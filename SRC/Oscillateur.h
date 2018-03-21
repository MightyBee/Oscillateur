#pragma once
#include <initializer_list>
#include "Vecteur.h"


class Oscillateur{
public:
  explicit Oscillateur(const unsigned int& n=3);
  explicit Oscillateur(const double& Px, const double& Py, const double& Pz,
                       const double& Qx, const double& Qy, const double& Qz);
  explicit Oscillateur(const std::initializer_list<double>& liP,
                       const std::initializer_list<double>& liQ);

  Vecteur f(const double& t) const;

  void affiche();
  //accesseurs
  Vecteur get_P() const;
  Vecteur get_Q() const;
  //manipulateurs
  void set_P(Vecteur const& p);
  void set_Q(Vecteur const& q);

  std::ostream& affiche(std::ostream& sortie=std::cout) const; // permet permet d'afficher le vecteur par composants sur un flot de sortie

protected:
  Vecteur P;
  Vecteur Q;
};

std::ostream& operator<<(std::ostream& sortie, const Oscillateur& osc);

class Pendule :public Oscillateur{
private:
  double L;
  double m;
  double frott;
  Vecteur axe;
  Vecteur origine;
};

class Ressort :public Oscillateur{
private:
  double k;
  double m;
  double frott;
  Vecteur axe;
  Vecteur origine;
};
