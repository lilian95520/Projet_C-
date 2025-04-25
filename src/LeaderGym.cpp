
#include <iostream>
#include <string>
#include <vector>
#include "LeaderGym.h"
using namespace std;

LeaderGym::LeaderGym(string nom, string b, string gym):
Entraineur(nom), badge(b), gymnase(gym){}

string LeaderGym::getBadge()
{
    return badge;
}

string LeaderGym::getGymnase()
{
    return gymnase;
}
