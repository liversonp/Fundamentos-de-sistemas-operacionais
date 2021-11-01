# Substituição de Páginas - FIFO

Lucas, um jovem aluno de Engenharia de Software, é muito curioso e meticuloso. Recentemente ele aprendeu sobre os algoritmos de substituição de páginas e ficou muito curioso sobre a estratégia de fila.

O professor disse que esta estratégia de substituição de páginas sofre da anomalia de Belady, que alocando mais quadros podemos obter uma maior taxa de page faults.

## Entrada

A entrada é composta por um único caso de teste contendo diversas linhas. A primeira linha possui um número inteiro N ( 3 \leq N \leq 10^5 ), a segunda linha possui N números P_i ( 1 \leq P_i \leq 10^6 ) representando a página que é acessada pelo sistema. A partir da terceira linha uma número inteiro Q (1 \leq Q \leq 10^5) será dado, indicando para quantos quadros a sequência de páginas deve ser testada.

A entrada termina em EOF.

## Saída

Para cada teste de quadros você deverá imprimir uma única linha contendo a quantidade de quadros e de page faults. A última linha deve contar a string Belady detectado ou Sem anomalia caso seja identificado a anomalia de Belady para os testes feitos.

## Exemplos
### Exemplo de entrada 1

    12
    1 2 3 4 1 2 5 1 2 3 4 5
    3
    4

### Saída para o exemplo 1

    3 9
    4 10
    Belady detectado

### Exemplo de entrada 2

    12
    1 2 3 4 1 2 5 1 2 3 4 5
    5
    6

### Saída para o exemplo 2

    5 5
    6 5
    Sem anomalia

### Exemplo de entrada 3

    30
    97 67 24 35 43 69 69 63 4 99 16 49 5 77 8 77 27 58 15 45 45 43 3 30 94 37 17 12 21 184
    6
    5
    11
    9
    3
    16
    7
    19
    14

### Saída para o exemplo 3

    6 27
    5 27
    11 27
    9 27
    3 27
    16 26
    7 27
    19 26
    14 26
    Sem anomalia