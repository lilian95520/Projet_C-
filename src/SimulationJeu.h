#pragma once
#include "Joueur.h"
#include "LeaderGym.h"
#include "MaitrePokemon.h"
#include <vector>
using namespace std;

class SimulationJeu {
public:
    SimulationJeu(Joueur& joueur,
                  const vector<LeaderGym>& leaders,
                  const vector<MaitrePokemon>& maitres);

    // Boucle principale : affiche le menu et traite les choix
    void lancer();

private:
    Joueur& joueur;
    vector<LeaderGym> leaders;
    vector<MaitrePokemon> maitres;

    void afficherMenu() const;
    void choisirOption(int choix);
    void afficherPokemons() const;
    void afficherStats() const;
    void defierGym();
    void defierMaitre();
    void soignerEquipe();
    void changerOrdrePokemon();
};
