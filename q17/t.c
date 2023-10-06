

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    
    int fd, fcntlStatus;
    ssize_t readBytes, writeBytes;
    off_t lseekOffset;
    int buffer;
    struct flock ticketLock;

    fd = open("ticket", O_CREAT | O_RDWR, S_IRWXU);

    if (fd == -1)
        perror("Error while opening the file!");
    else
    {
        ticketLock.l_type = F_WRLCK;
        ticketLock.l_pid = getpid();
        // Lock the entire file
        ticketLock.l_whence = SEEK_SET;
        ticketLock.l_len = 0;
        ticketLock.l_start = 0;

        fcntlStatus = fcntl(fd, F_GETLK, &ticketLock);

        if (fcntlStatus == -1)
            perror("Error while getting lock status!");
        else
        {
            switch (ticketLock.l_type)
            {
            case F_WRLCK:
                // File already has write lock
                printf("The ticket File %s is already locked for writing!\n", ticketFile);
                break;
            case F_RDLCK:
                // File already has a read lock
                printf("The ticket File %s is already locked for reading!\n", ticketFile);
                break;
            default:
                // No lock on the file
                ticketLock.l_type = F_WRLCK;
                fcntlStatus = fcntl(fd, F_SETLKW, &ticketLock);
                if (fcntlStatus == -1)
                    perror("Error while locking the ticket file!");
                else
                {
                    readBytes = read(fd, &buffer, sizeof(int));
                    if (readBytes == -1)
                        perror("Error while reading ticket!");
                    else if (readBytes == 0)
                    {
                        buffer = 1;
                        writeBytes = write(fd, &buffer, sizeof(int));
                        if (writeBytes == -1)
                            perror("Error while writing to ticket!");
                        else
                            printf("Your ticket number is %d\n", buffer);
                    }
                    else
                    {
                        lseekOffset = lseek(fd, 0, SEEK_SET);
                        if (lseekOffset == -1)
                            perror("Error while seeking!");
                        else
                        {
                            buffer += 1;
                            writeBytes = write(fd, &buffer, sizeof(int));
                            printf("Your ticket number is: %d\n", buffer);
                        }
                    }
                    ticketLock.l_type = F_UNLCK;
                    fcntlStatus = fcntl(fd, F_SETLKW, &ticketLock);
                    if (fcntlStatus == -1)
                        perror("Error releasing lock!");
                    else
                        printf("Done!\n");
                }
            }
        }
        close(fileDescriptor);
    }
}
