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
<<<<<<< HEAD
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
=======
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
>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
	return 0;
}

