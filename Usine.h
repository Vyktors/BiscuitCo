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
public :
	Usine();
	Liste<Client> listeClient = Liste<Client>();
	Liste<Commande> listeCommande = Liste<Commande>();
private:
	
};
