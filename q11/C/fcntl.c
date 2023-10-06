#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main() {
    // Open a file for appending
   
    int fd = open("fcntl", O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor
    int dup= fcntl(fd, F_DUPFD, 0);
    if (dup== -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    // Append to the file using the original and duplicated descriptors
    char message []= "This is a test message.\n";
    int write_result = write(fd, message, strlen(message));
    if (write_result == -1) {
        perror("Error writing to the file");
        close(fd);
        close(dup);
        return 1;
    }

    write_result = write(dup, message, strlen(message));
    if (write_result == -1) {
        perror("Error writing to the duplicated descriptor");
        close(fd);
        close(dup);
        return 1;
    }

    // Close the file descriptors
    close(fd);
    close(dup);

    // Check if the file is updated properly
    int file = open("fcntl", O_RDONLY);
    if (file == -1) {
        perror("Error opening file for reading");
        return 1;
    }

    char buffer[1024];
    while (read(file,&buffer,sizeof(buffer))) {
        printf("%s", buffer);
    }

    close(file);

    return 0;
}

