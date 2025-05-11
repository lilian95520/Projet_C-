#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Type.h"
#include "Interagir.h"

using namespace std;

class Pokemon : public Interagir
{
    private: 
    string nom;
    vector<Type> type;
    int hp;
    int maxHp;
    string attaque;
    int puissance;
    

    public: 
    Pokemon(const string& n, const vector<Type>& t, int h, const string& att, const int puiss);
    void afficher() const;
    void attaquer(Pokemon* cible,float coeff);
    void subirdegat(const string& typeattaque, int degat);
    string getNom() const;
    int getHp();
    void soigner();
    string getAttaqueType();
    int getAttaqueDegat();
    vector<Type> getTypes() const;
    void interagir() override;

};