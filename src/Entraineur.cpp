#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
#include "Pokemon.h"

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
    std::cout << "Équipe de " << nom << " :" << std::endl;
    if (equipe.empty()) {
        std::cout << "  (aucun Pokémon)" << std::endl;
        return;
    }
    for (size_t i = 0; i < equipe.size(); ++i) {
        Pokemon* p = equipe[i];
        std::cout << "  " << (i + 1) << ". ";
        // On peut soit afficher le nom et les PV :
        std::cout << p->getNom() << " (HP: " << p->getHp() << ")" << std::endl;
        // — ou appeler p->afficher() pour plus de détails :
        // p->afficher();
    }
}