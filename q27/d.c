#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};

    if (execv("/bin/ls", args) == -1) {
        perror("execv");
        exit(1);
    }

    // This code will not be reached if execv is successful
    printf("This won't be printed because of execv\n");

    return 0;
}

