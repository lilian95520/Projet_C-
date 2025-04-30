#include <iostream>
using namespace std;
#include "Combat.h"
#include "Pokemon.h"

Combat::Combat(Entraineur& j, Entraineur& ad, int nombretour)
    : joueur(j), adversaire(ad), nbtour(nombretour) {}

void Combat:: DemarrerCombat()
{
    int indexJoueur=0;
    int indexad=0;
    bool combatTerminer=false;

    while (combatTerminer == false)
    {
        Pokemon* pJ=joueur.getEquipe()[indexJoueur];
        Pokemon* pA=adversaire.getEquipe()[indexad];
        string typeattaque = pJ->getAttaqueType();
        float multiplicateur =1.0f;
        for(const auto& type : pA -> getType()  )
        {
            auto it = typeconnu.find(type);
            if(it!=typeconnu.end())
            {
                multiplicateur *=it->second.getMultiplicateurContre(typeattaque);

            }
        }
        
    }
    



}

