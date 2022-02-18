#include "Paquet.h"
#include <iomanip>

Paquet::Paquet()
{
	quantite = 0; 
}

Paquet::Paquet(string _biscuit, int _quantite)
{
	biscuit = _biscuit;
	quantite = _quantite;
}

Paquet::~Paquet()
{

}

void Paquet::afficher()
{
	cout << "Paquet : " << setw(20) << biscuit << " " << setw(8) << to_string(quantite) << endl;
	
}

void Paquet::ajouterQt(int nbr) {
	quantite = quantite + nbr;
}

void Paquet::setQt(int nbr) {
	quantite = nbr;
}

int Paquet::getQt()
{
	return quantite;
}

string Paquet::getNom()
{
	return biscuit;
}
