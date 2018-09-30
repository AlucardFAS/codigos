def QuicarBola(alturaInicial,limiteAltura):
    
    #altura atual em que a bola está
    alturaAtual = alturaInicial
    #considerando altura da primeira queda
    distanciaPercorrida = alturaInicial
    #quantidade de quicks, considerando a primeira quicada com alturaInicial
    kikar = 1

    while(alturaAtual >= limiteAltura):
        distanciaPercorrida += alturaAtual
        alturaAtual = alturaAtual/2
        kikar += 1

    print("\nA bola quicou ", kikar, " vezes")

    return distanciaPercorrida

def Main():
    print("================================================")
    print("===========Simulação de queda de bola===========")
    print("================================================")
    print()
    print("Todas entradas aceitam ponto flutuante")
    print()
    alturaInicial = float(input("Entre com a altura inicial: "))
    limiteAltura = float(input("Entre com o limite de altura: "))

    distancia = QuicarBola(alturaInicial,limiteAltura)

    print("\n\nDistância percorrida pela bola: ", distancia)



Main()