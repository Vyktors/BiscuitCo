#pragma once

#include "Noeud.h"

template<typename TElement> class Liste {
public:
	Liste(); // Constructeur
	~Liste(); // Destructeur
	void ViderListe(); // Vide la liste
	void Inserer(const TElement&); // insère un élément à la position courante
	void InsererQueue(const TElement&); // insère un élément à la fin de la liste
	TElement Supprimer(); // Supprime et retourne l'élément à la position courante
	void FixerTete(); // met la position courante à la tête de la liste
	void Precedent(); // Déplace la position courante à la position précédente
	void Suivant(); // Déplace la position courante à la position suivante
	int Longueur() const; // retourne la longueur courante de la liste
	void FixerPosition(const int); // met position courante à position donnée
	void FixerValeur(const TElement&); // met à jour la valeur à la position courante
	TElement ValeurCourante() const;//retourne la valeur d'élément à la position courante.
	bool ListeVide(); // retourne vrai si la liste est vide
	bool EstDansListe() const; // retourne vrai si position courante est dans la liste
	bool Trouver(const TElement&);// recherche une valeurs dans la
								   // liste à partir de la position courante.
private:
	noeud<TElement> * Tete; // position du premier élément
	noeud<TElement> * Queue; // position du dernier élément
	noeud<TElement> * Courant; // position de l'élément courant
};
