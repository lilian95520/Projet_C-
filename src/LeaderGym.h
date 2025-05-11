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
    LeaderGym(const string& nom,
        const string& badge,
        const string& gymnase,
        const vector<Pokemon*>& equipe);
    string getBadge();
    string getGymnase();
    void interagir() override; 
};