#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Type
{
    private: 
    string nom; 
    string faiblesse; 
    string resistance;

    public: 
    Type()=default; 
    Type(const string& n, const string faible, const string resis);
    string getNom();
    float getMultiContre(string typeattaque );
    


};