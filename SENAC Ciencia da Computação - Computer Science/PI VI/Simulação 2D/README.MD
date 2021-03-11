# Modelo matemático de propagação de incêndio utilizando Cadeias de Markov

* Matriz 5x5 onde cada termo representa um terreno com 500m²
* Cada terreno tem um tipo(Mata, vegetação baixa, agricultura, pasto ou área nula, para construções ou corpos híbridos)
* Cada terreno deve conter: Hi = umidade relativa do ar (%); n = número de dias sem chuva maior ou igual a 13;
mm; v = velocidade do vento em m/s(CONSTANTE)
e = 2,718282 - base dos logarítmos naturais
* Sobre cada terreno deve ser realizado um cálculo da taxa de propagação
* O vento deve influenciar o modelo, podendo correr sobre o mesmo vertical, horizontal e diagonalmente
* Incêndio pode iniciar de local aleatório ou selecionado
* Incêndio pode ir para qualquer quadrante que o envolve
* A quantidade de gerações da cadeia deve ser pré-determinada(DEFAULT 5)
* Cada geração implica 1 hora
* O modelo compreende locais com mais de 13 dias sem chuva
* Aplicar Fórmula de Monte Alegre


## Artigos de estudo 

* <a href="https://periodicos.ufsm.br/cienciaflorestal/article/view/27728/15735">COMPORTAMENTO DO FOGO EM DIFERENTES PERÍODOS E CONFIGURAÇÕES DE UMA PAISAGEM NO NORDESTE DE PORTUGAL</a><br>
* <a href="http://www.scielo.br/pdf/floram/v24/2179-8087-floram-2179-8087025615.pdf">Mapeamento do Risco de Incêndios Florestais Utilizando Técnicas de Geoprocessamento</a><br>
* <a href="https://www2.codevasf.gov.br/programas_acoes/programa-florestal-1/acoes-florestais-na-bacia-do-parnaiba/produto11_apostila_incendios.pdf">TÉCNICAS DE PREVENÇÃO E COMBATE À INCÊNDIOS FLORESTAIS</a><br>
