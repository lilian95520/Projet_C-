#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Entraineur.h"
using namespace std;

int main()
{
    Type feu ("feu", "eau", "métal");
    vector<Type> type={feu};
    Pokemon* Pokemon1=new Pokemon("Salameche", type, 40, "boule de feu", 40);
    cout<<Pokemon1->getNom()<<"a "<< Pokemon1->getHp()<< endl;
    delete Pokemon1;

    return 0;

}
 