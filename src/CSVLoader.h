#pragma once

#include <string>
#include <vector>
#include <map>
#include "Type.h"
#include "Pokemon.h"
#include "Joueur.h"
#include "LeaderGym.h"
#include "MaitrePokemon.h"

// découpe une string "a|b|c" en {"a","b","c"} (utilisé pour types.csv)
std::vector<std::string> split(const std::string& s, char delim);

// charge data/types.csv
std::map<std::string, Type> chargerTypesDepuisCSV(const std::string& chemin);

// charge data/pokemon.csv
// nom,Type 1,Type 2,Points de Vie,Attaque,Dégâts d'Attaque
std::vector<Pokemon*> chargerPokemonsDepuisCSV(
    const std::string& chemin,
    const std::map<std::string, Type>& typesConnus
);

// charge data/joueur.csv
// Nom,Pokemon1,Pokemon2,...,Pokemon6
std::vector<Joueur> chargerJoueursDepuisCSV(
    const std::string& chemin,
    const std::vector<Pokemon*>& tousLesPokemons
);

// charge data/leaders.csv
// Nom,Gymnase,Medaille,Pokemon1,...,Pokemon6
std::vector<LeaderGym> chargerLeadersDepuisCSV(
    const std::string& chemin,
    const std::vector<Pokemon*>& tousLesPokemons
);

// charge data/maitres.csv
// Nom,Pokemon1,...,Pokemon6
std::vector<MaitrePokemon> chargerMaitresDepuisCSV(
    const std::string& chemin,
    const std::vector<Pokemon*>& tousLesPokemons
);
