#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int priority;

    // Get the current priority of the process
    priority = getpriority(PRIO_PROCESS, 0);
    if (priority == -1) {
        perror("getpriority");
        return 1;
    }

    printf("Current priority: %d\n", priority);

    // Modify the priority using nice (increase priority)
    if (nice(10) == -1) {
        perror("nice");
        return 1;
    }

    // Get the updated priority
    priority = getpriority(PRIO_PROCESS, 0);
    if (priority == -1) {
        perror("getpriority");
        return 1;
    }

    printf("New priority: %d\n", priority);

    return 0;
}

