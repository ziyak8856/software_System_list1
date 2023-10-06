#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>

#define FILENAME "records.txt"
#define RECORD_SIZE 256
#define NUM_RECORDS 3

void write_record(int record_num, const char* data) {
    int fd = open(FILENAME, O_RDWR);
    if (fd == -1) {
        perror("open");
        return;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return;
    }

    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    write(fd, data, strlen(data));

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
    }

    close(fd);
}

void read_record(int record_num) {
    int fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(fd);
        return;
    }

    char data[RECORD_SIZE];
    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    ssize_t bytesRead = read(fd, data, RECORD_SIZE);
    if (bytesRead == -1) {
        perror("read");
    } else {
        data[bytesRead] = '\0';
        printf("Record %d: %s", record_num, data);
    }

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
    }

    close(fd);
}

int main() {
    // Create the file with empty records
    int fd = open(FILENAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    for (int i = 0; i < NUM_RECORDS; i++) {
        char emptyRecord[RECORD_SIZE] = "\n";
        write(fd, emptyRecord, RECORD_SIZE);
    }
    close(fd);

    while (1) {
        int choice;
        printf("Enter 1 to write a record, 2 to read a record, or 3 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int record_num;
            char data[RECORD_SIZE];
            printf("Enter the record number to write (0-2): ");
            scanf("%d", &record_num);
            printf("Enter the data to write: ");
            scanf("%s", data);
            write_record(record_num, data);
            printf("Record written successfully.\n");
        } else if (choice == 2) {
            int record_num;
            printf("Enter the record number to read (0-2): ");
            scanf("%d", &record_num);
            read_record(record_num);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

