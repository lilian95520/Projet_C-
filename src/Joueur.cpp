
#include <iostream>
#include <string>
#include <vector>
#include "Joueur.h"
using namespace std;

Joueur::Joueur(string nom):
Entraineur(nom), nbbadge(0), nbcombat_gagne(0), nbcombat_perdu(0), badge(""){}

void Joueur::AjouterBadge()
{
    nbbadge++;

}
void Joueur::EnregistrerVictoire()
{
    nbcombat_gagne++;
}
void Joueur::EnregistrerDefaite()
{
    nbcombat_perdu++;
}
void Joueur::AfficherStat()
{
    cout<<nom<<" a fait: "<< nbcombat_gagne <<" victoire et "<< nbcombat_perdu << " défaite"<<endl;
}
