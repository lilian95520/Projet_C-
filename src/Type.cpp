#include <iostream>
#include <string>
#include <vector>
#include "Type.h"
#include <algorithm>
using namespace std;


Type::Type (const string& n, const vector<string> faible, const vector<string> resis):
nom(n), faiblesse(faible), resistance(resis){}

float Type::getMultiContre(string typeattaque )
{
    if(find(faiblesse.begin(),faiblesse.end(),typeattaque)!=faiblesse.end())
    {
        return 2.0f;
    }
    if(find(resistance.begin(),resistance.end(),typeattaque)!=resistance.end())
    {
        return 0.5f;
    }
    return 1.0f;
    
};

string Type::getNom() const
{
    return nom;
}
    