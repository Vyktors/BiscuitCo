#include "Paquet.h"
#include "TypeBiscuit.h"

Paquet::Paquet()
{
	biscuit = TypeBiscuit("");
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

void Paquet::afficher()
{
	cout << "Paquet : " << biscuit.nom << " " << quantite << endl;
}

