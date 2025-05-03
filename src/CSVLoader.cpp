#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>  // std::find

// --- split (pour types.csv) ---
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) tokens.push_back(item);
    }
    return tokens;
}

// --- types.csv (inchangé) ---
std::map<std::string, Type> chargerTypesDepuisCSV(const std::string& chemin) {
    std::map<std::string, Type> result;
    std::ifstream file(chemin);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossibe d'ouvrir " << chemin << std::endl;
        return result;
    }
    std::string ligne;
    std::getline(file, ligne); // entête
    while (std::getline(file, ligne)) {
        std::stringstream ss(ligne);
        std::string nom, faib, res;
        std::getline(ss, nom, ',');
        std::getline(ss, faib, ',');
        std::getline(ss, res, ',');
        result[nom] = Type(nom, split(faib, '|'), split(res, '|'));
    }
    return result;
}

// --- pokemon.csv ---
std::vector<Pokemon*> chargerPokemonsDepuisCSV(
    const std::string& chemin,
    const std::map<std::string, Type>& typesConnus
) {
    std::vector<Pokemon*> result;
    std::ifstream file(chemin);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir " << chemin << std::endl;
        return result;
    }
    std::string ligne;
    std::getline(file, ligne); // entête
    while (std::getline(file, ligne)) {
        std::stringstream ss(ligne);
        std::string nom, t1, t2, hpStr, attNom, dmgStr;
        std::getline(ss, nom, ',');
        std::getline(ss, t1, ',');
        std::getline(ss, t2, ',');
        std::getline(ss, hpStr, ',');
        std::getline(ss, attNom, ',');
        std::getline(ss, dmgStr, ',');

        int hp = std::stoi(hpStr);
        int dmg = std::stoi(dmgStr);

        // construire le vecteur<Type>
        std::vector<Type> types;
        if (!t1.empty() && typesConnus.count(t1)) types.push_back(typesConnus.at(t1));
        if (!t2.empty() && typesConnus.count(t2)) types.push_back(typesConnus.at(t2));

        // le type de l'attaque = premier type, ou string vide si absent
        std::string attType = types.empty() ? std::string{} : types.front().getNom();

        result.push_back(new Pokemon(nom, types, hp, attNom, dmg));
    }
    return result;
}

// --- utilitaire : map nom→Pokemon* pour lookup rapide ---
static std::map<std::string, Pokemon*> buildPokemonMap(const std::vector<Pokemon*>& v) {
    std::map<std::string, Pokemon*> m;
    for (auto* p : v) m[p->getNom()] = p;
    return m;
}

// --- joueur.csv ---
std::vector<Joueur> chargerJoueursDepuisCSV(
    const std::string& chemin,
    const std::vector<Pokemon*>& tousLesPokemons
) {
    auto mapP = buildPokemonMap(tousLesPokemons);
    std::vector<Joueur> result;
    std::ifstream file(chemin);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir " << chemin << std::endl;
        return result;
    }
    std::string ligne;
    std::getline(file, ligne); // entête
    while (std::getline(file, ligne)) {
        std::stringstream ss(ligne);
        std::string nom;
        std::vector<Pokemon*> equipe;
        std::getline(ss, nom, ',');
        // 6 colonnes Pokémon
        for (int i = 0; i < 6; ++i) {
            std::string poke;
            std::getline(ss, poke, ',');
            if (!poke.empty() && mapP.count(poke))
                equipe.push_back(mapP[poke]);
        }
        result.emplace_back(nom, equipe);
    }
    return result;
}

// --- leaders.csv ---
std::vector<LeaderGym> chargerLeadersDepuisCSV(
    const std::string& chemin,
    const std::vector<Pokemon*>& tousLesPokemons
) {
    auto mapP = buildPokemonMap(tousLesPokemons);
    std::vector<LeaderGym> result;
    std::ifstream file(chemin);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir " << chemin << std::endl;
        return result;
    }
    std::string ligne;
    std::getline(file, ligne); // entête
    while (std::getline(file, ligne)) {
        std::stringstream ss(ligne);
        std::string nom, gym, medaille;
        std::vector<Pokemon*> equipe;
        std::getline(ss, nom, ',');
        std::getline(ss, gym, ',');
        std::getline(ss, medaille, ',');
        for (int i = 0; i < 6; ++i) {
            std::string poke;
            std::getline(ss, poke, ',');
            if (!poke.empty() && mapP.count(poke))
                equipe.push_back(mapP[poke]);
        }
        result.emplace_back(nom, gym, medaille, equipe);
    }
    return result;
}

// --- maitres.csv ---
std::vector<MaitrePokemon> chargerMaitresDepuisCSV(
    const std::string& chemin,
    const std::vector<Pokemon*>& tousLesPokemons
) {
    auto mapP = buildPokemonMap(tousLesPokemons);
    std::vector<MaitrePokemon> result;
    std::ifstream file(chemin);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir " << chemin << std::endl;
        return result;
    }
    std::string ligne;
    std::getline(file, ligne); // entête
    while (std::getline(file, ligne)) {
        std::stringstream ss(ligne);
        std::string nom;
        std::vector<Pokemon*> equipe;
        std::getline(ss, nom, ',');
        for (int i = 0; i < 6; ++i) {
            std::string poke;
            std::getline(ss, poke, ',');
            if (!poke.empty() && mapP.count(poke))
                equipe.push_back(mapP[poke]);
        }
        result.emplace_back(nom, equipe);
    }
    return result;
}
