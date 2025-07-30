#pragma once
#include <cstring>
#include <vector>
#include<sstream>
#include<string>

using namespace std;

vector<char*> parseInput(const string& input);
void freeArgs(vector<char*>& args);