#include <iostream>
#include <windows.h>  // uniquement sous Windows

#include "CSVLoader.h"
#include "SimulationJeu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // 1) Charger les types
    auto types = chargerTypesDepuisCSV("data/types.csv");
    std::cout << "Types charges : " << types.size() << std::endl;

    // 2) Charger tous les Pokemon
    auto allPokemons = chargerPokemonsDepuisCSV("data/pokemon.csv", types);
    std::cout << "Pokemons charges : " << allPokemons.size() << "\n";
    for (auto* p : allPokemons) {
        p->afficher();
    }
    std::cout << std::endl;

    // 3) Charger les joueurs
    auto joueurs = chargerJoueursDepuisCSV("data/joueur.csv", allPokemons);
    std::cout << "Joueurs charges : " << joueurs.size() << "\n";
    for (auto& j : joueurs) {
        j.afficherEquipe();
    }
    std::cout << std::endl;

    // 4) Charger les leaders
    auto leaders = chargerLeadersDepuisCSV("data/leaders.csv", allPokemons);
    std::cout << "Leaders charges : " << leaders.size() << "\n";
    for (auto& lg : leaders) {
        lg.afficherEquipe();
    }
    std::cout << std::endl;

    // 5) Charger les maîtres
    auto maitres = chargerMaitresDepuisCSV("data/maitres.csv", allPokemons);
    std::cout << "Maîtres chargés : " << maitres.size() << "\n";
    for (auto& m : maitres) {
        m.afficherEquipe();
    }
    std::cout << std::endl;

    // 6) Lancer la simulation avec le premier joueur
    if (!joueurs.empty()) {
        std::cout << "Démarrage de la simulation pour le joueur : " 
                  << joueurs[0].getNom() << "\n\n";
        SimulationJeu sim(joueurs[0], leaders, maitres);
        sim.lancer();
    } else {
        std::cerr << "Aucun joueur chargé, fin du programme.\n";
    }

    // 7) Nettoyage mémoire (optionnel pour un test rapide)
    for (auto* p : allPokemons) delete p;

    return 0;
}
