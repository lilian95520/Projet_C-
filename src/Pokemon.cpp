#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include <map>

using namespace std;

Pokemon::Pokemon(const string& n, const vector<Type>& t, int h, const string& att, const int puiss):
nom(n), type(t), hp(h),maxHp(h), attaque(att), puissance(puiss){}

static const map<string, string> messagesInteraction = {
    { "Salamèche",   "Salamèche flamboie et lance quelques étincelles ! 🔥" },
    { "Carapuce",    "Carapuce sort sa tête et te salue d'un sourire ! 🐢" },
    { "Bulbizarre",  "Bulbizarre gambade joyeusement dans l'herbe ! 🌿" },
    { "Pikachu",     "Pikachu te fait un petit saut et dit \"Pika Pika\" ! ⚡️" },
    { "Évoli",       "Évoli tourne autour de toi avec curiosité ! ✨" },
    { "Mew",      "Mewtwo ferme les yeux et t'envoie une onde psychique apaisante ! 🧠" },
};
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
    cout << nom << " est soigné ! PV restaurés à " << hp << " / " << maxHp << ".\n";
}

void Pokemon::afficher() const {
    cout << "Pokemon: " << nom
              << " | HP: " << hp
              << " | Type: ";
    for (const auto& t : type)
        cout << t.getNom() << " ";
    cout << "| Attaque: " << attaque
              << " (" << puissance << " dmg)" << endl;
}

void Pokemon::interagir() {
    auto it = messagesInteraction.find(nom);
    if (it != messagesInteraction.end()) {
        cout << it->second << std::endl;
    } else {
        cout << nom << " te regarde avec curiosité." << endl;
    }
}
