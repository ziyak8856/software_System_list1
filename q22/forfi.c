#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    // Create a child process
    int fd=open("fork",O_RDWR|O_APPEND);
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork"); // Forking failed
        return 1;
    } else if (child_pid == 0) {
        char buff[]="by the child process\n";
        write(fd,&buff,sizeof(buff));
    } else {
        char buff[]="by the parent process\n";
         write(fd,&buff,sizeof(buff));
        
    }

    return 0;
}

