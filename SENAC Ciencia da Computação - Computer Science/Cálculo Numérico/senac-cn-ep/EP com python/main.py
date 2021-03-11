from src import grafos
from src import pRank
from src.grafos import grafo



if __name__ == '__main__':
    rede = grafo.carregaDado('src/input.json')
    ranks = pRank.main()
    for rank in enumerate(ranks):
        print('{}'.format(rank))