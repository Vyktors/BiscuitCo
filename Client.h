#pragma once
#include <iostream>
#include <string>
#include "Commande.h"
#include "Liste.h"

using namespace std;


 class Client {
 private :
	 string nom_client;
	int numero;
	string rue;
	Liste < Commande >listecommande;

};