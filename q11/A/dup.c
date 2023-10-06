#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(){
   int fd=open("d",O_RDWR|O_APPEND);
   int dfd=dup(fd);
   char buffer[]="ziya";
   write(dfd,&buffer,strlen(buffer));
   char buf[]="khan";
   write(fd,&buf,strlen(buf));
   
   
   }
   
