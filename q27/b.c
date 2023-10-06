#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Use execlp to execute the 'ls -Rl' command
    if (execlp("ls", "ls", "-Rl", NULL) == -1) {
        perror("execlp");
        return 1;
    }

    // This code will not be executed because execlp replaces the current process
    printf("This message will not be printed.\n");

    return 0;
}

