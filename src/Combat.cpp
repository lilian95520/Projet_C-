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
            cout<<adversaire.getNbPokemon()<<endl;
            cout<<"index"<<indexJoueur<<endl;
            cout<<indexad<<endl;
            Pokemon* pJ = joueur.getEquipe()[indexJoueur];
            Pokemon* pA = adversaire.getEquipe()[indexad];
    
            // Calcul du multiplicateur des types du Pokémon adverse contre l'attaque du joueur
            float multiplicateur = pA->getTypes()[0].getMultiContre(pJ->getAttaqueType());

    
            // Attaque joueur
            pJ->attaquer(pA, multiplicateur);
    
            if (pA->getHp() <= 0) {
                indexad++;
                if (indexad >= adversaire.getNbPokemon()) {
                    std::cout << "\n" << adversaire.getNom() << " n'a plus de Pokémon. " << joueur.getNom() << " gagne le combat !\n";
                    joueur.EnregistrerVictoire();
                    joueur.AjouterBadge();
                    break;
                } else {
                    std::cout << adversaire.getNom() << " envoie un nouveau Pokemon !\n";
                    cout<<indexad<<endl;
                    continue; // sauter l'attaque de l'adversaire
                }
            }
    
            // Calcul du multiplicateur inverse (attaque de l’adversaire)
            multiplicateur = adversaire.bonusDegats();
            multiplicateur = pJ->getTypes()[0].getMultiContre(pA->getAttaqueType());
    
            // Attaque adversaire
            pA->attaquer(pJ, multiplicateur);
    
            if (pJ->getHp() <= 0) {
                indexJoueur++;
                if (indexJoueur >= joueur.getNbPokemon()) {
                    std::cout << "\n" << joueur.getNom() << " n'a plus de Pokemon. " << adversaire.getNom() << " gagne le combat !\n";
                    joueur.EnregistrerDefaite();
                    break;
                } else {
                    std::cout << joueur.getNom() << " envoie un nouveau Pokemon !\n";
                    cout<<indexJoueur<<endl;
                }
            }
    
            nbtour++;
        }
        cout<<"sorti"<<endl;
    }
    

