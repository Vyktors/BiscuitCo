#pragma once


template<typename TElement>
class noeud {
public:
	TElement element;
	noeud<TElement>* Suivant;
	noeud(const TElement& info, noeud* suiv = nullptr) { // constructeur1
		element = info;
		Suivant = suiv;
	}
	noeud(noeud* suiv = nullptr) { // constructeur 2
		Suivant = suiv;
	}
	~noeud() {
	}
}; // fin de la déclaration
