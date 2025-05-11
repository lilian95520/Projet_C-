#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
#include "Pokemon.h"
#include <algorithm>
using namespace std;

Entraineur::Entraineur(string n, vector<Pokemon*> e): 
nom(n),equipe(e){}

Entraineur:: Entraineur(string n): nom(n){}
string Entraineur::getNom()
{
    return nom;
}

void Entraineur::ajouterPokemon(Pokemon* p) {
    equipe.push_back(p);
}

vector<Pokemon*> Entraineur::getEquipe()
{
    return equipe;
}

int Entraineur::getNbPokemon()
{
    return equipe.size();
}
float Entraineur::bonusDegats() const {
    return 1.0f;
}

void Entraineur::afficherEquipe() {
    cout << "Équipe de " << nom << " :" << endl;
    if (equipe.empty()) {
        cout << "  (aucun Pokémon)" << endl;
        return;
    }
    for (size_t i = 0; i < equipe.size(); ++i) {
        Pokemon* p = equipe[i];
        cout << "  " << (i + 1) << ". ";
        cout << p->getNom() << " (HP: " << p->getHp() << ")" << endl;
    }

}
void Entraineur::changerOrdre(int idx1,int idx2){
    swap(equipe[idx1],equipe[idx2]);
    cout << "Echange des pokémons positions "<< (idx1+1) << " et " << (idx2+1) << ".\n";
    
}