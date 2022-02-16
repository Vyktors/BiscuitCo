#include "Paquet.h"
#include "TypeBiscuit.h"

Paquet::Paquet()
{
	cout << "Creation paquet sans param�tre" << endl;
	quantite = 0; 
}

Paquet::Paquet(const TypeBiscuit& pTypeBiscuit, int _quantite)
{
	cout << "Creation paquet avec param�tre" << pTypeBiscuit.nom << " " << _quantite  << endl;
	biscuit = pTypeBiscuit;
	quantite = _quantite;
}

Paquet::~Paquet()
{
	cout << "Destruction Paquet" << endl;
}

string Paquet::afficher()
{
	string s = "Paquet : " + biscuit.nom + " " + to_string(quantite);
	return s;
}

