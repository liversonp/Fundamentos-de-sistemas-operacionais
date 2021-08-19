#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int exitdofilho=0;

void tratasinal(int s){
    exitdofilho=s;
}

int main(void){
    
    signal(SIGUSR1, tratasinal);
    signal(SIGUSR2, tratasinal);
    pause();
    if(fork()==0)
        exit(0);
    pause();
    wait(NULL);
    pause();
    exit(0);
}