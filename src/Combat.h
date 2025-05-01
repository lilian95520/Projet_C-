#include <iostream>
#include <string>
#pragma once
#include <vector>
#include "Entraineur.h"
using namespace std;

class Combat
{
    private:
    Entraineur& joueur;
    Entraineur& adversaire;
    int nbtour;

    public:
    Combat(Entraineur& j, Entraineur& ad);
    
    void DemarrerCombat();
    

};