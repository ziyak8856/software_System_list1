#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(){
int fd1=open("ziya",O_RDONLY);

char ch;
while(read(fd1,&ch,1)){
write(1,&ch,1);
}
}
