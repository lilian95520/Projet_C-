#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Entraineur.h"
#include "CSVLoader.h"
using namespace std;

int main()
{
    
    // //vector<Type> type={feu};
    // //Pokemon* Salameche =new Pokemon("Salameche", type, 40, "boule de feu", 40);
    // cout<<Salameche->getNom()<<" a "<< Salameche->getHp()<< endl;
    // Pokemon* Bulbizare =new Pokemon("Bulbizare", type, 60, "herbe", 40);
    // cout<<Bulbizare->getNom()<<" a "<< Bulbizare->getHp()<< endl;
    // Bulbizare->attaquer(Salameche);
    // Entraineur Paul ("Paul");
    // cout<<Paul.getNom()<< endl;
    // cout<<Paul.getNbPokemon()<< endl;
    // Paul.ajouterPokemon(Salameche);
    // cout<<Paul.getNbPokemon()<< endl;
    // delete Salameche;
    // delete Bulbizare;

    auto types=chargerTypesDepuisCSV("Donnees/types.csv");
    for(const auto& pair:types)
    {
        string nom=pair.first;
        Type type=pair.second;
        cout<<"_"<<nom<<endl;
    }
    string attaque = "Eau";
    string cyble="Feu";
    float mult=types[cyble].getMultiContre(attaque);
    cout<<mult<<endl;
    

    return 0;


}
 