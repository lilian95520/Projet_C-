#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
using namespace std;

Entraineur::Entraineur(string n, vector<Pokemon> listP[]):
nom(n),  list_Pokemon(listP){}

string Entraineur::getNom()
{
    return nom;
}
    
vector<Pokemon> Entraineur::getList()
{
    return list_Pokemon;
}

int Entraineur::getNbPokemon()
{
    return list_Pokemon.size();
}