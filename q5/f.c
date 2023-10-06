#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
     while(1)
    {
    creat("s1",0644);
    creat("s2",0644);
    creat("s3",0644);
    creat("s4",0644);
    creat("s5",0644);
    }

    return 0;
}
