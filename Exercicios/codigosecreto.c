#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int v = 0;

void tratasinal(int s){

    printf("Recebi %d\n", s);
    
    if(s == SIGINT)
        v=1;

    else if(s == SIGUSR2 && v == 1)
        v=2;
    
    else if(s == SIGTERM && v == 2){
        printf("Senha acionada\n");
        v=3;
    }
    else if(s == SIGUSR1 && v == 3){
        printf("Tchau\n");
        exit(0);
    }
    else
        v = 0;
}

int main(void){
    
    signal(SIGUSR1, tratasinal);
    signal(SIGUSR2, tratasinal);
    signal(SIGTERM, tratasinal);
    signal(SIGINT, tratasinal);
    while(1)
        pause();
    return 0;
}