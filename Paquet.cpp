#include "Paquet.h"
#include "TypeBiscuit.h"

Paquet::Paquet()
{
<<<<<<< HEAD
	cout << "Creation paquet sans paramètre" << endl;
=======
>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
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
<<<<<<< HEAD
	cout << "Destruction Paquet" << endl;
=======

>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
}

string Paquet::afficher()
{
	string s = "Paquet : " + biscuit.nom + " " + to_string(quantite);
	return s;
}

