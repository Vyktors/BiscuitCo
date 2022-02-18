#include <iostream>
#include <fstream>
#include <string>
#include "Liste.h"
#include "Client.h"
#include "Paquet.h"
#include "Commande.h"
#include "Usine.h"

using namespace std;

Usine usine;

void gereChoix(string);
void ajouterClient(string);
void ajouterCommande(string);
void afficherCommande(string);
void ouvrir(string);
void enregistrer(string);

int main()
{
	cout << "Bienvenue a l'usine de Biscuit! " << endl;
	string instruction;
	while (true) {
		cout << "Entrez une operation : ";
		getline(cin, instruction);
		gereChoix(instruction);
	}
	system("pause");

	return 0;
}

void gereChoix(string s)
{
	char operation = s.substr(0, s.find(" "))[0];
	s.erase(0, 2);
	switch (operation)
	{
	case '+':
		cout << "Ajouter un client C habitant a l'adresse A et au numero N" << endl;
		cout << "--------------" << endl;
		ajouterClient(s);
		break;
	case '-':
		cout << "Supprimer un client X ainsi que toutes ses commandes associees de la liste" << endl;
		cout << "--------------" << endl;
		usine.supprimerClient(s);
		break;
	case '=':
		cout << "Ajouter une commande du client X au client Y suivie des types B de biscuits et de leur quantite X, & indique la fin de la commande" << endl;
		cout << "--------------" << endl;
		ajouterCommande(s);
		break;
	case '?':
		cout << "Afficher les commandes faites par un client X" << endl;
		cout << "--------------" << endl;
		afficherCommande(s);
		break;
	case '$':
		cout << "Afficher le type de biscuit le plus populaire et le montant total reçu pour ce dernier" << endl;
		cout << "--------------" << endl;
		usine.afficherPaquetPopulaire();
		break;
	case 'O':
		cout << "ouvre et charge les fichiers ""CLIENTS"" et ""COMMANDES""" << endl;
		cout << "--------------" << endl;
		ouvrir(s);
		break;
	case 'S':
		cout << "enregistre dans les fichiers ""CLIENTS"" et "" COMMANDES""" << endl;
		cout << "--------------" << endl;
		break;
	case 'X':
		cout << "Afficher tous les clients" << endl;
		cout << "--------------" << endl;
		usine.afficherClients();
		break;
	default:
		break;
	}
}

void ajouterClient(string s) {
	size_t pos = 0;
	string token, nom, addr;
	int no;
	for (size_t i = 0; i < 3; i++)
	{
		pos = s.find(" ");
		token = s.substr(0, pos);

		switch (i)
		{
		case 0:
			nom = token;
			break;
		case 1:
			try {
				no = stoi(token);
			}
			catch(...) {
				cout << "Mauvaise entree de numero" << endl;
				exit(0);
			}	
			break;
		case 2:
			addr = token;
			break;
		default:
			break;
		}
		s.erase(0, pos + 1);		
	}
	usine.ajouterClient(Client(nom, no, addr));
}

void ajouterCommande(string s) {
	
	size_t pos = 0;
	string token, cliS, cliD;
	for (size_t i = 0; i < 2; i++)
	{
		pos = s.find(" ");
		token = s.substr(0, pos);

		switch (i)
		{
		case 0:
			cliS = token;
			break;
		case 1:
			cliD = token;
			break;
		default:
			break;
		}
		s.erase(0, pos + 1);
	}
	if (usine.checkClient(cliS) && usine.checkClient(cliD)) {
		Commande commande(cliS, cliD);
		int mod = 0;
		string biscuit;
 		while (token != "&") {
			pos = s.find(" ");
			token = s.substr(0, pos);
			//Type biscuit
			if (mod % 2 == 0)
			{
				biscuit = token;
			}
			//Quantité
			else {
				Paquet paquetTemp(biscuit, stoi(token));
				commande.ajouterPaquet(paquetTemp);
				usine.ajouterPaquet(paquetTemp);
			}
			mod++;
			s.erase(0, pos + 1);
		}

		usine.ajouterCommandeToClient(cliS, commande);
	}
	else {
		cout << "Pas de client a ce/ces Nom" << endl;
	}
	
}

void afficherCommande(string s) {
	
	usine.afficherClient(s);

}

void ouvrir(string s) {
	size_t pos = 0;
	string token, nomFichierClient, nomFichierCommande;
	int no;
	for (size_t i = 0; i < 2; i++)
	{
		pos = s.find(" ");
		token = s.substr(0, pos);

		switch (i)
		{
		case 0:
			nomFichierClient = token;
			break;
		case 1:
			nomFichierCommande = token;
			break;
		default:
			break;
		}
		s.erase(0, pos + 1);
	}



}
