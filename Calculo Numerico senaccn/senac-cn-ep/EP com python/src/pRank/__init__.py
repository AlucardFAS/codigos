from src.grafos import *
from src.grafos import grafo


rede = None
available_grafos = list()
selected_grafo = 'input.json'
link_matrix = None
page_rank = None
import subprocess

def generate_link_matrix():
    global rede
    global selected_grafo
    global link_matrix

    #grafo = Grafo()
    rede = grafo.carregaDado(selected_grafo)

    n = len(rede.nohs)
    link_matrix = [[0 for _ in range(n)] for _ in range(n)]

    for i, u in enumerate(rede.nohs):
        for j, v in enumerate(rede.nohs):
            if u in {w for w in rede.neighbours(v)}:
                link_matrix[i][j] = 1 / len({w for w in rede.neighbours(v)})

def calculaRank():
    global page_rank

    n = len(link_matrix)

    import os
    if os.name == 'nt':
        args = ['page_rank.exe', str(n)]
    else:
        args = ['page_rank', str(n)]

    for i in range(n):
        for j in range(n):
            args.append(
                str(link_matrix[i][j])
            )

    for i in range(n):
        for j in range(n):
            args = []
            args.append(
                str(link_matrix[i][j])
            )

    process = subprocess.Popen(args, stdout=subprocess.PIPE, stdin=subprocess.PIPE, env=None)
    page_rank = [token.decode() for token in process.stdout]

    for noh, rank in zip(rede.nohs, page_rank):
        print('Nó {} <=> rank {}'.format(noh, rank))

    process.kill()

class Pipeline:
    actions = []
    def add_action(self, action):
        self.actions.append(action)
    def run(self):
        for action in self.actions:
            action()

pipeline = Pipeline()
pipeline.add_action(generate_link_matrix)
pipeline.add_action(calculaRank)

def main():
    pipeline.run()


if __name__ == '__main__':
    main()