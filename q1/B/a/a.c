#include<stdio.h>
#include <unistd.h>
int main(){
    int t=symlink("ziya","softlink");
   if(t==-1)printf("failed");
   else printf("created");
 return 0;
}

