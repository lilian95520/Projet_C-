#pragma once

#include "Entraineur.h"
#include <string>
#include <vector>
using namespace std;

// Spécialisation d'Entraineur : les Maîtres Pokémon infligent +25% de dégâts
class MaitrePokemon : public Entraineur {
public:
    // Constructeur : nom et équipe hérité d'Entraineur
    MaitrePokemon(const std::string& nom, const std::vector<Pokemon*>& equipe);

    // Bonus de dégâts spécifique aux Maîtres Pokémon
    // Retourne 1.25 pour augmenter de 25% les dégât
    virtual float bonusDegats() const override;
};
