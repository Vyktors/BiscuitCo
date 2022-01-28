#include "Client.h"
#include <iostream>

using namespace std;

Client::Client()
{
	nom_client = "";
	numero = 0;
	rue = "";
	listeCommande = new Liste<Commande>();
}

Client::Client(string _nom_client, int _numero, string _rue)
{
	nom_client = _nom_client;
	numero = _numero;
	rue = _rue;
	listeCommande = new Liste<Commande>();
}

Client::~Client()
{
	//delete listeCommande;
}

void Client::ajouterCommande(Commande& _commande)
{
	listeCommande->InsererQueue(_commande);
}

void Client::afficher()
{
	cout << "Afficher le client : " << endl;
	cout << "Nom : " << nom_client << endl;
	cout << "Adresse : " << numero << " rue " << rue << endl;
	cout << "Liste de commandes :" << endl;
	for (listeCommande->FixerTete(); listeCommande->EstDansListe(); listeCommande->Suivant())
	{
		listeCommande->ValeurCourante().afficher();
		cout << "--------------" << endl;
	}
}

string Client::nom()
{
	return nom_client;
}
