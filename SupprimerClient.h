#pragma once
#include <iostream>
#include <Client.h>

using namespace std;

SupprimerClient(string Name)
{
	Client c_retirer;
	Client* courant;
	Client* prec;

	bool trouver;

	Name = c_retirer;

	while (courant != 0) && (!trouver)
	{
		if (courant->nom_client == c_retirer)
		{
			trouver = true;
		}
		else
		{
			trouver = false;
		}
	
		if (!trouver)
		{
		prec = courant;
		courant = courant->suivant;
		}
	}
		if (prec == 0)

			tete = tete->suivant;
		else
		{
			prec->suivant = courant->suivant;

			delete courant;
			courant = 0;
		}

}
