#pragma once
#include "Oscillateur.h"
#include "Vecteur.h"

class Integrateur{
  public:
    explicit Integrateur(const Oscillateur& osc, const double& pdt=0.01, const double t=0);
    // note : on doit toujours initiliser un integrateur en lui associant un oscillateur, pas de constructeur par défaut
    void evolue();
    Oscillateur get_osc();
    double get_t();
    std::ostream& affiche(std::ostream& sortie=std::cout) const;
  protected:
    Oscillateur osc;
    double pdt;
    double t_abs;
};

std::ostream& operator<<(std::ostream& sortie, const Integrateur& integrat); // permet l'affichage standard : sortie << integrateur;


class IntegrateurEulerCromer : public Integrateur{
  public:
    explicit IntegrateurEulerCromer(const Integrateur& integrat);
    explicit IntegrateurEulerCromer(const Oscillateur& osc, const double& pdt=0.01, const double t=0);
    void evolue();
  private:
    //uu
};

class IntergrateurRungeKutta : public Integrateur{
  public:
    void evolue();
  private:
    //uuu
};
