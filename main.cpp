/*                 Présentation du Devoir 1                     */
/*--------------------------------------------------------------*/
/* Réalisé par :   Mathieu Victor Guérin                        */
/*                 Sophie Lalancette                            */
/* -------------------------------------------------------------*/
/* Date de remise : 18 mars 2022                                */
/*--------------------------------------------------------------*/
/* Objectif  : Dans ce code, il sera possible de lire des       */
/*             fichier textes. Une liste de clients et de       */
/*             commandes seront sauvegarder. Le programme va    */
/*             ensuite faire des modification au données en     */
/*             fonction des altercation demander. Pour finir le */
/*             va enregistré les modifications en les sortant en*/
/*             fichier texte.                                   */
/*--------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include "Liste.h"
#include "Client.h"
#include "Paquet.h"
#include "Commande.h"
#include "Usine.h"

using namespace std;


//Création des Types
const TypeBiscuit CHOCOLAT("Chocolat");
const TypeBiscuit MACADAM("Macadam");
const TypeBiscuit NOIX("Noix");

int main()
{

	//Liste de Paquet ça fonctionne à moitié! Le destucteur est appelé deux fois? 

	//Liste<Paquet> listeP;
	Paquet p1(CHOCOLAT, 20);
	//Paquet p2(MACADAM, 22);
	//listeP.InsererQueue(p1);
	//listeP.InsererQueue(p2);


	//Liste de Commande(Liste de liste), fonctionne pas :(
	Liste<Commande> listeCo;
	Commande co1;
	co1.ajouterPaquet(p1);
	listeCo.InsererQueue(co1);

	system("pause");

	return 0;
}

