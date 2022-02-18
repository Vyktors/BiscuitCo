#include "Commande.h"

using namespace std;


Commande::Commande()
{
	client_source = "";
	client_destinataire = "";
}

Commande::Commande(string _client_source, string _client_destinataire)
{
	client_source = _client_source;
	client_destinataire = _client_destinataire;
}

Commande::~Commande()
{

}

void Commande::ajouterPaquet(const Paquet& _paquet)
{
	listePaquet.InsererQueue(_paquet);
}

void Commande::afficher()
{
	cout << "Pour " << client_destinataire << endl;
	for (listePaquet.FixerTete(); listePaquet.EstDansListe(); listePaquet.Suivant())
	{
		listePaquet.ValeurCourante().afficher();
	}
}

string Commande::getCliSource()
{
	return client_source;
}

string Commande::getCliDest()
{
	return client_destinataire;
}

Liste<Paquet>& Commande::getPaquets()
{
	return listePaquet;
}

void Commande::metAJourQtTotal(Liste<Paquet>& listePUsine)
{
	bool dejaLa;
	for (listePaquet.FixerTete(); listePaquet.EstDansListe(); listePaquet.Suivant())
	{
		dejaLa = false;
		for (listePUsine.FixerTete(); listePUsine.EstDansListe(); listePUsine.Suivant())
		{
			if (listePaquet.ValeurCourante().getNom() == listePUsine.ValeurCourante().getNom()) {
				dejaLa = true;
				listePUsine.ValeurCourante().ajouterQt(listePaquet.ValeurCourante().getQt());
			}
		}
		if (!dejaLa) {
			listePUsine.InsererQueue(listePaquet.ValeurCourante());
		}
	}
}




