#include "history.h"


History :: History(){}
void History :: addCmdtoHistory(const char* cmd){
    char* cmdCopy = new char[strlen(cmd) + 1];
    strcpy(cmdCopy, cmd);
    history.push_back(cmdCopy);
}

void History :: printHistory(){
    for(char* cmd : history){
        cout<<cmd<<endl;
    }
}

History :: ~History(){
    for(char * cmd : history){
        delete[] cmd;
    }
}