#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Type
{
    private: 
    string nom; 
    vector<string> faiblesse; 
    vector<string> resistance;


    public: 
    Type()=default; 
    Type(const string& n, const vector<string> faible, const vector<string> resis);
    string getNom() const;
    float getMultiContre(string typeattaque);
    
    


};