
#include <iostream>
#include <string>
#include <vector>
#include "LeaderGym.h"
using namespace std;

LeaderGym::LeaderGym(string nom, string b, string gym):
Entraineur(nom), badge(b), gymnase(gym){}

LeaderGym::LeaderGym(const std::string& nom,
    const std::string& b,
    const std::string& g,
    const std::vector<Pokemon*>& equipe)
: Entraineur(nom, equipe),  // initialise le vecteur<Pokemon*> de la classe de base
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
