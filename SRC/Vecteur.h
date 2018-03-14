#pragma once
#include <vector>
#include <cmath>
#include <initializer_list>


class Vecteur {
public:
	//constructeurs
	Vecteur(const unsigned int& n=0);
	Vecteur(const double& x, const double& y, const double& z);
	Vecteur(const std::initializer_list<double>& liste);
	//accesseurs
	size_t taille() const; // retourne la dim du vecteur
	bool operator==(Vecteur v2) const; // retourne vrai/faux si les vecteurs sont les memes
	//manipulateurs
	void augmente(double newCoord); // ajoute une dimension au vecteur et une valeur pour cette dimension
	void set_coord(unsigned int n, double newValeur); // modifie la n-ieme coordonnee du vecteur
	Vecteur addition( Vecteur autre) const;
	Vecteur oppose() const;
	Vecteur soustraction(Vecteur autre) const;
	Vecteur prod_vect(Vecteur autre) const;
	//autres operations
	std::ostream& affiche(std::ostream& sortie) const;
	Vecteur mult(double lambda) const;
	double prod_scal(Vecteur autre) const;
	double norme() const;
	double norme2() const;

private:
	//attributs
	std::vector<double> coord; // tableau dynamique contenant les coordonees du vecteur
	//accessuers
};

std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);
//okaay
