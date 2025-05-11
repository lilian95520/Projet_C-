#include <iostream>
using namespace std;
#include "Combat.h"
#include "Pokemon.h"
#include "Entraineur.h"
#include "Joueur.h"

Combat::Combat(Joueur& j, Entraineur& ad)
    : joueur(j), adversaire(ad), nbtour(0) {}

void Combat::DemarrerCombat()
    {
        int indexJoueur = 0;
        int indexad = 0;
    
        while (indexJoueur < joueur.getNbPokemon() && indexad < adversaire.getNbPokemon()) {
            Pokemon* pJ = joueur.getEquipe()[indexJoueur];
            Pokemon* pA = adversaire.getEquipe()[indexad];
    
            float multiplicateur = pA->getTypes()[0].getMultiContre(pJ->getAttaqueType());

    
            pJ->attaquer(pA, multiplicateur);
    
            if (pA->getHp() <= 0) {
                indexad++;
                if (indexad >= adversaire.getNbPokemon()) {
                    cout << "\n" << adversaire.getNom() << " n'a plus de Pokémon. " << joueur.getNom() << " gagne le combat !\n";
                    joueur.EnregistrerVictoire();
                    joueur.AjouterBadge();
                    break;
                } else {
                    cout << adversaire.getNom() << " envoie un nouveau Pokemon !\n";
                    continue; 
                }
            }
    
            multiplicateur = adversaire.bonusDegats();
            multiplicateur = pJ->getTypes()[0].getMultiContre(pA->getAttaqueType());
    
            pA->attaquer(pJ, multiplicateur);
    
            if (pJ->getHp() <= 0) {
                indexJoueur++;
                if (indexJoueur >= joueur.getNbPokemon()) {
                    cout << "\n" << joueur.getNom() << " n'a plus de Pokemon. " << adversaire.getNom() << " gagne le combat !\n";
                    joueur.EnregistrerDefaite();
                    break;
                } else {
                    cout << joueur.getNom() << " envoie un nouveau Pokemon !\n";
                }
            }
    
            nbtour++;
        }
    }
    

