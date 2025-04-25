#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon(const string& n, const vector<Type>& t, int h, const string& att, const int puiss):
nom(n), type(t), hp(h), attaque(att), puissance(puiss){}

void Pokemon::attaquer(Pokemon* cible)
{
    cout<<nom<<"utilise "<< attaque<<endl;
    cible->subirdegat(type[0].getNom(), puissance);

}
void Pokemon::subirdegat(const string& typeattaque, int degat)
{
    hp=hp-degat; 
    if(hp<=0)
    {
        cout<<nom<<"subit"<< degat<<"degat. Hp restant : "<<hp<<endl;

    }

}
string Pokemon::getNom()
{
    return nom;

}

int Pokemon::getHp()
{
    return hp;
}
    

