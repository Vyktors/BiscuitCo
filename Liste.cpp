#include <cassert>
#include "Liste.h"

// Constructeur
template<typename TElement> Liste<TElement>::Liste()
{ 
	Queue = Tete = Courant = new noeud; // cr�e le noeud ent�te
}

// Destructeur
template<typename TElement> Liste<TElement>::~Liste()
{ 
	while (Tete != nullptr) {
		Courant = Tete;
		Tete = Tete->Suivant;
		delete Courant;
	}
}

// lib�re l'espace allou� aux noeuds, garde l'ent�te.
template<typename TElement> void Liste<TElement>::ViderListe()
{
	while (Tete->Suivant != nullptr) {
		Courant = Tete->Suivant;
		Tete->Suivant = Courant->Suivant;
		delete Courant;
	}
	Courant = Queue = Tete; // r�initialise
}

// Ins�re un �l�ment � la position courante
template<typename TElement> void Liste<TElement>::Inserer(const TElement & element)
{
	assert(Courant != nullptr);// s'assure que Courant pointe vers un noeud

	Courant->Suivant = new noeud(element, Courant->Suivant);
	if (Queue == Courant)
		Queue = Courant->Suivant; //l'�l�ment est ajout� � la fin de la liste.
}

// supprime et retourne l'�l�ment courant
template<typename TElement> TElement Liste<TElement>::Supprimer()
{ 
	assert(EstDansListe());// Courant doit �tre une position valide sinon le programme se termine
	TElement temp = Courant->Suivant->element; //Sauvegarde de l'�l�ment courant
	noeud * ptemp = Courant->Suivant; // Sauvegarde du pointeur du noeud Courant
	Courant->Suivant = ptemp->Suivant; // suppression de l'�l�ment
	if (Queue == ptemp)
		Queue = Courant; // C'est le dernier �l�ment supprim�, mise � jour de Queue
	delete ptemp;
	return temp;
}

// ins�re en fin de liste
template<typename TElement> void Liste<TElement>::InsererQueue(const TElement & element)
{ 
	Queue = Queue->Suivant = new noeud(element, nullptr);
}

// rend la t�te comme position courante
template<typename TElement> void Liste<TElement>::FixerTete() {
	Courant = Tete;
}

// met la position courante � la position pr�c�dente
template<typename TElement> void Liste<TElement>::Precedent() {
	noeud * temp = Tete;
	if ((Courant == nullptr) || (Courant == Tete)) // pas d'�l�ment pr�c�dent
	{
		Courant = nullptr;
		return;
	}
	while ((temp != nullptr) && (temp->Suivant != Courant))
		temp = temp->Suivant;
	Courant = temp;
}

template<typename TElement> void Liste<TElement>::Suivant() {
	if (Courant != nullptr)
		Courant = Courant->Suivant;
}

// compte le nombre d'�l�ments
template<typename TElement> int Liste<TElement>::Longueur() const {
	int cpt = 0;
	for (noeud * temp = Tete->Suivant; temp != nullptr; temp = temp->Suivant)
		cpt++; 
	return cpt;
}

template<typename TElement> void Liste<TElement>::FixerPosition(const int pos) {
	Courant = Tete;
	for (int i = 0; (Courant != nullptr) && (i < pos); i++)
		Courant = Courant->Suivant;
}

template<typename TElement> void Liste<TElement>::FixerValeur(const TElement & valeur) {
	assert(EstDansListe());
	Courant->Suivant->element = valeur;
	return;
}

template<typename TElement> TElement Liste<TElement>::ValeurCourante() const {
	assert(EstDansListe());
	return Courant->Suivant->element;
}

template<typename TElement> bool Liste<TElement>::EstDansListe() const {
	return (Courant != nullptr) && (Courant->Suivant != nullptr);
}

template<typename TElement> bool Liste<TElement>::ListeVide() {
	return Tete->Suivant == nullptr;
}

template<typename TElement> bool Liste<TElement>::Trouver(const TElement & valeur) { // recherche la valeur � partir
											   // de la position courante
	while (EstDansListe())
		if (Courant->Suivant->element == valeur)
			return true;
		else
			Courant = Courant->Suivant;
	return false;
}