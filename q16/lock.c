/*
Question: Write a program to perform mandatory locking. 
    - Implement write lock 
*/

#include <unistd.h>    // Imports for `fcntl`
#include <fcntl.h>     // Imports for `fcntl`, `open`
#include <sys/types.h> // Import for `open`
#include <sys/stat.h>  // Import for `open`
#include<stdio.h>
void main(int argc, char *argv[])
{

    char *filename;
    struct flock lock, lockStatus;
    int fileDescriptor;

    if (argc != 2)
        printf("Pass the file name to be locked as the argument!");
    else
    {
        filename = argv[1];

        // Defining lock paramaters
        lock.l_type = F_WRLCK;    // Write lock
        lock.l_whence = SEEK_SET; // Seek to start of the file
        lock.l_start = 0;         // Lock from start of the file
        lock.l_len = 0;           // Locks the entire file
        lock.l_pid = getpid();

        // Copying lock contents, used for checking if a lock has already been placed on the file
        lockStatus = lock;

        // Opening the file
        fileDescriptor = open(filename, O_RDWR);

        // Checking file lock status
        fcntl(fileDescriptor, F_GETLK, &lockStatus);

        if (lockStatus.l_type == F_WRLCK){ // File already has a write lock 
       // sleep(100);
            printf("File already locked for writing\n");
            sleep(100);
            }
        else if (lockStatus.l_type == F_RDLCK) // File already has a read lock
            printf("File already locked for reading\n");
        else
        {
            // Applying lock
            fcntl(fileDescriptor, F_SETLK, &lock);
            printf("File is now locked for writing\n");
            
        }

        // pause();  // Used for testing purposes, prevents the program from terminating
    }
}
