
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
static const map<string, string> messagesLeader = {
    { "Pierre",   "Pierre : « Tu as montré de la ténacité, tiens, le Badge Roche est à toi ! »" },
    { "Ondine",   "Ondine : « Magnifique, voici le Badge Cascade ! Continue de surfer sur ta passion ! »" },
    { "Major Bob","Major Bob : « Ton électricité brûle d’enthousiasme, voilà le Badge Foudre ! »" },
    { "Sabrina",  "Sabrina : « Ton esprit est affûté comme un Psychopunch ! Le Badge Psy est à toi ! »" },
};
string LeaderGym::getBadge()
{
    return badge;
}

string LeaderGym::getGymnase()
{
    return gymnase;
}
void LeaderGym::interagir() {
    auto it = messagesLeader.find(nom);
    if (it != messagesLeader.end()) {
        cout << it->second << endl;
    } else {
        cout << nom << " te félicite  pour ta victoire !" << endl;
    }
}