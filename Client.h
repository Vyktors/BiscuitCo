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

		void ajouterCommande(Commande& _commande);
		void afficher();
		string nom();
};