#pragma once
#include<cstring>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Chain{
    string commands;
    string op;
};

vector<Chain> parseCommands_accTo_op(string input);