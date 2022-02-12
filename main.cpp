#include <iostream>
#include <string>
#include "Liste.h"
#include "Client.h"
#include "Paquet.h"
#include "Commande.h"
#include "Usine.h"

using namespace std;


int main()
{
	const TypeBiscuit CHOCOLAT("Chocolat");
	const TypeBiscuit MACADAM("Macadam");
	const TypeBiscuit NOIX("Noix");

	//Liste de INT ça fonctionne! 
	Liste<int> listeINt;
	listeINt.InsererQueue(4);
	listeINt.InsererQueue(5);

	//Liste de Paquet ça fonctionne! 
	Liste<Paquet> listeP;
	Paquet p1 = Paquet(CHOCOLAT, 20);
	Paquet p2 = Paquet(MACADAM, 22);
	listeP.InsererQueue(p1);
	listeP.InsererQueue(p2);

	//Liste de Commande(Liste de liste), fonctionne pas :(
	Liste<Commande> listeCo;


	system("pause");
	return 0;
}