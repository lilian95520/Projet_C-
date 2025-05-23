#include <iostream>
#include <windows.h>  
#include "Combat.h"
#include "Pokemon.h"
#include "Entraineur.h"
#include "Joueur.h"

using namespace std;

Combat::Combat(Joueur& j, Entraineur& ad)
    : joueur(j), adversaire(ad), nbtour(0) {}

void Combat::DemarrerCombat()
    {
        system("cls");
        cout << "╔═══════════════ Combat Pokémon ═══════════════╗\n";
        int indexJoueur = 0;
        int indexad = 0;
        auto skipFaint = [&](Entraineur& e, int& idx) {
            while (idx < e.getNbPokemon() && e.getEquipe()[idx]->getHp() <= 0) {
                idx++;
            }
        };
        skipFaint(joueur,indexJoueur);
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
                    joueur.ajouterVaincu(&adversaire);
                    break;
                } else {
                    cout << adversaire.getNom() << " envoie un nouveau Pokemon !\n";
                    cout << "\n────────────────────────────────────────\n\n";
                    Sleep(3000);

                    continue; 
                }
            }
            cout << "\n────────────────────────────────────────\n\n";
            Sleep(3000);

    
            multiplicateur = adversaire.bonusDegats();
            multiplicateur *= pJ->getTypes()[0].getMultiContre(pA->getAttaqueType());
    
            pA->attaquer(pJ, multiplicateur);

            if (pJ->getHp() <= 0) {
                indexJoueur++;
                if (indexJoueur >= joueur.getNbPokemon()) {
                    cout << "\n" << joueur.getNom() << " n'a plus de Pokemon. " << adversaire.getNom() << " gagne le combat !\n";
                    joueur.EnregistrerDefaite();
                    break;
                } else {
                    cout << joueur.getNom() << " envoie un nouveau Pokemon !\n";
                    Sleep(3000);
                }
            }
            cout << "\n────────────────────────────────────────\n\n";
            Sleep(3000);

            nbtour++;
        }
        Sleep(5000);
        system("cls");

    }
    

