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
<<<<<<< HEAD
	Usine();	

	void ajouterClient(Client _client);
=======
	Usine();
	Liste<Client> listeClient = Liste<Client>();
	Liste<Commande> listeCommande = Liste<Commande>();
private:
	
>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
};
