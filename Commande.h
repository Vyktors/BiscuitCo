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
	Liste < Paquet > listepaquet;


};
