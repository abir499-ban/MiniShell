## File redirection in MiniShell

Before diving into the concept of file redirection, let us understand a few concepts:
- A file is a resource on the computer stored on disk, whereas file descriptor (FD) is a integer that the kernel gives our process to handle the file ( or any I/O resource ).

### Now how does a terminal knows whom to redirect output?
Each process has some predefined FDs, which points to a particular open resource for IO:
| FD | Formal name | Pointed Resource |
|----------|----------|----------|
| 0 | `STDIN_FILENO` | Standard Input |
| 1 | `STDOUT_FILENO` | Terminal |
| 2  |    `STDERR_FILENO`      |   Terminal       |

now when we do:
`int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);`
- The kernel finds output.txt on disk, it opens it for writing and assigns the  process a new file descriptor that points to the open file.
for eg here `fd = 3`

now `write(1 , "hello" , 5)` -> redirects o/p to fd=1 which is the STDout terminal.
and `write(3, "hello" , 5)` -> redirects o/p to fd=3 which is the output.txt file


### Use of dup2() sys call to duplicate FDs
dup2() is a system call which duplicates FDs or make one FD point to the same resource as another.
Syntax: `dup2(oldfd, newfd)` : duplicates the file descriptor oldfd onto newfd.



Next any function or system call that originally prints or writes to the resource pointed by newfd will now do it to the resource pointed by oldfd, as now newfd points to the same resource as oldfd.

### Closinf FDs:
doing `close(fd)` will tell the kernel that this descriptor pointing to a open resource is to be closed.


