#pragma once
#include "Joueur.h"
#include "LeaderGym.h"
#include "MaitrePokemon.h"
#include <vector>

class SimulationJeu {
public:
    SimulationJeu(Joueur& joueur,
                  const std::vector<LeaderGym>& leaders,
                  const std::vector<MaitrePokemon>& maitres);

    // Boucle principale : affiche le menu et traite les choix
    void lancer();

private:
    Joueur& joueur;
    std::vector<LeaderGym> leaders;
    std::vector<MaitrePokemon> maitres;

    void afficherMenu() const;
    void choisirOption(int choix);
    void afficherPokemons() const;
    void afficherStats() const;
    void defierGym();
    void defierMaitre();
    void soignerEquipe();
};
