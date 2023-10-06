#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pids[3];

    // Create three child processes
    for (int i = 0; i < 3; i++) {
        child_pids[i] = fork();

        if (child_pids[i] < 0) {
            perror("fork");
            return 1;
        } else if (child_pids[i] == 0) {
            // This code is executed by each child process
            printf("Child process %d (PID: %d) is running.\n", i + 1, getpid());
            sleep(2); // Simulate some work
            printf("Child process %d (PID: %d) is exiting.\n", i + 1, getpid());
            exit(0);
        }
    }

    // Parent process
    printf("Parent process (PID: %d) is waiting for all children...\n", getpid());

    // Wait for all child processes to complete
    for (int i = 0; i < 3; i++) {
        int status;
        waitpid(child_pids[i], &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process %d (PID: %d) has exited with status %d.\n",
                   i + 1, child_pids[i], WEXITSTATUS(status));
        } else {
            printf("Child process %d (PID: %d) has not exited normally.\n",
                   i + 1, child_pids[i]);
        }
    }

    return 0;
}

