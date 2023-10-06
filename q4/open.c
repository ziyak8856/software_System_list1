#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Specify the file path of the existing file you want to open or create
    const char* filepath = "zi";

    // Attempt to open the file with O_RDWR and O_EXCL flags
    int fd = open(filepath, O_RDWR|O_CREAT, O_EXCL,666);
    
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    // Write "hello" to the file using fprintf
   
    

    // Close the file when you are done
    close(fd);

    return 0;
}

