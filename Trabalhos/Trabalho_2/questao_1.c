#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n,q, qtfaults;
    bool achei = false;
    bool anomalia = false;
    int vpf[] = {0,0};
    int aux;
    char a;
    scanf("%d", &n);
    int* paginas = (int*)malloc(n * sizeof(paginas));
    
    for(int i=0;i<n;++i){
        scanf("%d", &paginas[i]);
    }

    while(scanf("%d", &q) != EOF){
        aux = 0;
        qtfaults = 0;
        int* pfaults = (int*)calloc(q,sizeof(int));
        
        for(int i=0;i<n;++i){
            achei = false;
            if(aux == q){
                    aux = 0;
            }

            for(int j=0;j<q;++j){
                if(paginas[i] == pfaults[j]){
                    achei = true;
                }
            }
            if(!achei){
                    pfaults[aux] = paginas[i];
                    aux++;
                    qtfaults++;
            }
        }

        printf("%d %d\n", q, qtfaults);
        
        if(vpf[0] == 0 && vpf[1] == 0){
            vpf[0] = q;
            vpf[1] = qtfaults;
        }
        else if(q < vpf[0] && qtfaults <= vpf[1]){
            vpf[0] = q;
            vpf[1] = qtfaults;
        }

        else if(vpf[0] < q && vpf[1] < qtfaults){
                anomalia = true;
        }
        free(pfaults);
    }

    if(anomalia){
            printf("Belady detectado\n");
        }
    else{
        printf("Sem anomalia\n");
    }
    return 0;
}