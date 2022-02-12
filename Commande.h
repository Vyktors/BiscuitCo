#pragma once
#include <iostream>
#include <string>

#include "Paquet.h"
#include "Liste.h"

using namespace std;

class Commande {
	private :
		string client_source;
		string client_destinataire;
		Liste<Paquet> listePaquet;
	public :
		Commande();
		Commande(string _client_source, string _client_destinataire);
		~Commande();

		void ajouterPaquet(Paquet& _paquet);
		void afficher();
};
