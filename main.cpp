#include <iostream>
#include <fstream>
#include <string>
#include "Liste.h"
#include "Client.h"
#include "Paquet.h"
#include "Commande.h"
#include "Usine.h"

using namespace std;


//Création des Types
const TypeBiscuit CHOCOLAT("Chocolat");
const TypeBiscuit MACADAM("Macadam");
const TypeBiscuit NOIX("Noix");

int main()
{

	//Liste de Paquet ça fonctionne à moitié! Le destucteur est appelé deux fois? 

	//Liste<Paquet> listeP;
	Paquet p1(CHOCOLAT, 20);
	//Paquet p2(MACADAM, 22);
	//listeP.InsererQueue(p1);
	//listeP.InsererQueue(p2);


	//Liste de Commande(Liste de liste), fonctionne pas :(
	Liste<Commande> listeCo;
	Commande co1;
	co1.ajouterPaquet(p1);
	listeCo.InsererQueue(co1);

	//system("pause");

	return 0;
}

