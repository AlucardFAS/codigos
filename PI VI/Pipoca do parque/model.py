from random import randint

def Clima(mes):
    probSol = [0.45,0.55,0.60,0.70,0.70,0.75,0.75,0.80,0.70,0.60,0.60,0.50]
    probRand = (randint(0,100))/100

    #0 chuva -- 1 sol#

    if (probRand > probSol[mes]):
        return 0
    else:
        return 1

def printAll(totalGasto,estoque,numSimulacoes,totalSol,totalClientes,valorPipoca,totalClientesAtendidos):
    lucro = totalClientesAtendidos*valorPipoca-totalGasto*numSimulacoes

    print("Total de gastos: ", totalGasto*numSimulacoes)
    print("Total recebido: ", totalClientesAtendidos*valorPipoca)
    print("Lucros: ", lucro)
    print("Clientes sem pipoca: ", totalClientes-totalClientesAtendidos)
    print("Lucro Máximo com todos clientes atendidos: ", totalClientes*valorPipoca)
    print("Estoque: ", estoque)
    print("Dias de sol: ", totalSol," - ",round((totalSol/numSimulacoes*100),2),"%")
    print("Dias de chuva: ", numSimulacoes - totalSol," - ", round(((numSimulacoes - totalSol)/numSimulacoes*100),2),"%")
    print("Média de Lucro: ", lucro/numSimulacoes)
    print("Média de clientes atendidos: ",totalClientesAtendidos/numSimulacoes)
#    print("Média de de clientes sem atendimento: ", 100-(totalClientesAtendidos/numSimulacoes))

def PipocaDoParque(): 

    ####VALUES####
    valorPipoca = 5.0
    valorEstoque = 2.0
    segundaPipoca = 0.3
    terceiraPipoca = 0.2
    quartaPipoca = 0.05
    estoqueMax = 100
    estoqueMin = 0
    qtdClientes = 60
    totalSol = 0
    totalClientes = 0
    totalClientesAtendidos = 0

    ####INPUT####
    estoque = int(input("Com qual tamanho de estoque deseja simular?  "))
    while(estoque > estoqueMax or estoque < estoqueMin): 
        print("Parâmetro incorreto, selecione um valor entre 0 e 100.")
        estoque = int(input("Com qual tamanho de estoque deseja simular?  "))

    numSimulacoes = int(input("Quantas simulações deseja realizar?  "))

    mes = int(input("Em qual mês deseja simular a venda?  "))
    while(mes > 12 or mes < 1): 
        print("Formato de mês incorreto, selecione uma data válida")
        mes = int(input("Em qual mês deseja simular a venda?  "))

    ####PROGRAM####
    totalGasto = valorEstoque * estoque

    for i in range(numSimulacoes):
        estadoTempo = Clima(mes)

        if (estadoTempo == 0):
            qtdClientes -= int((randint(0,60)/100)*60)
        else:
            qtdClientes += int((randint(0,40)/100)*60)
            totalSol += 1

        for j in range(qtdClientes):
            if (randint(0,100)/100 < segundaPipoca):
                qtdClientes += 1
                if (randint(0,100)/100 < terceiraPipoca):
                    qtdClientes += 1
                    if (randint(0,100)/100 < quartaPipoca):
                        qtdClientes += 1

        if (qtdClientes >= estoque):
            totalClientesAtendidos += estoque
        else:
            totalClientesAtendidos += qtdClientes 

        totalClientes += qtdClientes
        
        qtdClientes = 60

    printAll(totalGasto,estoque,numSimulacoes,totalSol,totalClientes,valorPipoca,totalClientesAtendidos)

PipocaDoParque()
input()
