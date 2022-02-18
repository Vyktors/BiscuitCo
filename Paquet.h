#pragma once
#include <iostream>
#include <string>

using namespace std;

class Paquet {
private:
	string biscuit;
	int quantite;

public:
	

	Paquet();
	Paquet(string _biscuit, int _quantite);
	~Paquet();

	void afficher();
	void setQt(int nbr);
	void ajouterQt(int nbr);
	int getQt();
	string getNom();
};