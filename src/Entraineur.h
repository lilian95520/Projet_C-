#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Interagir.h"

using namespace std;

class Entraineur : public Interagir
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
    void changerOrdre(int idx1, int idx2);
    virtual float bonusDegats() const ;
    void interagir() override;



};