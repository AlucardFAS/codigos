from random import randint

def Clima(mes):
    while(mes > 12 or mes < 1): 
        print("Formato de mês incorreto, selecione uma data válida")
        mes = int(input("Em qual mês deseja simular a venda?  "))

    probSol = [0.45,0.55,0.60,0.70,0.70,0.75,0.75,0.80,0.70,0.60,0.60,0.50]
    probRand = (randint(0,100))/100

    #0 chuva -- 1 sol#

    if (probRand > probSol[mes]):
        return 0
    else:
        return 1

def PipocaDoParque(): 

    ####VALUES####
    valorPipoca = 5.0
    valorEstoque = 2.0
    mediaClientes = 60
    segundaPipoca = 0.3
    terceiraPipoca = 0.2
    quartaPipoca = 0.05
    chuva = 0.6
    sol = 0.4
    estoqueMax = 100
    estoqueMin = 0


    ####INPUT####
    estoque = int(input("Com qual tamanho de estoque deseja simular?  "))
    numSimulacoes = int(input("Quantas simulações deseja realizar?  "))
    mes = int(input("Em qual mês deseja simular a venda?  "))


    ####PROGRAM####
    estadoTempo = Clima(mes)



PipocaDoParque()