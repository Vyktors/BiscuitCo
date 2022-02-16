#include "Paquet.h"
#include "TypeBiscuit.h"

Paquet::Paquet()
{
	cout << "Creation paquet sans paramètre" << endl;
	quantite = 0; 
}

Paquet::Paquet(const TypeBiscuit& pTypeBiscuit, int _quantite)
{
	cout << "Creation paquet avec paramètre" << pTypeBiscuit.nom << " " << _quantite  << endl;
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

