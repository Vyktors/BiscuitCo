#include "Usine.h"

Usine::Usine()
{

}

void Usine::ajouterClient(const Client& _client)
{
	listeClient.InsererQueue(_client);
}


void Usine::afficherClient(string s)
{
	for (listeClient.FixerTete(); listeClient.EstDansListe(); listeClient.Suivant())
	{
		if (listeClient.ValeurCourante().nom() == s) {
			listeClient.ValeurCourante().afficher();
		}
	}
}


void Usine::afficherClients()
{
	for (listeClient.FixerTete(); listeClient.EstDansListe(); listeClient.Suivant())
	{
		listeClient.ValeurCourante().afficher();
		cout << "--------------" << endl;
	}
}

bool Usine::checkClient(string s)
{
	for (listeClient.FixerTete(); listeClient.EstDansListe(); listeClient.Suivant())
	{
		if (listeClient.ValeurCourante().nom() == s) {
			return true;
		}
	}
	return false;
}

void Usine::ajouterCommandeToClient(string nomCli, const Commande& _commande)
{
	for (listeClient.FixerTete(); listeClient.EstDansListe(); listeClient.Suivant())
	{
		if (listeClient.ValeurCourante().nom() == nomCli) {
			listeClient.ValeurCourante().ajouterCommande(_commande);
		}
	}
}

void Usine::ajouterPaquet(Paquet& p)
{
	for (listePaquet.FixerTete(); listePaquet.EstDansListe(); listePaquet.Suivant())
	{
		if (listePaquet.ValeurCourante().getNom() == p.getNom()) {
			listePaquet.ValeurCourante().ajouterQt( p.getQt());
			return;
		}
	}
	//Sinon
	listePaquet.InsererQueue(p);
}

void Usine::afficherPaquetPopulaire()
{
	Paquet* ptrPopulaire = nullptr;
	int max = -1;
	for (listePaquet.FixerTete(); listePaquet.EstDansListe(); listePaquet.Suivant())
	{
		if (listePaquet.ValeurCourante().getQt() > max) {
			max = listePaquet.ValeurCourante().getQt();
			ptrPopulaire = &listePaquet.ValeurCourante();
		}
	}
	if (ptrPopulaire != nullptr) {
		cout << "Le biscuit le plus populaire est le " << ptrPopulaire->getNom() << " avec " << to_string(ptrPopulaire->getQt()) << " biscuits!!" << endl;
	}
	else {
		cout << "Il n'y a aucune commande ajoutée à l'usine" << endl;
	}
		
}

void Usine::supprimerClient(string nomCli)
{
	//Supprimer toutes les commandes associés
	supprimerCommandesAvecClient(nomCli);

	//Supprime le client
	for (listeClient.FixerTete(); listeClient.EstDansListe(); listeClient.Suivant())
	{
		if (listeClient.ValeurCourante().nom() == nomCli) {
			listeClient.Supprimer();
		}
	}
}

void Usine::supprimerCommandesAvecClient(string cli)
{
	for (listeClient.FixerTete(); listeClient.EstDansListe(); listeClient.Suivant())
	{
		listeClient.ValeurCourante().supprimerCommandes(cli);
	}
}
