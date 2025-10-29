#pragma once
#include<unistd.h>
#include<cstring>
#include<fcntl.h>
#include<cstdio>
#include<vector>

using namespace std;

bool handle_redirection(vector<char*>& args);
