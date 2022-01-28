#include "Commande.h"

using namespace std;


Commande::Commande()
{
	client_source = "";
	client_destinataire = "";
	listePaquet = Liste<Paquet>();
}

Commande::Commande(string _client_source, string _client_destinataire)
{
	client_source = _client_source;
	client_destinataire = _client_destinataire;
	listePaquet = Liste<Paquet>();
}

Commande::~Commande()
{
}

void Commande::ajouterPaquet(Paquet& _paquet)
{
	listePaquet.InsererQueue(_paquet);
}

void Commande::afficher()
{
	for (listePaquet.FixerTete(); listePaquet.EstDansListe(); listePaquet.Suivant())
	{
		//cout << listePaquet.ValeurCourante().Afficher() << endl;
	}
}


