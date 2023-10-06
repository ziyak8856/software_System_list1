#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <unistd.h>
int main(){
       int t= mknod("fifo");
       if(t==-1)printf("failo");
else printf("suc");
}
