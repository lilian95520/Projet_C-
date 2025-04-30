#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

std::vector<string> split(const string& s, char delim) {
    vector<std::string> tokens;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) tokens.push_back(item);
    }
    return tokens;
}

map<string, Type> chargerTypesDepuisCSV(const string& chemin) {
    map<string, Type> result;
    ifstream file(chemin);
    if (!file.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << chemin << endl;
        return result;
    }

    string ligne;
    getline(file, ligne); // ignore l'en-tête

    while (getline(file, ligne)) {
        stringstream ss(ligne);
        string nom, faibles, resist;

        getline(ss, nom, ',');
        getline(ss, faibles, ',');
        getline(ss, resist, ',');

        result[nom] = Type(nom, split(faibles, '|'), split(resist, '|'));
    }

    file.close();
    return result;
}