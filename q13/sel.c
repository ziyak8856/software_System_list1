#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>

int main() {
    fd_set fds;
    struct timeval tv;
    int ret;

    // Initialize the file descriptor set
    //FD_ZERO(&fds);
    //FD_SET(STDIN_FILENO, &fds);

    // Set the timeout to 10 seconds
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    // Use select to wait for input
    //1 max fd to read
    //0from terminal
    ret = select( 1, 0, NULL, NULL, &tv);

    if (ret == -1) {
        perror("select");
        return 1;
    } else if (ret == 0) {
        printf("No data available within 10 seconds.\n");
    } else {
       // if (FD_ISSET(STDIN_FILENO, &fds)) {
            char input[256];
            fgets(input, sizeof(input), stdin);
            printf("Data available within 10 seconds: %s", input);
      //  }
    }

    return 0;
}

