#include <iostream>
#include <string>
#pragma once
#include <vector>
#include "Entraineur.h"
#include "Joueur.h"
using namespace std;

class Combat
{
    private:
    Joueur& joueur;
    Entraineur& adversaire;
    int nbtour;

    public:
    Combat(Joueur& j, Entraineur& ad);
    
    void DemarrerCombat();
    

};