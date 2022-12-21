# BinPackingColumnGeneration

Aluno: Victor José de Sousa Koehler

Matrícula: 20211023501



## Introdução

Neste trabalho são apresentadas implementações de modelos matemáticos para o Problema do Empacotamento (do inglês, Bin Packing), bem como algoritmos e estruturas auxiliares, como requisito da avaliação da disciplina de Tópicos Especiais do Programa de Pós-Graduação em Informática (PPGI) da Universidade Federal da Paraíba (UFPB). Esta implementação possui teor puramente educativo e não deve ser seriamente utilizada em ambientes de produção. Neste relatório são apresentados alguns resultados de experimentos computacionais realizados com esta implementação utilizando um conjunto de instâncias bem conhecido da literatura.

O tempo de execução dos dois métodos implementados são apresentados em suas respectivas colunas: **Gilmore Gomory** e **Kantorovitch**. **INSTANCE** denota a instância testada, **ITEMS** e **CAPACITY** representam a quantidade de itens e a capacidade de cada mochila.


| INSTANCE                     |   ITEMS |   CAPACITY |   Gilmore Gomory |   Kantorovitch |
|:-----------------------------|--------:|-----------:|-----------------:|---------------:|
| ('binpack1.txt', 'u120_00')  |     120 |        150 |         0.090973 |      17.965    |
| ('binpack1.txt', 'u120_01')  |     120 |        150 |         0.03813  |      47.1911   |
| ('binpack1.txt', 'u120_02')  |     120 |        150 |         0.103646 |      41.551    |
| ('binpack1.txt', 'u120_03')  |     120 |        150 |         0.059469 |      49.3892   |
| ('binpack1.txt', 'u120_04')  |     120 |        150 |         0.057601 |      46.8878   |
| ('binpack1.txt', 'u120_05')  |     120 |        150 |         0.067187 |      51.8062   |
| ('binpack1.txt', 'u120_06')  |     120 |        150 |         0.057396 |      49.0138   |
| ('binpack1.txt', 'u120_07')  |     120 |        150 |         0.054257 |      49.3169   |
| ('binpack1.txt', 'u120_08')  |     120 |        150 |         0.0444   |     700.703    |
| ('binpack1.txt', 'u120_09')  |     120 |        150 |         0.03957  |     314.345    |
| ('binpack1.txt', 'u120_10')  |     120 |        150 |         0.063497 |      45.9365   |
| ('binpack1.txt', 'u120_11')  |     120 |        150 |         0.069364 |       4.92785  |
| ('binpack1.txt', 'u120_12')  |     120 |        150 |         0.043311 |      42.395    |
| ('binpack1.txt', 'u120_13')  |     120 |        150 |         0.050715 |       3.88561  |
| ('binpack1.txt', 'u120_14')  |     120 |        150 |         0.104874 |      42.9398   |
| ('binpack1.txt', 'u120_15')  |     120 |        150 |         0.042704 |       7.94146  |
| ('binpack1.txt', 'u120_16')  |     120 |        150 |         0.054152 |       7.92449  |
| ('binpack1.txt', 'u120_17')  |     120 |        150 |         0.037861 |      68.0129   |
| ('binpack1.txt', 'u120_18')  |     120 |        150 |         0.048781 |      53.9512   |
| ('binpack1.txt', 'u120_19')  |     120 |        150 |         0.046597 |     nan        |
| ('binpack2.txt', 'u250_00')  |     250 |        150 |        52.9668   |     nan        |
| ('binpack2.txt', 'u250_01')  |     250 |        150 |         0.108048 |     nan        |
| ('binpack2.txt', 'u250_02')  |     250 |        150 |         0.08306  |     nan        |
| ('binpack2.txt', 'u250_03')  |     250 |        150 |         0.043889 |     nan        |
| ('binpack2.txt', 'u250_04')  |     250 |        150 |         0.07421  |     nan        |
| ('binpack2.txt', 'u250_05')  |     250 |        150 |         0.074309 |     nan        |
| ('binpack2.txt', 'u250_06')  |     250 |        150 |         0.048295 |     nan        |
| ('binpack2.txt', 'u250_07')  |     250 |        150 |         0.092035 |     nan        |
| ('binpack2.txt', 'u250_08')  |     250 |        150 |         0.042469 |     nan        |
| ('binpack2.txt', 'u250_09')  |     250 |        150 |         0.041917 |     nan        |
| ('binpack2.txt', 'u250_10')  |     250 |        150 |         0.056291 |     nan        |
| ('binpack2.txt', 'u250_11')  |     250 |        150 |         0.081845 |     nan        |
| ('binpack2.txt', 'u250_12')  |     250 |        150 |         0.079203 |     nan        |
| ('binpack2.txt', 'u250_13')  |     250 |        150 |         0.061589 |     nan        |
| ('binpack2.txt', 'u250_14')  |     250 |        150 |         0.049292 |     nan        |
| ('binpack2.txt', 'u250_15')  |     250 |        150 |         0.040462 |     nan        |
| ('binpack2.txt', 'u250_16')  |     250 |        150 |         0.058166 |     nan        |
| ('binpack2.txt', 'u250_17')  |     250 |        150 |         0.042961 |     nan        |
| ('binpack2.txt', 'u250_18')  |     250 |        150 |         0.047062 |     nan        |
| ('binpack2.txt', 'u250_19')  |     250 |        150 |         0.049543 |     nan        |
| ('binpack3.txt', 'u500_00')  |     500 |        150 |         0.081512 |     nan        |
| ('binpack3.txt', 'u500_01')  |     500 |        150 |         0.070658 |     nan        |
| ('binpack3.txt', 'u500_02')  |     500 |        150 |         0.049318 |     nan        |
| ('binpack3.txt', 'u500_03')  |     500 |        150 |         0.047328 |     nan        |
| ('binpack3.txt', 'u500_04')  |     500 |        150 |         0.046924 |     nan        |
| ('binpack3.txt', 'u500_05')  |     500 |        150 |         0.062588 |     nan        |
| ('binpack3.txt', 'u500_06')  |     500 |        150 |         0.04907  |     nan        |
| ('binpack3.txt', 'u500_07')  |     500 |        150 |         0.093328 |     nan        |
| ('binpack3.txt', 'u500_08')  |     500 |        150 |         0.125264 |     nan        |
| ('binpack3.txt', 'u500_09')  |     500 |        150 |         0.04867  |     nan        |
| ('binpack3.txt', 'u500_10')  |     500 |        150 |         0.045862 |     nan        |
| ('binpack3.txt', 'u500_11')  |     500 |        150 |         0.059113 |     nan        |
| ('binpack3.txt', 'u500_12')  |     500 |        150 |         0.071527 |     nan        |
| ('binpack3.txt', 'u500_13')  |     500 |        150 |         0.063561 |     nan        |
| ('binpack3.txt', 'u500_14')  |     500 |        150 |         0.087223 |     nan        |
| ('binpack3.txt', 'u500_15')  |     500 |        150 |         0.057332 |     nan        |
| ('binpack3.txt', 'u500_16')  |     500 |        150 |         0.075889 |     nan        |
| ('binpack3.txt', 'u500_17')  |     500 |        150 |         0.047596 |     nan        |
| ('binpack3.txt', 'u500_18')  |     500 |        150 |         0.052023 |     nan        |
| ('binpack3.txt', 'u500_19')  |     500 |        150 |         0.064252 |     nan        |
| ('binpack4.txt', 'u1000_00') |    1000 |        150 |         0.18882  |     nan        |
| ('binpack4.txt', 'u1000_01') |    1000 |        150 |         0.086931 |     nan        |
| ('binpack4.txt', 'u1000_02') |    1000 |        150 |         0.058907 |     nan        |
| ('binpack4.txt', 'u1000_03') |    1000 |        150 |         0.057713 |     nan        |
| ('binpack4.txt', 'u1000_04') |    1000 |        150 |         0.065126 |     nan        |
| ('binpack4.txt', 'u1000_05') |    1000 |        150 |         0.100054 |     nan        |
| ('binpack4.txt', 'u1000_06') |    1000 |        150 |         0.147776 |     nan        |
| ('binpack4.txt', 'u1000_07') |    1000 |        150 |         0.093311 |     nan        |
| ('binpack4.txt', 'u1000_08') |    1000 |        150 |         0.060071 |     nan        |
| ('binpack4.txt', 'u1000_09') |    1000 |        150 |         0.054396 |     nan        |
| ('binpack4.txt', 'u1000_10') |    1000 |        150 |         0.057439 |     nan        |
| ('binpack4.txt', 'u1000_11') |    1000 |        150 |         0.081262 |     nan        |
| ('binpack4.txt', 'u1000_12') |    1000 |        150 |         0.069096 |     nan        |
| ('binpack4.txt', 'u1000_13') |    1000 |        150 |         0.078332 |     nan        |
| ('binpack4.txt', 'u1000_14') |    1000 |        150 |         0.053887 |     nan        |
| ('binpack4.txt', 'u1000_15') |    1000 |        150 |         0.081537 |     nan        |
| ('binpack4.txt', 'u1000_16') |    1000 |        150 |         0.055421 |     nan        |
| ('binpack4.txt', 'u1000_17') |    1000 |        150 |         0.085673 |     nan        |
| ('binpack4.txt', 'u1000_18') |    1000 |        150 |         0.07758  |     nan        |
| ('binpack4.txt', 'u1000_19') |    1000 |        150 |         0.070053 |     nan        |
| ('binpack5.txt', 't60_00')   |      60 |        100 |         0.071555 |       0.130344 |
| ('binpack5.txt', 't60_01')   |      60 |        100 |         0.129628 |       0.077341 |
| ('binpack5.txt', 't60_02')   |      60 |        100 |         0.042761 |       0.07444  |
| ('binpack5.txt', 't60_03')   |      60 |        100 |         0.070776 |       0.071126 |
| ('binpack5.txt', 't60_04')   |      60 |        100 |         0.038988 |       0.084586 |
| ('binpack5.txt', 't60_05')   |      60 |        100 |         0.037868 |       0.080578 |
| ('binpack5.txt', 't60_06')   |      60 |        100 |         0.041369 |       0.082125 |
| ('binpack5.txt', 't60_07')   |      60 |        100 |         0.038827 |       0.071799 |
| ('binpack5.txt', 't60_08')   |      60 |        100 |         0.039592 |       0.074438 |
| ('binpack5.txt', 't60_09')   |      60 |        100 |         0.101237 |       0.076417 |
| ('binpack5.txt', 't60_10')   |      60 |        100 |         0.074892 |       0.079483 |
| ('binpack5.txt', 't60_11')   |      60 |        100 |         0.035685 |       0.077286 |
| ('binpack5.txt', 't60_12')   |      60 |        100 |         0.087391 |       0.074075 |
| ('binpack5.txt', 't60_13')   |      60 |        100 |         0.035067 |       0.079986 |
| ('binpack5.txt', 't60_14')   |      60 |        100 |         0.092899 |       0.080363 |
| ('binpack5.txt', 't60_15')   |      60 |        100 |         0.037258 |       0.079078 |
| ('binpack5.txt', 't60_16')   |      60 |        100 |         0.037382 |       0.081585 |
| ('binpack5.txt', 't60_17')   |      60 |        100 |         0.040045 |       0.079024 |
| ('binpack5.txt', 't60_18')   |      60 |        100 |         0.04574  |       0.077116 |
| ('binpack5.txt', 't60_19')   |      60 |        100 |         0.126976 |       0.081311 |
| ('binpack6.txt', 't120_00')  |     120 |        100 |         0.070709 |       0.312068 |
| ('binpack6.txt', 't120_01')  |     120 |        100 |         0.052012 |       0.258961 |
| ('binpack6.txt', 't120_02')  |     120 |        100 |         0.163798 |       0.248437 |
| ('binpack6.txt', 't120_03')  |     120 |        100 |         0.051032 |       0.260318 |
| ('binpack6.txt', 't120_04')  |     120 |        100 |         0.045389 |       0.270058 |
| ('binpack6.txt', 't120_05')  |     120 |        100 |         0.103804 |       0.279685 |
| ('binpack6.txt', 't120_06')  |     120 |        100 |         0.045328 |       0.25206  |
| ('binpack6.txt', 't120_07')  |     120 |        100 |         0.065421 |       0.256482 |
| ('binpack6.txt', 't120_08')  |     120 |        100 |         0.089986 |       0.284562 |
| ('binpack6.txt', 't120_09')  |     120 |        100 |         0.098864 |       0.259239 |
| ('binpack6.txt', 't120_10')  |     120 |        100 |         0.041266 |       0.279035 |
| ('binpack6.txt', 't120_11')  |     120 |        100 |         0.047379 |       0.259442 |
| ('binpack6.txt', 't120_12')  |     120 |        100 |         0.0373   |       0.284846 |
| ('binpack6.txt', 't120_13')  |     120 |        100 |         0.128324 |       0.259728 |
| ('binpack6.txt', 't120_14')  |     120 |        100 |         0.039083 |       0.259412 |
| ('binpack6.txt', 't120_15')  |     120 |        100 |         0.124558 |       0.256568 |
| ('binpack6.txt', 't120_16')  |     120 |        100 |         0.080472 |       0.262437 |
| ('binpack6.txt', 't120_17')  |     120 |        100 |         0.133815 |       0.254095 |
| ('binpack6.txt', 't120_18')  |     120 |        100 |         0.03286  |       0.275795 |
| ('binpack6.txt', 't120_19')  |     120 |        100 |         0.045967 |       0.285612 |
| ('binpack7.txt', 't249_00')  |     249 |        100 |         0.055319 |       2.01282  |
| ('binpack7.txt', 't249_01')  |     249 |        100 |         0.032663 |       1.92088  |
| ('binpack7.txt', 't249_02')  |     249 |        100 |         0.097715 |       1.83038  |
| ('binpack7.txt', 't249_03')  |     249 |        100 |         0.030005 |       2.03625  |
| ('binpack7.txt', 't249_04')  |     249 |        100 |         0.062223 |       1.91685  |
| ('binpack7.txt', 't249_05')  |     249 |        100 |         0.031008 |       1.97854  |
| ('binpack7.txt', 't249_06')  |     249 |        100 |         0.0302   |       2.00989  |
| ('binpack7.txt', 't249_07')  |     249 |        100 |         0.031233 |       1.99207  |
| ('binpack7.txt', 't249_08')  |     249 |        100 |         0.028492 |       1.92097  |
| ('binpack7.txt', 't249_09')  |     249 |        100 |         0.044379 |       1.90699  |
| ('binpack7.txt', 't249_10')  |     249 |        100 |         0.05848  |       1.92109  |
| ('binpack7.txt', 't249_11')  |     249 |        100 |         0.035356 |       1.9588   |
| ('binpack7.txt', 't249_12')  |     249 |        100 |         0.030407 |       1.78118  |
| ('binpack7.txt', 't249_13')  |     249 |        100 |         0.02924  |       1.98905  |
| ('binpack7.txt', 't249_14')  |     249 |        100 |         0.073645 |       1.93176  |
| ('binpack7.txt', 't249_15')  |     249 |        100 |         0.057342 |       1.8327   |
| ('binpack7.txt', 't249_16')  |     249 |        100 |         0.032163 |       1.7845   |
| ('binpack7.txt', 't249_17')  |     249 |        100 |         0.032969 |       1.78609  |
| ('binpack7.txt', 't249_18')  |     249 |        100 |         0.11822  |       1.93463  |
| ('binpack7.txt', 't249_19')  |     249 |        100 |         0.03053  |       1.80232  |
