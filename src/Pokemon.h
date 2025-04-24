#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Type.h"
class Pokemon
{
    private: 
    string nom;
    vector<Type> type;
    int hp;
    string attaque;
    int puissance;
    

    public: 
    Pokemon(const string n, const vector<string> t, int h, const string att, const int puiss);
    void attaquer(Pokemon* cible);
    void subirdegat(const string& typeattaque, int degat);
    string getNom();
    int getHp();


};