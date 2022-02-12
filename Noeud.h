#pragma once
#include <iostream>

using namespace std;

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
	cout << "Creation Noeud sans paramètre" << endl;
	Suivant = nullptr;
}

template<typename TType> inline
Noeud<TType>::Noeud(const TType& _info, Noeud<TType>* suiv) {
	cout << "Creation Noeud avec paramètres" << endl;
	info = _info;
	Suivant = suiv;
}

template<typename TType> inline
Noeud<TType>::Noeud(Noeud<TType>* suiv) {

	Suivant = suiv;
}

template<typename TType> inline
Noeud<TType>::~Noeud() {
}