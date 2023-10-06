#include <unistd.h> // for read and write functions

int main() {
    char *buffer; // Buffer to read input
    ssize_t bytesRead; // To store the number of bytes read

    // Infinite loop to continuously read from STDIN and write to STDOUT
   // while (1) {
        // Read from STDIN (file descriptor 0) into the buffer
        bytesRead = read(0, buffer, sizeof(buffer));

        // Check if read encountered an error or reached EOF
        if (bytesRead <= 0) {
            //break; // Exit the loop
        }

        // Write the contents of the buffer to STDOUT (file descriptor 1)
        write(1, buffer, bytesRead);
   // }

    return 0;
}

