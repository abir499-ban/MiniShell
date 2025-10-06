#include <vector>
#include <sys/wait.h>
#include <iostream>
#include <cstring>
#include "parser.h"

using namespace std;

int main()
{
    while (true)
    {
        cout << "Welcome to MiniShell>" << endl;
        string input;
        getline(cin, input);

        if (input == "exit")
        {
            break;
        }

        vector<char *> args = parseInput(input);

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Fork failed");
            freeArgs(args);
            //exit(1);
        }
        else if (pid == 0)
        {
            cout << "Child process with parent pid " << getppid() << " and pid " << getpid() << " with command : " << args[0] << endl;
            if (execvp(args[0], args.data()) == -1)
            {
                perror("Error executing command");
                freeArgs(args);
                exit(1);
            }
        }
        else
        {
            cout << "Parent process" << getpid() << endl;
            wait(NULL);
            freeArgs(args);
        }
    }
    exit(0);
}