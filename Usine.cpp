#include "Usine.h"

Usine::Usine()
{

}

void Usine::ajouterClient(Client _client)
{
	listeClient.InsererQueue(_client);
}
