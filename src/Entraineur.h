#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Entraineur
{
    protected: 
    string nom; 
    vector<Pokemon*> equipe;

    public:
    Entraineur(string n, vector<Pokemon*> e);
    Entraineur(string n);
    string getNom();
    void ajouterPokemon(Pokemon* p);
    vector<Pokemon*> getEquipe();
    int getNbPokemon();
    void afficherEquipe();



};