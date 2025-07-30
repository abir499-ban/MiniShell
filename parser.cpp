#include "parser.h"


vector<char*> parseInput(const string& input){
    stringstream ss(input);
    string token;
    vector<char*> args;

    while(ss >> token){
        char* cStr = new char[token.length() + 1];
        strcpy(cStr , token.c_str());
        args.push_back(cStr);
    }

    args.push_back(nullptr);
    return args;
}

void freeArgs(vector<char*>& args){
    for(char* ch : args){
        if(ch != nullptr) delete[] ch;
    }
}