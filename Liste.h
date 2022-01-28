#pragma once
#include <cassert>

#include "Noeud.h"


template<typename TElement>
class Liste {
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



// Constructeur
template<typename TElement> inline
Liste<TElement>::Liste()
{
	Queue = Tete = Courant = new noeud<TElement>(); // cr�e le noeud ent�te
}

// Destructeur
template<typename TElement> inline
Liste<TElement>::~Liste()
{
	while (Tete != nullptr) {
		Courant = Tete;
		Tete = Tete->Suivant;
		delete Courant;
	}
}

// lib�re l'espace allou� aux noeuds, garde l'ent�te.
template<typename TElement>
void Liste<TElement>::ViderListe()
{
	while (Tete->Suivant != nullptr) {
		Courant = Tete->Suivant;
		Tete->Suivant = Courant->Suivant;
		delete Courant;
	}
	Courant = Queue = Tete; // r�initialise
}

// Ins�re un �l�ment � la position courante
template<typename TElement>
void Liste<TElement>::Inserer(const TElement& element)
{
	assert(Courant != nullptr);// s'assure que Courant pointe vers un noeud

	Courant->Suivant = new noeud<TElement>(element, Courant->Suivant);
	if (Queue == Courant)
		Queue = Courant->Suivant; //l'�l�ment est ajout� � la fin de la liste.
}

// supprime et retourne l'�l�ment courant
template<typename TElement>
TElement Liste<TElement>::Supprimer()
{
	assert(EstDansListe());// Courant doit �tre une position valide sinon le programme se termine
	TElement temp = Courant->Suivant->element; //Sauvegarde de l'�l�ment courant
	noeud<TElement> * ptemp = Courant->Suivant; // Sauvegarde du pointeur du noeud Courant
	Courant->Suivant = ptemp->Suivant; // suppression de l'�l�ment
	if (Queue == ptemp)
		Queue = Courant; // C'est le dernier �l�ment supprim�, mise � jour de Queue
	delete ptemp;
	return temp;
}

// ins�re en fin de liste
template<typename TElement>
void Liste<TElement>::InsererQueue(const TElement& element)
{
	Queue = Queue->Suivant = new noeud<TElement>(element, nullptr);
}

// rend la t�te comme position courante
template<typename TElement>
void Liste<TElement>::FixerTete() {
	Courant = Tete;
}

// met la position courante � la position pr�c�dente
template<typename TElement>
void Liste<TElement>::Precedent() {
	noeud<TElement> * temp = Tete;
	if ((Courant == nullptr) || (Courant == Tete)) // pas d'�l�ment pr�c�dent
	{
		Courant = nullptr;
		return;
	}
	while ((temp != nullptr) && (temp->Suivant != Courant))
		temp = temp->Suivant;
	Courant = temp;
}

template<typename TElement>
void Liste<TElement>::Suivant() {
	if (Courant != nullptr)
		Courant = Courant->Suivant;
}

// compte le nombre d'�l�ments
template<typename TElement>
int Liste<TElement>::Longueur() const {
	int cpt = 0;
	for (noeud<TElement> * temp = Tete->Suivant; temp != nullptr; temp = temp->Suivant)
		cpt++;
	return cpt;
}

template<typename TElement>
void Liste<TElement>::FixerPosition(const int pos) {
	Courant = Tete;
	for (int i = 0; (Courant != nullptr) && (i < pos); i++)
		Courant = Courant->Suivant;
}

template<typename TElement>
void Liste<TElement>::FixerValeur(const TElement& valeur) {
	assert(EstDansListe());
	Courant->Suivant->element = valeur;
	return;
}

template<typename TElement>
TElement Liste<TElement>::ValeurCourante() const {
	assert(EstDansListe());
	return Courant->Suivant->element;
}

template<typename TElement>
bool Liste<TElement>::EstDansListe() const {
	return (Courant != nullptr) && (Courant->Suivant != nullptr);
}

template<typename TElement>
bool Liste<TElement>::ListeVide() {
	return Tete->Suivant == nullptr;
}

template<typename TElement>
bool Liste<TElement>::Trouver(const TElement& valeur) { // recherche la valeur � partir
											   // de la position courante
	while (EstDansListe())
		if (Courant->Suivant->element == valeur)
			return true;
		else
			Courant = Courant->Suivant;
	return false;
}

