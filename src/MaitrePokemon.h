#pragma once

#include "Entraineur.h"
#include <string>
#include <vector>
using namespace std;

class MaitrePokemon : public Entraineur {
public:
    MaitrePokemon(const string& nom, const vector<Pokemon*>& equipe);

    virtual float bonusDegats() const override;
};
