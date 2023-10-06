#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid < 0) {
        perror("fork"); 
        return 1;
    } else if (child_pid == 0) {
       
        printf("Child process is running.\n");
        sleep(10); // child done now have entry in table
        printf("child process is exiting.\n");
        
    } else {
        
        printf("Parent process is running.\n");
        exit(0); 
        
    }

    return 0;
}

