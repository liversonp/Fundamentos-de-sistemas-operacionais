// CUIDADO CONTEM LOOPS INFINITOS E O PROGRAMA NAO VAI PARAR COM CTRL C
// para parar em outro terminal rode ps x, veja qual o numero e faca o comando:
// kill 9 <numero do processo>. ex: kill 9 10030

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void fazcoisadefilho(){
    while(1){
        printf("%d, Chamando o pai %d\n", getpid(), getppid());
        kill(getppid(),SIGUSR1);
    }
}

void tratasinal(int s){
    if(s == SIGINT)
        printf("%d: CTRL C cmg\n", getpid());
    else if(s == SIGALRM){
        printf("%d: Alarme\n", getpid());
        alarm(1);
    }
    else
        printf("%d: Sinal recebido\n", getpid());
}

int main(void){
    signal(SIGUSR1, tratasinal);
    signal(SIGUSR2, tratasinal);
    signal(SIGTERM, tratasinal);
    signal(SIGINT, tratasinal);
    signal(SIGALRM, tratasinal);
    
    pid_t p = fork();
    
    if(p == 0)
        fazcoisadefilho();
    while(1)
        pause();


}