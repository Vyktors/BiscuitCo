#include "Commande.h"

using namespace std;


Commande::Commande()
{
	client_source = "";
	client_destinataire = "";
}

Commande::Commande(string _client_source, string _client_destinataire)
{
	client_source = _client_source;
	client_destinataire = _client_destinataire;
}

Commande::~Commande()
{
<<<<<<< HEAD

=======
	listePaquet.~Liste();
>>>>>>> b51fa1f5e600e5027e3983b3866e35e8c7f645b1
}

void Commande::ajouterPaquet(Paquet& _paquet)
{
	listePaquet.InsererQueue(_paquet);
}

void Commande::afficher()
{
	for (listePaquet.FixerTete(); listePaquet.EstDansListe(); listePaquet.Suivant())
	{
		cout << listePaquet.ValeurCourante().afficher() << endl;
	}
}


