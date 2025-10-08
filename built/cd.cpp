#include "cd.h"


void handle_cd_cmd(const vector<char*> &args){
    if(args.size() < 2){
        perror("missing argument in cd command");
        return;
    }

    const char* path = args[1];
    if(chdir(path) != 0){
        perror("cd command failed");
    }
}