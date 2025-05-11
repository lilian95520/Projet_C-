#pragma once

#include <string>
#include <vector>
#include <map>
#include "Type.h"
#include "Pokemon.h"
#include "Joueur.h"
#include "LeaderGym.h"
#include "MaitrePokemon.h"
using namespace std;

// découpe une string "a|b|c" en {"a","b","c"} (utilisé pour types.csv)
vector<string> split(const string& s, char delim);

// charge data/types.csv
map<string, Type> chargerTypesDepuisCSV(const string& chemin);

// charge data/pokemon.csv
vector<Pokemon*> chargerPokemonsDepuisCSV(
    const string& chemin,
    const map<string, Type>& typesConnus
);

// charge data/joueur.csv
vector<Joueur> chargerJoueursDepuisCSV(
    const string& chemin,
    const vector<Pokemon*>& tousLesPokemons
);

// charge data/leaders.csv
vector<LeaderGym> chargerLeadersDepuisCSV(
    const string& chemin,
    const vector<Pokemon*>& tousLesPokemons
);

// charge data/maitres.csv
vector<MaitrePokemon> chargerMaitresDepuisCSV(
    const string& chemin,
    const vector<Pokemon*>& tousLesPokemons
);
