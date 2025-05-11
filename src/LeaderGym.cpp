
#include <iostream>
#include <string>
#include <vector>
#include "LeaderGym.h"
using namespace std;

LeaderGym::LeaderGym(string nom, string b, string gym):
Entraineur(nom), badge(b), gymnase(gym){}

LeaderGym::LeaderGym(const string& nom,
    const string& b,
    const string& g,
    const vector<Pokemon*>& equipe)
: Entraineur(nom, equipe),  
badge(b),
gymnase(g)
{}
string LeaderGym::getBadge()
{
    return badge;
}

string LeaderGym::getGymnase()
{
    return gymnase;
}
