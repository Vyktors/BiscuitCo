#pragma once
#include <iostream>
#include <string>

#include "TypeBiscuit.h"

using namespace std;

class Paquet {
	private :
		TypeBiscuit biscuit;
		int quantite;
	public : 
		Paquet();
		Paquet(const TypeBiscuit& _biscuit, int _quantite);
		~Paquet();

		string afficher();
};
