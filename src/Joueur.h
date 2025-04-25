#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
using namespace std;

class Joueur :public Entraineur
{
    private:
    int nbbadge;
    int nbcombat_gagne;
    int nbcombat_perdu;
    vector<string> badge;

    public:
    Joueur(string nom);
    void AjouterBadge();
    void EnregistrerVictoire(); 
    void EnregistrerDefaite(); 
    void AfficherStat();
};