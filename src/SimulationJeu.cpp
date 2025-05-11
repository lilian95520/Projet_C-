#include "SimulationJeu.h"
#include <iostream>
#include "Combat.h"
#include <limits>
#include <windows.h>

using namespace std;

SimulationJeu::SimulationJeu(Joueur& j,
                             const vector<LeaderGym>& l,
                             const vector<MaitrePokemon>& m)
  : joueur(j), leaders(l), maitres(m)
{}

void SimulationJeu::lancer() {
    system("cls");
    int choix = 0;
    do {
        afficherMenu();
        cout << "Votre choix > ";
        cin >> choix;
        choisirOption(choix);
    } while (choix != 0);
}

void SimulationJeu::afficherMenu() const {
    std::cout << "╔═════════════ Menu Principal ═════════════╗\n";
    std::cout << "║ 1) Afficher mes Pokémon                  ║\n";
    std::cout << "║ 2) Soigner mon équipe                    ║\n";
    std::cout << "║ 3) Changer ordre Pokémon                 ║\n";
    std::cout << "║ 4) Afficher Stat                         ║\n";
    std::cout << "║ 5) Affronter un Leader de Gym            ║\n";
    std::cout << "║ 6) Affronter un Maître Pokémon           ║\n";
    std::cout << "║ 7) Interagir                             ║\n";
    std::cout << "║ 0) Quitter                               ║\n";
    std::cout << "╚══════════════════════════════════════════╝\n";
}

void SimulationJeu::choisirOption(int choix) {
    switch (choix) {
        case 1: afficherPokemons(); break;
        case 2: soignerEquipe(); break;
        case 3: changerOrdrePokemon();    break;
        case 4: afficherStats();        break;
        case 5: defierGym();     break;
        case 6: defierMaitre(); break;
        case 7: joueur.interagir();break;
        case 0: cout << "Au revoir !\n"; break;
        default: cout << "Option invalide.\n"; 
    }
}

void SimulationJeu::afficherPokemons() const {
    system("cls");
    cout << "\n-- Vos Pokemon --\n";
    joueur.afficherEquipe();
    Sleep(10000);
    system("cls");
}

void SimulationJeu::afficherStats() const {
    system("cls");
    cout << "\n-- Vos Statistiques --\n";
    joueur.AfficherStat();
    Sleep(10000);
    system("cls");
}

void SimulationJeu::defierGym() {
    system("cls");
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
    system("cls");
    cout << "\n-- Soins de l'équipe de " << joueur.getNom() << " --\n";
    for (Pokemon* p : joueur.getEquipe()) {
        p->soigner();
    }
    cout << "Tous les Pokémon sont en pleine forme !\n";
    Sleep(10000);
    system("cls");
}
void SimulationJeu::defierMaitre() {
    if (joueur.GetNbBadge() < (int)leaders.size()) {
        cout << "Vous n'avez pas encore tous les badges.\n";
        Sleep(5000);
        system("cls");
        return;
    }
    
    size_t idx = rand() % maitres.size();
    cout << "Défi contre le Maître : " << maitres[idx].getNom() << "\n";
    Combat combat(joueur, const_cast<MaitrePokemon&>(maitres[idx]));
    combat.DemarrerCombat();
}

void SimulationJeu::changerOrdrePokemon(){
    system("cls");
    const auto liste = joueur.getEquipe();  
    for (size_t i = 0; i < liste.size(); ++i)
        cout << (i+1) << ") " << liste[i]->getNom() << "\n";

    cout << "Entrez les deux positions à échanger : ";
    int a, b;
    cin >> a >> b;
    joueur.changerOrdre(a-1, b-1);
    Sleep(10000);
    system("cls");
}


