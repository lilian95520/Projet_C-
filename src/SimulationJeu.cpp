#include "SimulationJeu.h"
#include <iostream>
#include "Combat.h"
#include <limits>

SimulationJeu::SimulationJeu(Joueur& j,
                             const std::vector<LeaderGym>& l,
                             const std::vector<MaitrePokemon>& m)
  : joueur(j), leaders(l), maitres(m)
{}

void SimulationJeu::lancer() {
    int choix = 0;
    do {
        afficherMenu();
        std::cout << "Votre choix > ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choisirOption(choix);
    } while (choix != 0);
}

void SimulationJeu::afficherMenu() const {
    std::cout << "\n=== MENU PRINCIPAL ===\n"
              << "1) Afficher mes Pokemon\n"
              << "2) Voir mes stats\n"
              << "3) Affronter un Leader de Gym\n"
              << "4) Affronter un Maitre Pokemon\n"
              << "0) Quitter\n";
}

void SimulationJeu::choisirOption(int choix) {
    switch (choix) {
        case 1: afficherPokemons(); break;
        case 2: afficherStats();    break;
        case 3: defierGym();        break;
        case 4: defierMaitre();     break;
        case 0: std::cout << "Au revoir !\n"; break;
        default: std::cout << "Option invalide.\n"; 
    }
}

void SimulationJeu::afficherPokemons() const {
    std::cout << "\n-- Vos Pokemon --\n";
    joueur.afficherEquipe();
}

void SimulationJeu::afficherStats() const {
    std::cout << "\n-- Vos Statistiques --\n";
    joueur.AfficherStat();
}

void SimulationJeu::defierGym() {
    std::cout << "\nChoisissez un Leader de Gym :\n";
    for (size_t i = 0; i < leaders.size(); ++i) {
        std::cout << i+1 << ") " << leaders[i].getNom()
                  << " (" << leaders[i].getBadge() << ")\n";
    }
    std::cout << "0) Retour\nVotre choix > ";
    int c; std::cin >> c;
    if (c > 0 && c <= (int)leaders.size()) {
        Combat combat(joueur, const_cast<LeaderGym&>(leaders[c-1]));
        combat.DemarrerCombat();
    }
}

void SimulationJeu::defierMaitre() {
    if (joueur.GetNbBadge() < (int)leaders.size()) {
        std::cout << "Vous n'avez pas encore tous les badges.\n";
        return;
    }
    // Choix aléatoire ou liste
    size_t idx = rand() % maitres.size();
    std::cout << "Défi contre le Maître : " << maitres[idx].getNom() << "\n";
    Combat combat(joueur, const_cast<MaitrePokemon&>(maitres[idx]));
    combat.DemarrerCombat();
}


