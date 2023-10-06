#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    struct stat file_info;

    // Use stat to retrieve file information
    if (stat(file_path, &file_info) == -1) {
        perror("stat");
        return 1;
    }

    // Check file type
    if (S_ISREG(file_info.st_mode)) {
        printf("%s is a regular file.\n", file_path);
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("%s is a directory.\n", file_path);
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("%s is a symbolic link.\n", file_path);
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("%s is a named pipe (FIFO).\n", file_path);
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("%s is a socket.\n", file_path);
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("%s is a character device.\n", file_path);
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("%s is a block device.\n", file_path);
    } else {
        printf("%s is an unknown or unsupported file type.\n", file_path);
    }

    return 0;
}

