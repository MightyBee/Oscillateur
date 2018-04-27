#pragma once
#include <initializer_list>
#include <memory>
#include "Vecteur.h"
#include "Dessinable.h"

class Oscillateur : public Dessinable {
  public:
    //constructeurs
    explicit Oscillateur(SupportADessin* support,                  //TODO mettre en dernier et valeur par defaut nullptr
                         const std::initializer_list<double>& liP, //construit un Oscillateur avec son origine et son axe
                         const std::initializer_list<double>& liQ,
                         const std::initializer_list<double>& lia={1,0,0},
                         const std::initializer_list<double>& liO={0,0,0});
    virtual ~Oscillateur(){}
    virtual std::unique_ptr<Oscillateur> copie() const = 0;
    //accesseurs
    Vecteur get_P() const; // retourne le vecteur des paramètres de l'oscillateur
    Vecteur get_Q() const; // retourne le vecteur des "vitesses" de l'oscillateur

    //manipulateurs
    void set_P(const Vecteur& p); // permet de modifier l'intégralité des paramètres
    void set_P(unsigned int n, double newValeur); // permet de modifier un des paramètre
    void set_Q(const Vecteur& q); // permet de modifier l'intégralité des "vitesses"
    void set_Q(unsigned int n, double newValeur); // permet de modifier une des "vitesses"

    //autres opérations
    virtual Vecteur f(const double& t=0) const = 0; // fonction P''=f(t,P,P') : détermine le mouvement de l'oscillateur
    virtual Vecteur position() const = 0;
    virtual std::ostream& affiche(std::ostream& sortie) const; // permet permet d'afficher le vecteur par composants sur un flot de sortie

  protected:
    //attributs
    Vecteur P; // vecteur contenant les paramètres de l'oscillateur
    Vecteur Q; // vecteur contenenat les dérivées des paramètres
    Vecteur a; //vecteur représentant la direction principale (axe)
    Vecteur O; //vecteur représentant la position de référence (origine)
};

std::ostream& operator<<(std::ostream& sortie, const Oscillateur& osc); // permet l'affichage standard : sortie << oscillateur;

class Pendule :public Oscillateur{
public:
  //constructeur
  explicit Pendule(SupportADessin* support,
                   const std::initializer_list<double>& liP={0},
                   const std::initializer_list<double>& liQ={0},
                   const std::initializer_list<double>& lia={1,0,0},
                   const std::initializer_list<double>& liO={0,0,0},
                   double longueur=1, double masse=1, double frottement=0);
  virtual ~Pendule(){}
  std::unique_ptr<Pendule> clone() const;
  virtual std::unique_ptr<Oscillateur> copie() const override;
  virtual void dessine() override;
  //autres opérations
  virtual Vecteur f(const double& t) const override;
  virtual Vecteur position() const override;
  virtual std::ostream& affiche(std::ostream& sortie) const override; // permet permet d'afficher le vecteur par composants sur un flot de sortie

private:
  double L;
  double m;
  double frott;
};

class Ressort :public Oscillateur{
public:
  //constructeur
  explicit Ressort(SupportADessin* support,
                   const std::initializer_list<double>& liP={0},
                   const std::initializer_list<double>& liQ={0},
                   const std::initializer_list<double>& lia={1,0,0},
                   const std::initializer_list<double>& liO={0,0,0},
                   double raideur=1, double masse=1, double frottement=0);
  virtual ~Ressort(){}
  std::unique_ptr<Ressort> clone() const;
  virtual std::unique_ptr<Oscillateur> copie() const override;
  virtual void dessine() override;
  //autre fonctions
  virtual Vecteur f(const double& t) const override;
  virtual Vecteur position() const override;
  virtual std::ostream& affiche(std::ostream& sortie) const override; // permet permet d'afficher le vecteur par composants sur un flot de sortie

private:
  double k;
  double m;
  double frott;
};
