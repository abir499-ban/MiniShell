#include <vector>
#include <sys/wait.h>
#include <iostream>
#include <cstring>
#include "parser.h"
#include "cd.h"
#include "history.h"
#include "preParser/preParser.h"

using namespace std;

int main()
{
    History h = History();
    while (true)
    {
        cout << "Welcome to MiniShell>" << endl;
        string input;
        getline(cin, input);

        if (input == "exit")
        {
            break;
        }

        vector<Chain> chainCommands = parseCommands_accTo_op(input);
        int lastExitCode = 0;

        for (Chain &c : chainCommands)
        {
            vector<char *> args = parseInput(c.commands);

            h.addCmdtoHistory(args[0]);

            if (strcmp(args[0], "cd") == 0)
            {
                handle_cd_cmd(args);
                freeArgs(args);
                if(c.op == "||") break;
                lastExitCode = 0;
                continue;
            }
            else if (strcmp(args[0], "history") == 0)
            {
                h.printHistory();
                freeArgs(args);
                if(c.op == "||") break;
                lastExitCode = 0;
                continue;
            }

            pid_t pid = fork();

            if (pid < 0)
            {
                perror("Fork failed");
                freeArgs(args);
                lastExitCode = 1;
                // exit(1);
            }
            else if (pid == 0)
            {
                cout << "Child process with parent pid " << getppid() << " and pid " << getpid() << " with command : " << args[0] << endl;
                if (execvp(args[0], args.data()) == -1)
                {
                    perror("Error executing command");
                    freeArgs(args);
                    exit(1); //this sets the exit status to 1 , and the parent collects the exit status of the child as 1.
                }
            }
            else
            {
                cout << "Parent process" << getpid() << endl;
                int status;
                waitpid(pid , &status , 0);
                lastExitCode = WEXITSTATUS(status);
                freeArgs(args);
            }

            if(c.op == "&&" && lastExitCode != 0) break;
            if(c.op == "||" && lastExitCode == 0) break;
        }
    }
    exit(0);
}