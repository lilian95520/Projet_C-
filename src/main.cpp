#include <iostream>
#include <windows.h>  

#include "CSVLoader.h"
#include "SimulationJeu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    map<string, Type> types;
    vector<Pokemon*>   allPokemons;
    vector<Joueur>     joueurs;
    vector<LeaderGym>  leaders;
    vector<MaitrePokemon> maitres;

    // 1) Charger les types
    try{
        types       = chargerTypesDepuisCSV("data/types.csv");
        allPokemons = chargerPokemonsDepuisCSV("data/pokemon.csv", types);
        joueurs     = chargerJoueursDepuisCSV("data/joueur.csv", allPokemons);
        leaders     = chargerLeadersDepuisCSV("data/leaders.csv", allPokemons);
        maitres     = chargerMaitresDepuisCSV("data/maitres.csv", allPokemons);

    }
    catch(const char* msg){
        cerr << "Exception caputrée : " << msg<<endl;
        return EXIT_FAILURE;
    }
    if (joueurs.empty()) {
        cerr << "Aucun joueur trouvé, arrêt du programme.\n";
        return EXIT_FAILURE;
    }

    cout << "Démarrage de la simulation pour le joueur « "<< joueurs[0].getNom() << " »\n\n";
    Sleep(5000);
    SimulationJeu sim(joueurs[0], leaders, maitres);
    sim.lancer();

    
    for (Pokemon* p : allPokemons) {
        delete p;
    }
    
    

    return 0;
}
