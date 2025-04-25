#include <iostream>
#include <string>
#include <vector>
#include "Entraineur.h"
using namespace std;

class LeaderGymm :public Entraineur
{
    private:
    string badge;
    string gymnase;

    public:
    LeaderGym(string nom, string b, string gym);
    string getBadge();
    string getGymnase();
}