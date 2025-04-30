#pragma once
#include <string>
#include <vector>
#include <map>
#include "Type.h"

std::vector<std::string> split(const std::string& s, char delim);
std::map<std::string, Type> chargerTypesDepuisCSV(const std::string& chemin);