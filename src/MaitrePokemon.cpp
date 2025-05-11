#include "MaitrePokemon.h"

MaitrePokemon::MaitrePokemon(const string& nom, const vector<Pokemon*>& equipe)
    : Entraineur(nom, equipe)
{}

float MaitrePokemon::bonusDegats() const {
    return 1.25f;
}
