#pragma once
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class History{
    private:
        vector<char*> history;
    public:
        History();
        ~History();

        void addCmdtoHistory(const char* cmd);
        void printHistory();
};

