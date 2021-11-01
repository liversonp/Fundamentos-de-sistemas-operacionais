# Arquivos Idênticos

## Tarefa

A sua tarefa é determinar se os arquivos passados como argumento para o seu programa são iguais ou diferentes.

Para determinar se arquivos são iguais ou diferentes você deve comparar todos os bytes dos dois arquivos. E, claro, se os tamanhos forem diferentes você já pode considerar que os arquivos são diferentes.

Para tratar os parâmetros você deve utilizar os parâmetros argc e argv, da main. A maneira mais comum é declarando a sua função principal da seguinte maneira:

    int main(int argc,char **argv)
    {
    }

## Entrada

O seu programa será invocado com parâmetros na linha de comando, que representam arquivos, por exemplo:

    ./solucao arquivo1 arquivo2 arquivo3

Você pode considerar que serão passados até 2000 arquivos como argumento para o seu programa.

Cada arquivo pode conter um tamanho que varia de 1 byte até 300
MegaBytes. E cada arquivo pode ser tanto binário como de texto.

## Saída

Para cada par você deverá imprimir os nomes dos arquivos e a string iguais quando os arquivos forem idênticos e diferentes se tiverem ao menos 1 byte diferente.

## Exemplos

### Exemplo de entrada 1

    ./solucao /bin/ls /bin/grep /bin/bash

### Saída para o exemplo 1

    /bin/ls /bin/grep diferentes
    /bin/ls /bin/bash diferentes
    /bin/grep /bin/bash diferentes

### Exemplo de entrada 2

    date > /tmp/hora
    cp /tmp/hora /tmp/hora2
    date -R > /tmp/hora3
    ./solucao /tmp/hora /tmp/hora2 /tmp/hora3 /bin/bash

### Saída para o exemplo 2

    /tmp/hora /tmp/hora2 iguais
    /tmp/hora /tmp/hora3 diferentes
    /tmp/hora /bin/bash diferentes
    /tmp/hora2 /tmp/hora3 diferentes
    /tmp/hora2 /bin/bash diferentes
    /tmp/hora3 /bin/bash diferentes

### Exemplo de entrada 3

    echo a > /tmp/a
    echo b > /tmp/b
    echo -n a > /tmp/an
    ./solucao /tmp/a /tmp/b /tmp/an

### Saída para o exemplo 3

    /tmp/a /tmp/b diferentes
    /tmp/a /tmp/an diferentes
    /tmp/b /tmp/an diferentes

## DICA

1. A dica importante para gerar a saída na ordem esperada é fixar um arquivo e percorrer todos os arquivos para frente dele (pois vetor argv é indexado de 1 até N , o que simplifica)

2. Você também deve se familiarizar com as funções ftell(3); fseek(3); fread(3)