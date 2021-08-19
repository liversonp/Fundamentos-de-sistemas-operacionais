#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int v = 0;

void tratasinal(int s){
    
    if(s == SIGUSR1){
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }
    else{
        if(v == 2){
            printf("Os incomodados que se mudem, tchau\n");
            exit(0);
        }

        printf("Ai que sono, quero dormir mais um pouco\n");
        v++;
    }
}

int main(void){
    
    signal(SIGUSR1, tratasinal);
    signal(SIGALRM, tratasinal);
    while(1)
        pause();
    return 0;
}