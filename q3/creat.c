 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include<stdio.h>
       int main(){
       int fd= creat("new", S_IRWXU);
         if(fd==-1)printf("error");
   else printf("the file des val:%d",fd);
}
