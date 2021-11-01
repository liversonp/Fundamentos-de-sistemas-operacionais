# Procurando pseudo-aleatórios modulados

## Preâmbulo

A pacata cidade de South Park nada de pacata tem. Professor Chaos está aterrorizando mais uma vez! Ele busca o que ninguém jamais procurou, as ocorrências de alguns números pseudo-aleatórios modulares!

O desejo de professor Chaos é muito simples. Ele possui duas sementes para geração de números pseudo-aleatórios e precisa saber quantas ocorrências de alguns números ocorrem a cada 100000 (isso mesmo cem mil) gerações de números pseudo-aleatórios para as duas sementes que ele possui.

## Entrada

A entrada possui um único caso de teste contendo um número indeterminado de linhas.

A primeira possui dois números inteiros sem sinal, S1 e S2, representanto, respectivamente, a primeira semente e a segunda semente.

- Use rand_r() para gerar os números pseudo-aleatórios

Depois da primeira linha existirão diversas linhas contendo dois inteiros M_i e B_i, representando, respectivamente, MÓDULO (em C representado pelo sinal %) e o número que seja se procurar.

## Saída

Para cada linha contendo M_i e B_i você deve responder quantas ocorrências de B_i aconteceram para cada um dos 200000 números (100000 de cada semente) pseudo-aleatórios módulo M_i.

## TAREFA

Você já deve ter percebido que esse problema talvez funcione mais rapidamente se for utilizado o conceito de threads e semáforos.

## Limites

- 0 \leq S1 \leq S2 \leq 2^{31}
- 0 < B_i < M_i \leq 2^{31}
- Sabemos também que não haverão mais de 2000 perguntas

## Exemplos

### Exemplo de entrada 1

    100 200
    8 7
    256 7
    1000000 533

### Saída para o exemplo 1

    24961
    734
    0

### Exemplo de entrada 2

    5270 22136
    705 416
    604 478
    318 316
    583 163
    344 137
    353 129
    762 703
    550 124
    249 49
    351 237

### Saída para o exemplo 2

    293
    350
    600
    319
    575
    558
    254
    359
    831
    563

### Exemplo de entrada 3

    27809 12061
    365 19
    975 42
    525 154
    18 0
    384 236
    291 27
    950 785
    290 141
    183 20
    904 268

### Saída para o exemplo 3

    544
    190
    399
    11109
    525
    657
    202
    698
    1061
    252

### Exemplo de entrada 4

    3732 28201
    15 4
    334 311
    715 341
    147 43
    403 66
    307 186
    384 236
    309 56
    185 145
    394 218

### Saída para o exemplo 4

    13355
    613
    276
    1289
    511
    644
    507
    650
    1081
    504