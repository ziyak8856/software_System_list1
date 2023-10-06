#include<stdio.h>
#include <unistd.h>
int main(){
int t=link("khan","hard");
if(t==-1)printf("fail");
else printf("success");
}
