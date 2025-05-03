#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
using namespace std;

class Joueur :public Entraineur
{
    private:
    int nbBadges;
    int nbCombatGagne;
    int nbCombatPerdu;

    public:
    Joueur(const string& nom, const vector<Pokemon*>& equipe = {});
    void AjouterBadge();
    void EnregistrerVictoire(); 
    void EnregistrerDefaite(); 
    int GetNbBadge();
    void AfficherStat();
    
};