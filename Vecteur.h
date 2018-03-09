#pragma once
#include <vector>
#include <math.h>


class Vecteur {
public:
	//accesseurs
	size_t taille() const; // retourne la dim du vecteur
	bool compare(Vecteur v2) const; // retourne vrai/faux si les vecteurs sont les memes
	//manipulateurs
	void augmente(double newCoord); // ajoute une dimension au vecteur et une valeur pour cette dimension
	void set_coord(unsigned int n, double newValeur); // modifie la n-ieme coordonnee du vecteur
	Vecteur addition( Vecteur autre) const;
	Vecteur oppose() const;
	Vecteur soustraction(Vecteur autre) const;
	Vecteur prod_vect(Vecteur autre) const;
	//autres operations
	void affiche(); // affiche le vecteur
	Vecteur mult(double lambda) const;
	double prod_scal(Vecteur autre) const;
	double norme() const;
	double norme2() const;

private:
	//attributs
	std::vector<double> coord; // tableau dynamique contenant les coordonees du vecteur
	//accessuers
};

//okaay
