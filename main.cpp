#include<vector>
#include<sys/wait.h>
#include<iostream>
#include<cstring>
#include "parser.h"

using namespace std;



int main(){
    cout<<"Welcome to MiniShell>"<<endl;
    string input;
    getline(cin , input);

    if(input == "exit"){
        exit(0);
    }

    vector<char*> args = parseInput(input);

    pid_t pid = fork();

    if(pid < 0){
        cout<<"Fork Failed"<<endl;
        exit(1);
    }else if(pid == 0){
        cout<<"Child process with pid "<<pid<<" and "<<getpid()<<" with command : "<<args[0]<<endl;
        if(execvp(args[0] , args.data()) == -1){
            perror("Error executing command");
            freeArgs(args);
            exit(1);
        }
    }else{
        cout<<"Parent process"<<getpid()<<endl;
        wait(NULL);
        freeArgs(args);
    }

    
}