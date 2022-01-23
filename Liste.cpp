#include <cassert>
#include "Liste.h"

// Constructeur
template<typename TElement> Liste<TElement>::Liste()
{ 
	Queue = Tete = Courant = new noeud; // crée le noeud entête
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

// libère l'espace alloué aux noeuds, garde l'entête.
template<typename TElement> void Liste<TElement>::ViderListe()
{
	while (Tete->Suivant != nullptr) {
		Courant = Tete->Suivant;
		Tete->Suivant = Courant->Suivant;
		delete Courant;
	}
	Courant = Queue = Tete; // réinitialise
}

// Insère un élément à la position courante
template<typename TElement> void Liste<TElement>::Inserer(const TElement & element)
{
	assert(Courant != nullptr);// s'assure que Courant pointe vers un noeud

	Courant->Suivant = new noeud(element, Courant->Suivant);
	if (Queue == Courant)
		Queue = Courant->Suivant; //l'élément est ajouté à la fin de la liste.
}

// supprime et retourne l'élément courant
template<typename TElement> TElement Liste<TElement>::Supprimer()
{ 
	assert(EstDansListe());// Courant doit être une position valide sinon le programme se termine
	TElement temp = Courant->Suivant->element; //Sauvegarde de l'élément courant
	noeud * ptemp = Courant->Suivant; // Sauvegarde du pointeur du noeud Courant
	Courant->Suivant = ptemp->Suivant; // suppression de l'élément
	if (Queue == ptemp)
		Queue = Courant; // C'est le dernier élément supprimé, mise à jour de Queue
	delete ptemp;
	return temp;
}

// insère en fin de liste
template<typename TElement> void Liste<TElement>::InsererQueue(const TElement & element)
{ 
	Queue = Queue->Suivant = new noeud(element, nullptr);
}

// rend la tête comme position courante
template<typename TElement> void Liste<TElement>::FixerTete() {
	Courant = Tete;
}

// met la position courante à la position précédente
template<typename TElement> void Liste<TElement>::Precedent() {
	noeud * temp = Tete;
	if ((Courant == nullptr) || (Courant == Tete)) // pas d'élément précédent
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

// compte le nombre d'éléments
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

template<typename TElement> bool Liste<TElement>::Trouver(const TElement & valeur) { // recherche la valeur à partir
											   // de la position courante
	while (EstDansListe())
		if (Courant->Suivant->element == valeur)
			return true;
		else
			Courant = Courant->Suivant;
	return false;
}