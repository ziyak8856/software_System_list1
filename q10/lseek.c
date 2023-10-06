#include<stdio.h>
#include <fcntl.h>
 #include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>
int main(){
int fd=open("ziya", O_RDWR);
char buf[10]="1234567890";
ssize_t len=write(fd, &buf, sizeof(buf));
 off_t seek_result = lseek(fd, 10, SEEK_CUR);

    if (seek_result == (off_t)-1) {
        perror("Error seeking in the file");
        close(fd);
        exit(1);
    } else {
        printf("lseek returned: %ld\n", seek_result);
    }

char buff[10]="1112131415";
write(fd, &buff, sizeof(buff));

}


    
