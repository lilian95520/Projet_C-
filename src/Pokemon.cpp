#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon(const string& n, const vector<Type>& t, int h, const string& att, const int puiss):
nom(n), type(t), hp(h),maxHp(h), attaque(att), puissance(puiss){}

void Pokemon::attaquer(Pokemon* cible,float coeff)
{
    cout<<nom<<" utilise "<< attaque<<endl;
    cible->subirdegat(type[0].getNom(), puissance*coeff);

}
void Pokemon::subirdegat(const string& typeattaque, int degat)
{
    hp=hp-degat; 
    if(hp>0)
    {
        cout<<nom<<" subit "<< degat<<" degat. Hp restant : "<<hp<<endl;

    }
    else {
        cout<<nom<< " subit "<< degat<<" degat. Hp restant : "<<hp<<endl;
        cout<<nom<< " est mort "<< endl;
    }

}
string Pokemon::getNom() const
{
    return nom;

}

int Pokemon::getHp()
{
    return hp;
}
    
string Pokemon::getAttaqueType()
{
    return type[0].getNom();
}

int Pokemon::getAttaqueDegat()
{
    return puissance;
}
vector<Type> Pokemon::getTypes() const {
    return type;
}

void Pokemon::soigner() {
    hp = maxHp;
    std::cout << nom << " est soigné ! PV restaurés à " << hp << " / " << maxHp << ".\n";
}

void Pokemon::afficher() const {
    cout << "Pokemon: " << nom
              << " | HP: " << hp
              << " | Type: ";
    for (const auto& t : type)
        cout << t.getNom() << " ";
    cout << "| Attaque: " << attaque
              << " (" << puissance << " dmg)" << std::endl;
}
