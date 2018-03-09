#pragma once
#include <vector>


class Vecteur {
public:
	//accesseurs
	size_t taille() const;
	bool compare(Vecteur v2) const;
	//manipulateurs
	void augmente(double newCoord); // ajoute une dimension au vecteur et une valeur pour cette dimension
	void set_coord(unsigned int n, double newValeur); // modifie la n-ieme coordonnee du vecteur
	Vecteur addition( Vecteur autre) const;
	Vecteur oppose() const;
	Vecteur soustraction(Vecteur autre) const;
	Vecteur prod_vect(Vecteur autre) const;
	//autres operations
	void affiche(); // affiche le vecteur

private:
	//attributs
	std::vector<double> coord; // tableau dynamique contenant les coordonees du vecteur
	//accessuers
};

//okaay
