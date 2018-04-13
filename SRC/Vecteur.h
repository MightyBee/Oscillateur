#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <initializer_list>



struct Erreur{ // definit le type Erreur que l'on lance s'il y a ... une erreur
	std::string type;
	std::string fct;
	std::string description;
};



class Vecteur {
	public:
		//constructeurs
		explicit Vecteur(const unsigned int& n=0); // construit un vecteur nul de dimension n et fait office de constructeur par defaut
		explicit Vecteur(const double& x, const double& y, const double& z); // construit un vecteur 3D, avec valeurs x,y,z spécifiées
		explicit Vecteur(const std::initializer_list<double>& liste); // construit un vecteur à partir d'une liste de double

		//operateurs internes
		bool operator==(const Vecteur& v2) const; // retourne true si les vecteurs sont les memes, false sinon
		bool operator!=(const Vecteur& v2) const; // retourne true si les vecteurs sont differents, flase sinon

		Vecteur operator^(const Vecteur& v2) const; // retourne le produit vectoriel de l'instance courante avec un autre vecteur 3D
		double operator*(const Vecteur& v2) const; // retourne le produit scalaire de l'instance courante avec un autre vecteur

		Vecteur& operator+=(const Vecteur& v2); // additionne un vecteur à l'instance courante
		Vecteur& operator-=(const Vecteur& v2); // soustrait un vecteur à l'instance courante
		Vecteur& operator*=(const double& lambda); // multiplie l'instance courante par un scalaire (double)


		//accesseurs
		double get_coord(unsigned int n) const; // accès à un paramètre
		size_t taille() const; // retourne la dim du vecteur

		//manipulateurs
		void augmente(double newCoord=0); // ajoute une dimension au vecteur et affecte une valeur pour cette dimension
		void set_coord(unsigned int n, double newValeur); // modifie la n-ieme coordonnee du vecteur

		//autres operations
		std::ostream& affiche(std::ostream& sortie=std::cout) const; // permet d'afficher le vecteur par composants sur un flot de sortie
		double norme() const; // retourne la norme de l'instance courante
		double norme2() const; // retourne la norme au carré de l'instance courante

	private:
		//attributs
		std::vector<double> coord; // tableau dynamique contenant les coordonees du vecteur
};


// operateurs externes
std::ostream& operator<<(std::ostream& sortie, const Vecteur& v); // permet l'affichage standard : sortie << vecteur;
const Vecteur operator+(Vecteur v1, const Vecteur& v2); // somme de deux vecteurs
const Vecteur operator-(Vecteur v1, const Vecteur& v2); // différence de deux vecteurs
const Vecteur operator-(Vecteur v); // opposé d'un vecteur
const Vecteur operator*(const double& lambda, Vecteur v); // multiplication d'un vecteur par un scalaire, cas scal*vect
const Vecteur operator*(const Vecteur& v, const double& lambda); // multiplication d'un vecteur par un scalaire, cas vect*scal
