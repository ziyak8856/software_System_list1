#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd= creat("ziya",O_RDONLY);
    
    // Open the file
    
    // Use fcntl to get the file status flags
    int flags = fcntl(fd, F_GETFL);
    // Check the file access mode
    if (flags & O_RDONLY) {
        printf("File is opened in read-only mode.\n");
    } else if (flags & O_WRONLY) {
        printf("File is opened in write-only mode.\n");
    } else if (flags & O_RDWR) {
        printf("File  is opened in read-write mode.\n");
    } else {
        printf("File  is opened in an unknown mode.\n");
    }

    // Close the file descriptor
  //  close(file_descriptor);

    return 0;
}

