#include <iostream>
#include <string>
#include "Liste.h"
#include "Client.h"
#include "Paquet.h"
#include "Commande.h"


using namespace std;


int main()
{

	Client Vic("Vic",25,"Quinn");
	Client Sophie("Sophie", 5468, "Lalancette");

	const TypeBiscuit CHOCOLAT("Chocolat");
	const TypeBiscuit MACADAM("Macadam");
	const TypeBiscuit NOIX("Noix"); 
	
	Paquet p1(CHOCOLAT, 45);
	Paquet p2(MACADAM, 21);
	Paquet p3(NOIX, 5);
	
	Commande c(Vic.nom(), Sophie.nom());
	c.ajouterPaquet(p1);
	c.ajouterPaquet(p2);
	c.ajouterPaquet(p3);
	
	Vic.ajouterCommande(c);

	Vic.afficher();
	Sophie.afficher();

	system("pause");
	return 0;
}