#pragma once
#include <iostream>
#include <string>
#include <stream>
#include <Client.h>
#include <Commande.h>
using namespace std;

void EnregistreFichier()
{	string const FichEcriture(CLIENT);
	ofstream Enregistrement(FichEcriture.c_str(CLIENT));

	if (Enregistrement.fail())
	{
		cout << ">>>> Erreur d\'enregistrement du ficher \n" << endl;
	}
	else
	{
		for (int i = 0; i <= Client; i++)
			Enregistrement << Client;

	}

	{	string const FichEcriture(COMMANDE);
	ofstream Enregistrement(FichEcriture.c_str(COMMANDE));

	if (Enregistrement.fail())
	{
		cout << ">>>> Erreur d\'enregistrement du ficher \n" << endl;
	}
	else
	{
		for (int i = 0; i <= Commande; i++)
			Enregistrement << Commande;

	}
	cout << endl;
	cout << setw(50) << "****** FICHER ENREGISTRE ******\n" << endl;
	cout << endl;
	cout << endl;
}

