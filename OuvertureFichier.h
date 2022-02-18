#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Client.h"
#include "Commande.h"

using namespace std;

void LectureFichier()
{
	ifstream FicEntree;
	string NomFichier;

	cout << "Nom du fichier ? ";
	cin >> NomFichier;

	switch (NomFichier)
	{
		case 'CLIENTS' : 	
			FicEntree.open(NomFichier.c_str());
			if (!FicEntree.fail())
			{
				FicEntree >> Client;
				FicEntree.close();
			}
			else 
			{
				cout << "Erreur à l\'ouverture du fichier !!" << endl;
				FicEntree.close();
			}
		break;
		case 'COOMANDES' :
			FicEntree.open(NomFichier.c_str());
			if (!FicEntree.fail())
			{
				FicEntree >> Commande;
				FicEntree.close();
			}
			else
			{
				cout << "Erreur à l\'ouverture du fichier !!" << endl;
				FicEntree.close();
			}
			break;


	}

}
