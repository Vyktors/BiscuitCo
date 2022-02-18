#pragma once
#include <iostream>
#include <string>

#include "Liste.h"
#include "Commande.h"

using namespace std;


 class Client {
	private :
		string nom_client;
		int numero;
		string rue;
		Liste<Commande> listeCommande;

	public:
		Client();
		Client(string _nom_client, int _numero, string _rue);
		~Client();

		void ajouterCommande(const Commande& _commande);
		void afficher();
		Liste<Commande> supprimerCommandes(string);
		string getNom();
		int getNo();
		string getAdresse();
		Liste<Commande>& getCommandes();
		void metAJourQtTotal(Liste<Paquet>&);
};