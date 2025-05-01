#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Type.h"
using namespace std;

class Pokemon
{
    private: 
    string nom;
    vector<Type> type;
    int hp;
    string attaque;
    int puissance;
    

    public: 
    Pokemon(const string& n, const vector<Type>& t, int h, const string& att, const int puiss);
    void afficher() const;
    void attaquer(Pokemon* cible,float coeff);
    void subirdegat(const string& typeattaque, int degat);
    string getNom() const;
    int getHp();
    string getAttaqueType();
    int getAttaqueDegat();
    vector<Type> getTypes() const;



};