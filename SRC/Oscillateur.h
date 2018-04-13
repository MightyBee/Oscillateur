#pragma once
#include <initializer_list>
#include "Vecteur.h"
#include "constantes.h"

class Oscillateur{
  public:
    //constructeurs
    explicit Oscillateur(const unsigned int& n=3); // construit un Oscillateur à n degrés de liberté, avec tous les parametres à zéro
    explicit Oscillateur(const std::initializer_list<double>& liP, // construit un Oscillateur à 3 degrés de libert
                         const std::initializer_list<double>& liQ);
    explicit Oscillateur(const std::initializer_list<double>& liP, //construit un Oscillateur avec son origine et son axe
                         const std::initializer_list<double>& liQ,
                         const std::initializer_list<double>& liO,
                         const std::initializer_list<double>& lia);
    //accesseurs
    Vecteur get_P() const; // retourne le vecteur des paramètres de l'oscillateur
    Vecteur get_Q() const; // retourne le vecteur des "vitesses" de l'oscillateur

    //manipulateurs
    void set_P(const Vecteur& p); // permet de modifier l'intégralité des paramètres
    void set_P(unsigned int n, double newValeur); // permet de modifier un des paramètre
    void set_Q(const Vecteur& q); // permet de modifier l'intégralité des "vitesses"
    void set_Q(unsigned int n, double newValeur); // permet de modifier une des "vitesses"

    //autres opérations
    Vecteur f(const double& t=0) const; // fonction P''=f(t,P,P') : détermine le mouvement de l'oscillateur
    std::ostream& affiche(std::ostream& sortie=std::cout) const; // permet permet d'afficher le vecteur par composants sur un flot de sortie
    Vecteur position()const;

  protected:
    //attributs
    Vecteur P; // vecteur contenant les paramètres de l'oscillateur
    Vecteur Q; // vecteur contenenat les dérivées des paramètres
    Vecteur O; //vecteur représentant la position de référence (origine)
    Vecteur a; //vecteur représentant la direction principale (axe)
};

std::ostream& operator<<(std::ostream& sortie, const Oscillateur& osc); // permet l'affichage standard : sortie << oscillateur;

class Pendule :public Oscillateur{
public:
  //constructeur
  explicit Pendule(const std::initializer_list<double>& liP
                  ,const std::initializer_list<double>& liQ
                  ,const std::initializer_list<double>& liO
                  ,const std::initializer_list<double>& lia
                  ,double longueur, double masse, double frottement);
  //autres opérations
  Vecteur f(const double& t) const;
  Vecteur position()const;

private:
  double L;
  double m;
  double frott;
};

class Ressort :public Oscillateur{
public:
  //constructeur
  explicit Ressort(const std::initializer_list<double>& liP
                  ,const std::initializer_list<double>& liQ
                  ,const std::initializer_list<double>& liO
                  ,const std::initializer_list<double>& lia
                  ,double raideur,double masse, double frottement);
  //autre fonctions
  Vecteur f(const double& t) const;
  Vecteur position()const;

private:
  double k;
  double m;
  double frott;
};
