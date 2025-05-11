#include "SimulationJeu.h"
#include <iostream>
#include "Combat.h"
#include <limits>
using namespace std;

SimulationJeu::SimulationJeu(Joueur& j,
                             const vector<LeaderGym>& l,
                             const vector<MaitrePokemon>& m)
  : joueur(j), leaders(l), maitres(m)
{}

void SimulationJeu::lancer() {
    int choix = 0;
    do {
        afficherMenu();
        cout << "Votre choix > ";
        cin >> choix;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choisirOption(choix);
    } while (choix != 0);
}

void SimulationJeu::afficherMenu() const {
    cout << "\n=== MENU PRINCIPAL ===\n"
              << "1) Afficher mes Pokemon\n"
              << "2) Changer l'ordre des Pokémon\n"
              << "3) Voir mes stats\n"
              << "4) Affronter un Leader de Gym\n"
              << "5) Affronter un Maitre Pokémon\n"
              << "6) Soigner tous mes Pokémon\n"
              << "0) Quitter\n";
}

void SimulationJeu::choisirOption(int choix) {
    switch (choix) {
        case 1: afficherPokemons(); break;
        case 2: changerOrdrePokemon(); break;
        case 3: afficherStats();    break;
        case 4: defierGym();        break;
        case 5: defierMaitre();     break;
        case 6: soignerEquipe();
        case 0: cout << "Au revoir !\n"; break;
        default: cout << "Option invalide.\n"; 
    }
}

void SimulationJeu::afficherPokemons() const {
    cout << "\n-- Vos Pokemon --\n";
    joueur.afficherEquipe();
}

void SimulationJeu::afficherStats() const {
    cout << "\n-- Vos Statistiques --\n";
    joueur.AfficherStat();
}

void SimulationJeu::defierGym() {
    cout << "\nChoisissez un Leader de Gym :\n";
    for (size_t i = 0; i < leaders.size(); ++i) {
        cout << i+1 << ") " << leaders[i].getNom()
                  << " (" << leaders[i].getBadge() << ")\n";
    }
    cout << "0) Retour\nVotre choix > ";
    int c; cin >> c;
    if (c > 0 && c <= (int)leaders.size()) {
        Combat combat(joueur, const_cast<LeaderGym&>(leaders[c-1]));
        combat.DemarrerCombat();
    }
}

void SimulationJeu::soignerEquipe() {
    cout << "\n-- Soins de l'équipe de " << joueur.getNom() << " --\n";
    for (Pokemon* p : joueur.getEquipe()) {
        p->soigner();
    }
    cout << "Tous les Pokémon sont en pleine forme !\n";
}
void SimulationJeu::defierMaitre() {
    if (joueur.GetNbBadge() < (int)leaders.size()) {
        cout << "Vous n'avez pas encore tous les badges.\n";
        return;
    }
    
    size_t idx = rand() % maitres.size();
    cout << "Défi contre le Maître : " << maitres[idx].getNom() << "\n";
    Combat combat(joueur, const_cast<MaitrePokemon&>(maitres[idx]));
    combat.DemarrerCombat();
}

void SimulationJeu::changerOrdrePokemon(){
    const auto liste = joueur.getEquipe();  
    for (size_t i = 0; i < liste.size(); ++i)
        cout << (i+1) << ") " << liste[i]->getNom() << "\n";

    cout << "Entrez les deux positions à échanger : ";
    int a, b;
    cin >> a >> b;
    joueur.changerOrdre(a-1, b-1);
}


