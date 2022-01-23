
#include <iostream>
#include "Liste.h"

using namespace std;

void afficherListe(Liste<int>& liste)
{
	for (liste.FixerTete(); liste.EstDansListe(); liste.Suivant())
	{
		cout << liste.ValeurCourante() << " ";
	}
	cout << endl;
}

int main()
{
	Liste<int> liste;

	//ajouter des élément à la fin de la liste
	cout << " ajouter elements ";
	for (int i = 0; i < 10; ++i)
	{
		liste.InsererQueue(i);
		cout << liste.ValeurCourante() << " ";
	}
	cout << endl;

	// affichage du premier au dernier element
	cout << " afficher elements ";
	afficherListe(liste);

	// supprimer deux elements au milieu de la liste  
	cout << " supprimer deux elements : ";
	liste.FixerPosition(5);
	cout << liste.Supprimer() << "," << liste.Supprimer() << " " << endl;
	cout << " afficher apres suppression ";
	afficherListe(liste);

	// affichage liste vide
	liste.ViderListe();
	cout << " afficher liste vide ";
	afficherListe(liste);

	system("pause");
	return 0;
}