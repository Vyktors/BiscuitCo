#pragma once


template<typename TElement>
class noeud {
public:
	TElement element;
	noeud<TElement> * Suivant;
	noeud(const TElement& info, noeud<TElement> * suiv = nullptr);
	noeud(noeud<TElement> *  suiv = nullptr);
	~noeud();
}; 

template<typename TElement> inline
noeud<TElement>::noeud(const TElement& info, noeud<TElement> * suiv) { 
	element = info;
	Suivant = suiv;
}

template<typename TElement> inline
noeud<TElement>::noeud(noeud<TElement> * suiv ) { 
	Suivant = suiv;
}

template<typename TElement> inline
noeud<TElement>::~noeud() {
}
