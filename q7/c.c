#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(){
int fd1=open("ziya",O_RDONLY);
int fd2=open("khan",O_WRONLY);
char ch;
while(read(fd1,&ch,1)){
write(fd2,&ch,1);
}
}
