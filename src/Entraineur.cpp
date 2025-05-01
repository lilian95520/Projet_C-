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