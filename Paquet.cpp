#include "Paquet.h"
#include "TypeBiscuit.h"

Paquet::Paquet()
{
	quantite = 0; 
}

Paquet::Paquet(const TypeBiscuit& pTypeBiscuit, int _quantite)
{
	biscuit = pTypeBiscuit;
	quantite = _quantite;
}

Paquet::~Paquet()
{

}

string Paquet::afficher()
{
	string s = "Paquet : " + biscuit.nom + " " + to_string(quantite);
	return s;
}

