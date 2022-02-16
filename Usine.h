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
	Liste<Commande> listeCommande;
public :
	Usine();	

	void ajouterClient(Client _client);

};
