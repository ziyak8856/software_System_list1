#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Define the path to the 'ls' command
    char *command = "/bin/ls";

    // Create an array of command line arguments
    char *args[] = { "ls", "-Rl", NULL };

    // Create an environment variable list
    char *env[] = { NULL };

    // Use execle to execute 'ls -Rl' with specified environment variables
    if (execle(command, "ls", "-Rl", NULL, env) == -1) {
        perror("execle");
        return 1;
    }

    // This code will only be executed if execle fails
    printf("Execle failed!\n");

    return 0;
}

