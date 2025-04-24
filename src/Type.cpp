#include <iostream>
#include <string>
#include <vector>
#include "Type.h"
using namespace std;




Type::Type (const string& n, const vector<string> faible, const vector<string> resis):
nom(n), flaiblesse(faible), resistance(resis)

float Type::getMultiContre(string typeattaque )
{
    return 1.0;
}
    