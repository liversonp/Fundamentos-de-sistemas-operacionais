#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void tratasinal(int s){
    char falador[11];
    if(scanf(" %s", falador) != 1)exit(0);
    
    if((s == SIGUSR1 && strcmp(falador,"Igor3k") == 0) || (s == SIGUSR2 && strcmp(falador,"Monark") == 0) || (s == SIGINT && strcmp(falador,"Con1") == 0) || (s == SIGTERM && strcmp(falador,"Con2") == 0) || s == SIGALRM && strcmp(falador,"Silencio") == 0){
        printf("Certo\n");
    }
    else if(falador[0] == '\0'){
        exit(0);
    }
    else{
        printf("Erro\n");
    }
}

int main(void){
    
    signal(SIGUSR1, tratasinal);
    signal(SIGUSR2, tratasinal);
    signal(SIGTERM, tratasinal);
    signal(SIGINT, tratasinal);
    signal(SIGALRM, tratasinal);
    while(1)
        pause();
    return 0;
}