# Senac | Cálculo Numérico | Page Rank

Este projeto foi desenvolvido em duas partes:

1.Desenvolvimento do Page Rank em Fortran;</br>
2.Integração com Python para interface com usuário.


Por questões maiores, a segunda parte ficou incompleta.

<h2>PAGE_RANK.f95</h2>

O input da matriz é feito no próprio código pela matriz A.
Com base nisso, os cálculos são realizados conforme artigo recomendado  e da como saída um vetor com o rank das páginas.

<h2>EP com Python</h2>

Foi desenvolvido até a metade, pois apresentava problemas com a leitura da entrada.
o algoritmo em Fortran foi baseado no mesmo dito na função acima, onde a entrada era inserida num JSON nomeado input.json.
