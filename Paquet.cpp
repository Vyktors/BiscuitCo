#include "Paquet.h"

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

string Paquet::afficher()
{
	string s = "Paquet : " + biscuit + " " + to_string(quantite);
	return s;
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
