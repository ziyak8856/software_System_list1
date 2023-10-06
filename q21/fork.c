#include <stdio.h>
#include <unistd.h>

int main() {
    // Create a child process
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork"); // Forking failed
        return 1;
    } else if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process ID: %d\n", getpid());
    } else {
        // This code is executed by the parent process
        printf("Parent process ID: %d\n", getpid());
        printf("Child process ID (from parent): %d\n", child_pid);
    }

    return 0;
}

