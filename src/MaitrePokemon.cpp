#include "MaitrePokemon.h"

MaitrePokemon::MaitrePokemon(const std::string& nom, const std::vector<Pokemon*>& equipe)
    : Entraineur(nom, equipe)
{}

float MaitrePokemon::bonusDegats() const {
    return 1.25f;
}
