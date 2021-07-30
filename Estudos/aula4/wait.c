#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void fazoqueofilhofaz();

void fazoqueopaifaz(){
    printf("%d: eu sou o pai\n", getpid());
    pid_t p;
    p = fork();
    if(p == 0){
        fazoqueofilhofaz();
    }
    int ret;
    p=wait(&ret);
    printf("Filho %d terminou com %d, tambem vou\n", p, WEXITSTATUS(ret));
    p=wait(&ret);
    printf("Filho %d terminou com %d, tambem vou\n", p, WEXITSTATUS(ret));
    exit(0);
}

void fazoqueofilhofaz(){
    printf("%d: eu sou o filho e meu pai eh: %d\n", getpid(), getppid());
    sleep(1);
    printf("%d: eu sou o filho e meu pai eh: %d\n", getpid(), getppid());
    exit(3);
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
    
    //sleep(20);
}   