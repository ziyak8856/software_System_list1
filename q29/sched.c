#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
    int policy;
    struct sched_param param;

    // Get the current scheduling policy
    policy = sched_getscheduler(0);  // 0 represents the calling process (self)

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy:\n");
    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Modify the scheduling policy to SCHED_FIFO
    param.sched_priority = 99;  // Set the priority (0-99) for SCHED_FIFO

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("New scheduling policy: SCHED_FIFO\n");

    

    return 0;
}

