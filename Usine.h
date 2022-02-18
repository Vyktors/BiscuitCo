#pragma once
#include <iostream>
#include <string>

#include "Liste.h"
#include "Paquet.h"
#include "Client.h"
#include "Commande.h"

using namespace std;

using namespace std;
class Usine {
private:
	Liste<Client> listeClient;
	Liste<Paquet> listePaquet;


public :
	Usine();	

	void ajouterClient(const Client& _client);
	void afficherClients();
	void afficherClient(string);
	bool checkClient(string);
	void ajouterCommandeToClient(string nomCli, const Commande&);
	void ajouterPaquet(Paquet&);
	void afficherPaquetPopulaire();
	void supprimerClient(string);
	void supprimerCommandesAvecClient(string);
};
