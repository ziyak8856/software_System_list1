#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};

    if (execvp("ls", args) == -1) {
        perror("execvp");
        exit(1);
    }

    // This code will not be reached if execvp is successful
    printf("This won't be printed because of execvp\n");

    return 0;
}

