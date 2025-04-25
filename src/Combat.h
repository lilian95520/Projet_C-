#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
using namespace std;

class Combat
{
    private:
    Entraineur joueur;
    Entraineur adversaire;
    int nbtour;

    public:
    Combat(Entraineur& j, Entraineur& ad, int nombretour);
    
    void DemarrerCombat();
    

};