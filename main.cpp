/*                 Présentation du Devoir 1                     */
/*--------------------------------------------------------------*/
/* Réalisé par :   Mathieu Victor Guérin                        */
/*                 Sophie Lalancette                            */
/* -------------------------------------------------------------*/
/* Date de remise : 18 mars 2022                                */
/*--------------------------------------------------------------*/
/* Objectif  : Dans ce code, il sera possible de lire des       */
/*             fichier textes. Une liste de clients et de       */
/*             commandes seront sauvegarder. Le programme va    */
/*             ensuite faire des modification au données en     */
/*             fonction des altercation demander. Pour finir le */
/*             va enregistré les modifications en les sortant en*/
/*             fichier texte.                                   */
/*--------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
void ouvrirClient(string _nomFichierClient);
void ouvrirCommande(string _nomFichierClient);
void enregistrer(string);
void enregistrerClient(string);
void enregistrerCommande(string);
void viderFichier(string nomFichier);

int main()
{
	setlocale(LC_CTYPE, "Fr-FR");

	cout << "Bienvenue a l'usine de Biscuit! " << endl;
	while (true) {
		cout << "Voulez vous entrer des transactions " << endl;
		cout << setw(10) << "A  "  << "MANUEL" <<  endl;
		cout << setw(10) << "B  "  << "À PARTIR D'UN FICHIER" <<  endl;
		string choix, instruction;
		cout << "Choix (A ou B) : ";
		getline(cin, choix);

		if (choix == "A") {
			while (true) {
				cout << "Entrez une operation : ";
				getline(cin, instruction);
				if (instruction == "Q" || instruction == "exit") {
					break;
				}
				gereChoix(instruction);
				cout << endl;
			}
		}
		else if (choix == "B") {
			string NomFichier;
			ifstream FicEntree;

			while (true) {
				cout << "Entrez un fichier opération: ";
				getline(cin, NomFichier);
				if (NomFichier == "Q" || NomFichier == "exit") {
					break;
				}
				FicEntree.open(NomFichier, ios::in);
				if (!FicEntree)
				{
					cout << "Erreur de lecture du fichier des operation";
					FicEntree.close();
				}
				else
				{
					while (!FicEntree.eof())
					{
						getline(FicEntree, instruction);
						gereChoix(instruction);
						cout << endl;
					}
					FicEntree.close();
				}
			}
		}
		else {
			cout << "Choisissez entre A et B!";
		}
	}

	system("pause");

	return 0;
}

// Action que le programme doit faire en fonction des actions du fichier texte des opérations
void gereChoix(string s)
{
	char operation = s.substr(0, s.find(" "))[0];
	s.erase(0, 2);
	switch (operation)
	{
	case '+': //Ajouter un client C habitant a l'adresse A et au numero N
		ajouterClient(s);
		break;
	case '-'://Supprimer un client X ainsi que toutes ses commandes associees de la liste
		usine.supprimerClient(s);
		break;
	case '='://Ajouter une commande du client X au client Y suivie des types B de biscuits et de leur quantite X, & indique la fin de la commande
		ajouterCommande(s);
		break;
	case '?'://Afficher les commandes faites par un client X
		afficherCommande(s);
		break;
	case '$'://Afficher le type de biscuit le plus populaire et le montant total reçu pour ce dernier
		usine.afficherPaquetPopulaire();
		break;
	case 'O'://ouvre et charge les fichiers ""CLIENTS"" et ""COMMANDES"
		ouvrir(s);
		break;
	case 'S'://enregistre dans les fichiers ""CLIENTS"" et "" COMMANDES"
		enregistrer(s);
		break;
	case 'X'://Afficher tous les clients
		usine.afficherClients();
		break;
	case 'H'://Lit fichier de transactions
		cout << "• - X : Supprimer un client X ainsi que toutes ses commandes associées de la liste." << endl;
		cout << " + C N A : Ajouter un client C habitant à l'adresse A et au numéro N à la liste chaînée." << endl;
		cout << " = X Y B1 X1[...] BN XN & : Ajouter une commande du client X au client Y suivie des types B" << endl;
		cout << "    de biscuits et de leur quantité X. '&' indique la fin de la commande." << endl;
		cout << " ? X : Afficher les commandes faites par un client X." << endl;
		cout << " $ : Afficher le type de biscuit le plus populaire et le montant total reçu pour ce dernier." << endl;
		cout << " O CLIENTS COMMANDES : ouvre et charge les fichiers 'CLIENTS' et 'COMMANDES'." << endl;
		cout << " S CLIENTS COMMANDES : enregistre dans les fichiers 'CLIENTS' et 'COMMANDES'." << endl;
		cout << " X : Affiche TOUS les clients et leurs commandes" << endl;
		cout << " H : Affiche les transactions disponibles et leur détails" << endl;

		break;
	default:
		cout << "Ceci n'est pas une commande, voir commande 'H' (help) pour plus d'information" << endl;
		break;
	}
}
//Fonction qui vérifie si le client existe dans la liste et s'il n'existe pas ajout de celui-ci
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
	if (usine.checkClient(nom)) {
		cout << "Client deja present" << endl;
	}
	else {
		usine.ajouterClient(Client(nom, no, addr));
		cout << nom << " ajoute(e) a la liste de client!" << endl;
	}
	
}

// Fonction qui ajoute une commande passer par un client qui existe dans la liste
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

// Fonction qui affiche un client de la liste
void afficherCommande(string s) {
	
	usine.afficherClient(s);

}

// Ouverture des fichiers textes et lectures de ceux-ci
void ouvrir(string s) {
	size_t pos = 0;
	string token, nomFichierClient ="", nomFichierCommande = "";
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

	ouvrirClient(nomFichierClient);
	ouvrirCommande(nomFichierCommande);
}

void ouvrirClient(string _nomFichierClient) {
	ifstream entree;
	entree.open(_nomFichierClient, ios::in);
	if (entree)
	{
		string op = "", s;
		int mod = 0;
		
		while (!entree.eof()) {
			
			entree >> s;
			if (mod % 3 == 0) {
				op = s;
			}
			else {
				op = op + " " + s;
			}
			
			if (mod % 3 == 2) {
				ajouterClient(op);
			}
			mod++;
		}
	}
	else {
		cout << "pas trouver de fichier avec ce nom " << _nomFichierClient << endl;
	}
	entree.close();
}


void ouvrirCommande(string _nomFichierCommande) {
	ifstream entree;
	entree.open(_nomFichierCommande, ios::in);
	if (entree)
	{
		string op = "", s;
		bool first = true;

		while (!entree.eof()) {
			entree >> s; 
			if (s == "&") { //Termine une commande
				op = op + " " + s;
				ajouterCommande(op);
				first = true;
			}
			else {
				if (first) {
					op = s;
					first = false;
				}
				else {
					op = op + " " + s;
				}
			}
		}
	}
	else {
		cout << "pas trouver de fichier avec ce nom " << _nomFichierCommande << endl;
	}
}

void enregistrer(string s) {
	size_t pos = 0;
	string token, nomFichierClient = "", nomFichierCommande = "";
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

	enregistrerClient(nomFichierClient);
	enregistrerCommande(nomFichierCommande);
}

void enregistrerClient(string _nomFichierClient) {
	viderFichier(_nomFichierClient);

	ofstream sortie;
	sortie.open(_nomFichierClient, ios::out);
	if (sortie) {
		//Imprimer client
		Liste<Client> listeClients = usine.getClients();
		for (listeClients.FixerTete(); listeClients.EstDansListe(); listeClients.Suivant())
		{
			sortie << listeClients.ValeurCourante().getNom() << endl;
			sortie << listeClients.ValeurCourante().getNo() << endl;
			sortie << listeClients.ValeurCourante().getAdresse() << endl;	
		}

	}
	else {
		cout << "pas trouver de fichier avec ce nom " << _nomFichierClient << endl;
	}
		sortie.close();

}

void enregistrerCommande(string _nomFichierCommande) {
	viderFichier(_nomFichierCommande);

	ofstream sortie;
	sortie.open(_nomFichierCommande, ios::out);
	if (sortie) {
		//Imprimer client
		Liste<Client> listeClients = usine.getClients();
		for (listeClients.FixerTete(); listeClients.EstDansListe(); listeClients.Suivant())
		{
			//Chaque CLient
			Liste<Commande> listeCommandeClient = listeClients.ValeurCourante().getCommandes();

			for (listeCommandeClient.FixerTete(); listeCommandeClient.EstDansListe(); listeCommandeClient.Suivant())
			{
				//Chaque Commande
				sortie << listeCommandeClient.ValeurCourante().getCliSource() << endl;
				sortie << listeCommandeClient.ValeurCourante().getCliDest() << endl;
				
				Liste<Paquet> listePaquets = listeCommandeClient.ValeurCourante().getPaquets();

				for (listePaquets.FixerTete(); listePaquets.EstDansListe(); listePaquets.Suivant())
				{
					sortie << listePaquets.ValeurCourante().getNom() << " ";
					sortie << listePaquets.ValeurCourante().getQt() << endl;
				}
				sortie << "&" << endl;
			}
			
		}

	}
	else {
		cout << "pas trouver de fichier avec ce nom " << _nomFichierCommande << endl;
	}
	sortie.close();


}

void viderFichier(string nomFichier) {
	std::ofstream ofs;
	ofs.open("nomFichier", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}