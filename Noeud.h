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
<<<<<<< HEAD
	cout << "Creation Noeud sans paramètre" << endl;
=======
>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
	Suivant = nullptr;
}

template<typename TType> inline
Noeud<TType>::Noeud(const TType& _info, Noeud<TType>* suiv) {
<<<<<<< HEAD
	cout << "Creation Noeud avec paramètres" << endl;
=======
>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
	info = _info;
	Suivant = suiv;
}

template<typename TType> inline
Noeud<TType>::Noeud(Noeud<TType>* suiv) {
<<<<<<< HEAD

=======
	info = TType();
>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
	Suivant = suiv;
}

template<typename TType> inline
Noeud<TType>::~Noeud() {
}