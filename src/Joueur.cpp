
#include <iostream>
#include <string>
#include <vector>
#include "Joueur.h"
using namespace std;

Joueur::Joueur(const std::string& nom, const std::vector<Pokemon*>& equipe)
    : Entraineur(nom, equipe), nbBadges(0), nbCombatGagne(0), nbCombatPerdu(0) {}

void Joueur::AjouterBadge()
{
    nbBadges++;

}
void Joueur::EnregistrerVictoire()
{
    nbCombatGagne++;
}
void Joueur::EnregistrerDefaite()
{
    nbCombatPerdu++;
}
void Joueur::AfficherStat()
{
    cout<<nom<<" a fait: "<< nbCombatGagne <<" victoire et "<< nbCombatPerdu << " defaite"<<endl;
}
int Joueur::GetNbBadge(){
    return nbBadges;
}