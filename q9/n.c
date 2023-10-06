#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    struct stat file_info;

    if (stat(filename, &file_info) == -1) {
        perror("Error getting file information");
        return 1;
    }

    printf("File Information for: %s\n", filename);
    printf("a. Inode: %lu\n", (unsigned long)file_info.st_ino);
    printf("b. Number of Hard Links: %lu\n", (unsigned long)file_info.st_nlink);
    printf("c. UID: %u\n", file_info.st_uid);
    printf("d. GID: %u\n", file_info.st_gid);
    printf("e. Size: %ld bytes\n", (long)file_info.st_size);
    printf("f. Block Size: %ld bytes\n", (long)file_info.st_blksize);
    printf("g. Number of Blocks: %ld\n", (long)file_info.st_blocks);

    // Convert time to a human-readable format
    char access_time[20];
    char modify_time[20];
    char change_time[20];

    strftime(access_time, sizeof(access_time), "%Y-%m-%d %H:%M:%S", localtime(&file_info.st_atime));
    strftime(modify_time, sizeof(modify_time), "%Y-%m-%d %H:%M:%S", localtime(&file_info.st_mtime));
    strftime(change_time, sizeof(change_time), "%Y-%m-%d %H:%M:%S", localtime(&file_info.st_ctime));

    printf("h. Time of Last Access: %s\n", access_time);
    printf("i. Time of Last Modification: %s\n", modify_time);
    printf("j. Time of Last Change: %s\n", change_time);

    return 0;
}

