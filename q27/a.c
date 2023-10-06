#include <stdio.h>
#include <unistd.h>

int main() {
    // Using execl to execute the ls -Rl command
    //ill list the contents of the directory and all the subdirectores recursively
    if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) {
        perror("execl");
        return 1;
    }

    // The following code is only executed if execl fails
    printf("This won't be reached.\n");
    
    return 0;
}

