#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Entraineur
{
    private: 
    string nom; 
    vector<Pokemon> list_Pokemon[5];

    public:
    Entraineur(string n, Pokemon listP[]);
    string getNom();
    Pokemon getList();
    int getNbPokemon();


}