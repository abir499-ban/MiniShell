#include "redirect.h"

bool handle_redirection(vector<char *> &args)
{
    size_t n = args.size();
    for (size_t i = 0; i < n; i++)
    {
        if ((size_t)i + 1 < n)
        {
            if (strcmp(args[i], ">") == 0)
            {
                const char *fileName = args[i + 1];
                int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if(fd < 0){
                    perror("Error in opening file");
                    return false;
                }
                dup2(fd , STDOUT_FILENO);
                close(fd);


                args.erase(args.begin() + i , args.begin() + i + 2);
                break;
            }
            else if(strcmp(args[i] , "<") == 0){
                int fd = open(args[i+1] , O_RDONLY);
                if(fd < 0){
                    perror("Error in opening file");
                    return false;
                }
                dup2(fd , STDIN_FILENO);
                close(fd);
                args.erase(args.begin() + i , args.begin() + i + 2);
                break;
            }else if(strcmp(args[i] , ">>") == 0){
                int fd = open(args[i+1] ,  O_WRONLY | O_CREAT | O_APPEND);
                if(fd < 0){
                    perror("Error in opening file");
                    return false;
                }
                dup2(fd , STDOUT_FILENO);
                close(fd);
                args.erase(args.begin() + i , args.begin() + i + 2);
                break;
            }
        }
    }

    return true;
}