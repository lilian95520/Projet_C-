#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
using namespace std;

class LeaderGym :public Entraineur
{
    private:
    string badge;
    string gymnase;

    public:
    LeaderGym(string nom, string b, string gym);
    LeaderGym(const std::string& nom,
        const std::string& badge,
        const std::string& gymnase,
        const std::vector<Pokemon*>& equipe);
    string getBadge();
    string getGymnase();
};