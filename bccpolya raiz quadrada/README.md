
=============================================================
#Algoritmo para calcular raízes

1.DESCRIÇÃO DO PROBLEMA

2.LINGUAGEM MATEMÁTICA

3.PORTUGUÊS ESTRUTURADO

4.FLUXOGRAMA

5.JUSTIFICATIVA DO USO DO TERMO "POLYA" NO NOME DO REPOSITÓRIO.

=============================================================



1.DESCRIÇÃO DO PROBLEMA

Calcular a raiz quadrada de um número real positivo sem o uso da biblioteca math.h e do método de Newton Raphson.



2.LINGUAGEM MATEMÁTICA

q = q/2 + n/(2*q)

n = Valor que se deseja obter a raiz;
q = Valor igual a n, que conforme a aplicação da fórmula muda.



3.PORTUGUÊS ESTRUTURADO


algoritmo "CalculaRaiz"

raizq: real (real);

variável
    n:real;

inicio  
  
    ler(n);
    
    escrever(raizq(n));
fim



raizq: real (n: real)

inicio
    x:inteiro;
    q: real;
    q = n;
    
    para x de 0  até 200 passo x faça
          q = q/2 + n/(2*q);

    retorne (n);

    fim_para
            
fim



4.FLUXOGRAMA

![Alt text](https://ap.imagensbrasil.org/images/FLUXOGRAMAREADME.jpg)



5.JUSTIFICATIVA DO USO DO TERMO "POLYA" NO NOME DO REPOSITÓRIO.

O uso do termo "Polya" da-se ao fato do método utilizado para resolver o problema levantado. George Polya foi um matemático que fundamentou um método para resolver problemas seguindo quatro etapas básicas:Compreensão, elaboração de um plano, aplicar o plano e comprovar o resultado. O programa elaborado seguiu uma linha parecida, onde, sem uso de funções pré-definidas, se foi necessário criar o próprio meio para chegar a um resultado.

