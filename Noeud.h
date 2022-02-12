#pragma once


template<typename TType>

class Noeud {
public:
	TType info;
	Noeud<TType>* Suivant;

	Noeud();
	Noeud(const TType& _info, Noeud<TType>* suiv = nullptr);
	Noeud(Noeud<TType>* suiv);
	~Noeud();
};

template<typename TType> inline
Noeud<TType>::Noeud() {
	Suivant = nullptr;
}

template<typename TType> inline
Noeud<TType>::Noeud(const TType& _info, Noeud<TType>* suiv) {
	info = _info;
	Suivant = suiv;
}

template<typename TType> inline
Noeud<TType>::Noeud(Noeud<TType>* suiv) {
	info = TType();
	Suivant = suiv;
}

template<typename TType> inline
Noeud<TType>::~Noeud() {
}