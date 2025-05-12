
#include <iostream>
#include <string>
#include <vector>
#include "Joueur.h"
#include <windows.h>
using namespace std;

Joueur::Joueur(const string& nom, const vector<Pokemon*>& equipe)
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
void Joueur::ajouterVaincu(Entraineur* e) {
    vaincus.push_back(e);
}

void Joueur::interagir() {
    system("cls");
    cout << "\n-- Interagir --\n";
    int idx = 1;
    for (auto* p : equipe)
        std::cout << idx++ << ") " << p->getNom() << " (Pokémon)\n";
    for (auto* e : vaincus)
        std::cout << idx++ << ") " << e->getNom() << " (Entraîneur)\n";
    cout << "0) Retour\nChoix > ";

    int choix; cin >> choix;
    if (choix > 0 && choix <= (int)equipe.size())
        equipe[choix-1]->interagir();
    else if (choix > (int)equipe.size() && choix < idx)
        vaincus[choix-1 - equipe.size()]->interagir();
    Sleep(5000);
    system("cls");
}
