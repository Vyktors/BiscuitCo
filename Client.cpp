#include "Client.h"
#include <iostream>

using namespace std;

Client::Client()
{
	nom_client = "";
	numero = 0;
	rue = "";
}

Client::Client(string _nom_client, int _numero, string _rue)
{
	nom_client = _nom_client;
	numero = _numero;
	rue = _rue;
}

Client::~Client()
{

}

void Client::ajouterCommande(const Commande& _commande)
{
	listeCommande.InsererQueue(_commande);
}

void Client::afficher()
{
	cout << "Afficher le client : " << endl;
	cout << "Nom : " << nom_client << endl;
	cout << "Adresse : " << numero << " rue " << rue << endl;
	cout << "Liste de commandes :" << endl;
	cout << "--------------" << endl;
	for (listeCommande.FixerTete(); listeCommande.EstDansListe(); listeCommande.Suivant())
	{
		listeCommande.ValeurCourante().afficher();
		cout << "--------------" << endl;
	}
}

Liste<Commande> Client::supprimerCommandes(string cli)
{
	Liste<Commande> listeCoSupprime;
	for (listeCommande.FixerTete(); listeCommande.EstDansListe(); listeCommande.Suivant())
	{
		if (listeCommande.ValeurCourante().getCliSource() == cli  || listeCommande.ValeurCourante().getCliDest() == cli) {
			listeCoSupprime.InsererQueue(listeCommande.Supprimer());
		}
	}
	return listeCoSupprime;
}

int Client::getNo()
{
	return numero;
}

string Client::getAdresse()
{
	return rue;
}

Liste<Commande>& Client::getCommandes()
{
	return listeCommande;
}

void Client::metAJourQtTotal(Liste<Paquet>& listeP)
{
	for (listeCommande.FixerTete(); listeCommande.EstDansListe(); listeCommande.Suivant())
	{
		listeCommande.ValeurCourante().metAJourQtTotal(listeP);
		
	}

}

string Client::getNom()
{
	return nom_client;
}




