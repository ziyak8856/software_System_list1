#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t pid=fork();
    if(pid==-1){
        printf("fork failed\n");
    }
    if(pid==0){
        //child process
        sleep(10);
        printf("creating a new session with setsid()\n");
        pid_t newsession=setsid();
        if(newsession==-1){
            printf("creating a new session failed\n");
        }else{
            printf("A new session created\n");
        }
        int changedir=chdir("/");
        if(changedir==-1){
            printf("changeing directory failed\n");
        }else{
            printf("changed the directory to '/'\n");
            while(1){
               sleep(2);
                printf("PID of process is %d\n",getpid());
                printf("the deamon process is running\n");
            }
        }
    }else{
        //parent process
        printf("parent process this will exit..\n"); 
        exit(0);      
    }
}
