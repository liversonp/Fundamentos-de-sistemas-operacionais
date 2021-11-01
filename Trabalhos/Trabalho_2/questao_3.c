#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 200000

struct threadparam{
    int ini;
    int fim;
    int quero;
    int mod;
    pthread_t tid;
};

sem_t semaforo;

int vetor[N];

int soma;

void preenche(){
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    for(int i =0;i<N/2;++i){
        vetor[i] = rand_r(&s1);
        vetor[i+(N/2)] = rand_r(&s2);
    }
}

void *calculathread(void* arg){
    int ini = ((struct threadparam*)arg)->ini;
    int fim = ((struct threadparam*)arg)->fim;
    int module = ((struct threadparam*)arg)->mod;
    int desejado = ((struct threadparam*)arg)->quero;
    int somaf = 0;
    
    for(int i = ini;i<fim;i++){
        if(vetor[i]%module == desejado){
            somaf++;
        }
    }
    sem_wait(&semaforo);
    soma += somaf;
    sem_post(&semaforo);    
}

int main(void){
    preenche();
    int n1,n2;
    struct threadparam t1,t2;
    t1.ini = 0;
    t1.fim = N/2;

    t2.ini = N/2;
    t2.fim = N;
    sem_init(&semaforo, 0, 1);
    
    while(scanf("%d %d", &n1, &n2) != EOF){
        soma = 0;
        t1.mod = n1;
        t1.quero = n2;
        
        t2.mod = n1;
        t2.quero = n2; 
        
        pthread_create(&t1.tid, NULL, calculathread, (void*)&t1);
        pthread_create(&t2.tid, NULL, calculathread, (void*)&t2);
        pthread_join(t1.tid, NULL);
        pthread_join(t2.tid, NULL);
        printf("%d\n", soma);
    }
    return 0;
}