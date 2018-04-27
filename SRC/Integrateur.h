#pragma once
#include <memory>
#include "Oscillateur.h"

// super-classe Integrateur, abstraite (pas de méthodes d'intégration numérique spécifiées)
class Integrateur{
  public:
    // constructeur(s)
    // note : on doit toujours initiliser un integrateur en lui associant un oscillateur, pas de constructeur par défaut
    explicit Integrateur(Oscillateur const& osc, const double& pdt=0.01, const double t=0);
    virtual ~Integrateur(){}

    // accesseurs
    double get_t() const; // retourne le temps absolu de l'intégrateur
    std::unique_ptr<Oscillateur> get_osc() const; // retourne l'oscillateur associé à l'intégrateur
    virtual std::unique_ptr<Integrateur> copie() const = 0;
    // autres méthodes
    virtual void evolue() = 0; // méthode qui fait évoluer l'intégrateur d'un pas de temps
    std::ostream& affiche(std::ostream& sortie=std::cout) const; // permet permet d'afficher l'integrateur (temps absolu, état de l'oscillateur) sur un flot de sortie

  protected:
    //attributs
    std::unique_ptr<Oscillateur> osc; // oscillateur auquel est associé l'intégrateur
    double pdt; // pas de temps d'intégration
    double t_abs; // temps absolu, référence
};

std::ostream& operator<<(std::ostream& sortie, const Integrateur& integrat); // permet l'affichage standard : sortie << integrateur;

// classe héritée d'Integrateur, (méthode d'intégration numérique : Euler-Cromer)
class IntegrateurEulerCromer : public Integrateur{
  public:
    // constructeur (note: pas de constructeurs par défaut comme pour la super-classe Integrateur)
    explicit IntegrateurEulerCromer(Oscillateur const& osc, const double& pdt=0.01, const double t=0); // permet d'initialiser tous les attributs d'un intégrateur Euler-Cromer
    virtual ~IntegrateurEulerCromer(){}

    std::unique_ptr<IntegrateurEulerCromer> clone() const;
//{ return unique_ptr<Cercle>(new Cercle(*this)); }

  virtual std::unique_ptr<Integrateur> copie() const override;
//{ return clone(); }
    // autres méthodes
    virtual void evolue() override; // spécialisation de la méthode "evolue()" de la super-classe, avance d'un pas de temps avec la méthode d'intégration d'Euler-Cromer
};

/*
class IntergrateurRungeKutta : public Integrateur{
  public:
    virtual void evolue() override;
  private:
    //uuu
};*/
