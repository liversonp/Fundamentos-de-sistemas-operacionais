#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void fazoqueopaifaz(){
    printf("%d: eu sou o pai\n", getpid());
    sleep(10);
    exit(0);
}

void fazoqueofilhofaz(){
    printf("%d: eu sou o filho e meu pai eh: %d\n", getpid(), getppid());
    sleep(15);
    printf("%d: eu sou o filho e meu pai eh: %d\n", getpid(), getppid());
}

int main(){
    pid_t p;
    p=fork();
    if(p > 0)
        fazoqueopaifaz();
    
    else if(p == 0)
        fazoqueofilhofaz();
    
    else
        printf("o fork falhou\n");
    
    sleep(20);
}   