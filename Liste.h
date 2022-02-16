#pragma once
#include <iostream>
#include "Noeud.h"
using namespace std;

template<typename TElement>
class Liste {
public:
	Liste(); // Constructeur
	Liste<TElement> &operator=(const Liste<TElement>& copied);


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
	Noeud<TElement> * Tete; // position du premier élément
	Noeud<TElement> * Queue; // position du dernier élément
	Noeud<TElement> * Courant; // position de l'élément courant
};



// Constructeur
template<typename TElement> inline
Liste<TElement>::Liste()
{
	cout << "Creation Liste sans paramètre" << endl;
	Queue = Tete = Courant = new Noeud<TElement>(); // crée le Noeud entête
}


template<typename TElement> inline 
Liste<TElement>& Liste<TElement>::operator=(const Liste<TElement>& copied)
{

	cout << "Copie référence!!" << endl;
	Noeud<TElement>* courantTmp = copied.Tete;
	while (courantTmp->Suivant != nullptr) {
		this->InsererQueue(courantTmp->Suivant->info);
		courantTmp = courantTmp->Suivant;
	}
	

	return *this;
}

// Destructeur
template<typename TElement> inline
Liste<TElement>::~Liste()
{
	cout << "Destruction Liste" << endl;
	while (Tete != nullptr) {
		Courant = Tete;
		Tete = Tete->Suivant;
		delete Courant;
	}
}

// libère l'espace alloué aux Noeuds, garde l'entête.
template<typename TElement>
void Liste<TElement>::ViderListe()
{
	while (Tete->Suivant != nullptr) {
		Courant = Tete->Suivant;
		Tete->Suivant = Courant->Suivant;
		delete Courant;
	}
	Courant = Queue = Tete; // réinitialise
}

// Insère un élément à la position courante
template<typename TElement>
void Liste<TElement>::Inserer(const TElement& element)
{

	Courant->Suivant = new Noeud<TElement>(element, Courant->Suivant);
	if (Queue == Courant)
		Queue = Courant->Suivant; //l'élément est ajouté à la fin de la liste.
}

// supprime et retourne l'élément courant
template<typename TElement>
TElement Liste<TElement>::Supprimer()
{
	assert(EstDansListe());// Courant doit être une position valide sinon le programme se termine
	TElement temp = Courant->Suivant->element; //Sauvegarde de l'élément courant
	Noeud<TElement> * ptemp = Courant->Suivant; // Sauvegarde du pointeur du Noeud Courant
	Courant->Suivant = ptemp->Suivant; // suppression de l'élément
	if (Queue == ptemp)
		Queue = Courant; // C'est le dernier élément supprimé, mise à jour de Queue
	delete ptemp;
	return temp;
}

// insère en fin de liste
template<typename TElement>
void Liste<TElement>::InsererQueue(const TElement& _info)
{
	Queue = Queue->Suivant = new Noeud<TElement>(_info, nullptr);
}

// rend la tête comme position courante
template<typename TElement>
void Liste<TElement>::FixerTete() {
	Courant = Tete;
}

// met la position courante à la position précédente
template<typename TElement>
void Liste<TElement>::Precedent() {
	Noeud<TElement> * temp = Tete;
	if ((Courant == nullptr) || (Courant == Tete)) // pas d'élément précédent
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

// compte le nombre d'éléments
template<typename TElement>
int Liste<TElement>::Longueur() const {
	int cpt = 0;
	for (Noeud<TElement> * temp = Tete->Suivant; temp != nullptr; temp = temp->Suivant)
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
	if (EstDansListe()) {
		Courant->Suivant->info = valeur;
	}
}

template<typename TElement>
TElement Liste<TElement>::ValeurCourante() const {
	if (EstDansListe()) {
		return Courant->Suivant->info;
	}	
	
	return TElement();
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
bool Liste<TElement>::Trouver(const TElement& valeur) { // recherche la valeur à partir
											   // de la position courante
	while (EstDansListe())
		if (Courant->Suivant->info == valeur)
			return true;
		else
			Courant = Courant->Suivant;
	return false;
}

