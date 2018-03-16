#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <initializer_list>

struct Erreur{
	std::string type;
	std::string fct;
	std::string description;
};

class Vecteur {
public:
	//constructeurs
	explicit Vecteur(const unsigned int& n=0);
	explicit Vecteur(const double& x, const double& y, const double& z);
	explicit Vecteur(const std::initializer_list<double>& liste);
	//accesseurs
	size_t taille() const; // retourne la dim du vecteur
	bool operator==(const Vecteur& v2) const; // retourne vrai/faux si les vecteurs sont les memes
	bool operator!=(const Vecteur& v2) const;
	//manipulateurs
	void augmente(double newCoord); // ajoute une dimension au vecteur et une valeur pour cette dimension
	void set_coord(unsigned int n, double newValeur); // modifie la n-ieme coordonnee du vecteur
	Vecteur operator^(const Vecteur& v2) const;
	double operator*(const Vecteur& v2) const;


	Vecteur& operator+=(const Vecteur& v2);
	Vecteur& operator-=(const Vecteur& v2);
	Vecteur& operator*=(const double& lambda);

	//autres operations
	std::ostream& affiche(std::ostream& sortie=std::cout) const;
	double norme() const;
	double norme2() const;

private:
	//attributs
	std::vector<double> coord; // tableau dynamique contenant les coordonees du vecteur
	//accessuers
};

std::ostream& operator<<(std::ostream& sortie, const Vecteur& v);
//okaay

const Vecteur operator+(Vecteur v1, const Vecteur& v2);
const Vecteur operator-(Vecteur v1, const Vecteur& v2);
const Vecteur operator-(Vecteur v);
//multiplication en externe
const Vecteur operator*(const double& lambda, Vecteur v);
const Vecteur operator*(const Vecteur& v, const double& lambda);
