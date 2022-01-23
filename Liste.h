#pragma once

#include "Noeud.h"

template<typename TElement> class Liste {
public:
	Liste(); // Constructeur
	~Liste(); // Destructeur
	void ViderListe(); // Vide la liste
	void Inserer(const TElement&); // ins�re un �l�ment � la position courante
	void InsererQueue(const TElement&); // ins�re un �l�ment � la fin de la liste
	TElement Supprimer(); // Supprime et retourne l'�l�ment � la position courante
	void FixerTete(); // met la position courante � la t�te de la liste
	void Precedent(); // D�place la position courante � la position pr�c�dente
	void Suivant(); // D�place la position courante � la position suivante
	int Longueur() const; // retourne la longueur courante de la liste
	void FixerPosition(const int); // met position courante � position donn�e
	void FixerValeur(const TElement&); // met � jour la valeur � la position courante
	TElement ValeurCourante() const;//retourne la valeur d'�l�ment � la position courante.
	bool ListeVide(); // retourne vrai si la liste est vide
	bool EstDansListe() const; // retourne vrai si position courante est dans la liste
	bool Trouver(const TElement&);// recherche une valeurs dans la
								   // liste � partir de la position courante.
private:
	noeud<TElement> * Tete; // position du premier �l�ment
	noeud<TElement> * Queue; // position du dernier �l�ment
	noeud<TElement> * Courant; // position de l'�l�ment courant
};
