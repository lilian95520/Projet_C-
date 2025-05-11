#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>  
using namespace std;

// --- split (pour types.csv) ---
vector<string> split(const string& s, char delim) {
    vector<string> tokens;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) tokens.push_back(item);
    }
    return tokens;
}

// --- types.csv (inchangé) ---
map<string, Type> chargerTypesDepuisCSV(const string& chemin) {
    map<string, Type> result;
    ifstream file(chemin);
    if (!file.is_open()) {
        throw ios_base::failure("Impossible d'ouvrir " + chemin);       
    }
    string ligne;
    getline(file, ligne); 
    while (getline(file, ligne)) {
        stringstream ss(ligne);
        string nom, faib, res;
        getline(ss, nom, ',');
        getline(ss, faib, ',');
        getline(ss, res, ',');
        result[nom] = Type(nom, split(faib, '|'), split(res, '|'));
    }
    return result;
}

// --- pokemon.csv ---
vector<Pokemon*> chargerPokemonsDepuisCSV(
    const string& chemin,
    const map<string, Type>& typesConnus
) {
    vector<Pokemon*> result;
    ifstream file(chemin);
    if (!file.is_open()) {
        throw ios_base::failure("Impossible d'ouvrir " + chemin);        
    }
    string ligne;
    getline(file, ligne); // entête
    while (getline(file, ligne)) {
        stringstream ss(ligne);
        string nom, t1, t2, hpStr, attNom, dmgStr;
        getline(ss, nom, ',');
        getline(ss, t1, ',');
        getline(ss, t2, ',');
        getline(ss, hpStr, ',');
        getline(ss, attNom, ',');
        getline(ss, dmgStr, ',');

        int hp = stoi(hpStr);
        int dmg = stoi(dmgStr);

        // construire le vecteur<Type>
        vector<Type> types;
        if (!t1.empty() && typesConnus.count(t1)) types.push_back(typesConnus.at(t1));
        if (!t2.empty() && typesConnus.count(t2)) types.push_back(typesConnus.at(t2));

        // le type de l'attaque = premier type, ou string vide si absent
        string attType = types.empty() ? string{} : types.front().getNom();

        result.push_back(new Pokemon(nom, types, hp, attNom, dmg));
    }
    return result;
}

// --- utilitaire : map nom→Pokemon* pour lookup rapide ---
static map<string, Pokemon*> buildPokemonMap(const vector<Pokemon*>& v) {
    map<string, Pokemon*> m;
    for (auto* p : v) m[p->getNom()] = p;
    return m;
}

// --- joueur.csv ---
vector<Joueur> chargerJoueursDepuisCSV(
    const string& chemin,
    const vector<Pokemon*>& tousLesPokemons
) {
    auto mapP = buildPokemonMap(tousLesPokemons);
    vector<Joueur> result;
    ifstream file(chemin);
    if (!file.is_open()) {
        throw ios_base::failure("Impossible d'ouvrir " + chemin);        
    }
    string ligne;
    getline(file, ligne); // entête
    while (getline(file, ligne)) {
        stringstream ss(ligne);
        string nom;
        vector<Pokemon*> equipe;
        getline(ss, nom, ',');
        // 6 colonnes Pokémon
        for (int i = 0; i < 6; ++i) {
            string poke;
            getline(ss, poke, ',');
            if (!poke.empty() && mapP.count(poke))
                equipe.push_back(mapP[poke]);
        }
        result.emplace_back(nom, equipe);
    }
    return result;
}

// --- leaders.csv ---
vector<LeaderGym> chargerLeadersDepuisCSV(
    const string& chemin,
    const vector<Pokemon*>& tousLesPokemons
) {
    auto mapP = buildPokemonMap(tousLesPokemons);
    vector<LeaderGym> result;
    ifstream file(chemin);
    if (!file.is_open()) {
        throw ios_base::failure("Impossible d'ouvrir " + chemin);        
    }
    string ligne;
    getline(file, ligne); // entête
    while (getline(file, ligne)) {
        stringstream ss(ligne);
        string nom, gym, medaille;
        vector<Pokemon*> equipe;
        getline(ss, nom, ',');
        getline(ss, gym, ',');
        getline(ss, medaille, ',');
        for (int i = 0; i < 6; i++) {
            string poke;
            getline(ss, poke, ',');
            if (!poke.empty() && mapP.count(poke))
                equipe.push_back(mapP[poke]);
        }
        result.emplace_back(nom, gym, medaille, equipe);
    }
    return result;
}

// --- maitres.csv ---
vector<MaitrePokemon> chargerMaitresDepuisCSV(
    const string& chemin,
    const vector<Pokemon*>& tousLesPokemons
) {
    auto mapP = buildPokemonMap(tousLesPokemons);
    vector<MaitrePokemon> result;
    ifstream file(chemin);
    if (!file.is_open()) {
        throw ios_base::failure("Impossible d'ouvrir " + chemin);        
    }
    string ligne;
    getline(file, ligne); 
    while (getline(file, ligne)) {
        stringstream ss(ligne);
        string nom;
        vector<Pokemon*> equipe;
        getline(ss, nom, ',');
        for (int i = 0; i < 6; ++i) {
            string poke;
            getline(ss, poke, ',');
            if (!poke.empty() && mapP.count(poke))
                equipe.push_back(mapP[poke]);
        }
        result.emplace_back(nom, equipe);
    }
    return result;
}
