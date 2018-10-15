class Grafo:
    class nohSet:
        def __init__(self, grafo):
            self.grafo = grafo
        def __iter__(self):
            for u in self.grafo.represente.keys():
                yield u
        def __len__(self):
            return len(self.grafo.represente.keys())
        def __str__(self):
            return str({u for u in self.grafo.nohs})

    class defineCaminho:
        def __init__(self, grafo):
            self.grafo = grafo
        def __iter__(self):
            for u in self.grafo.nohs:
                for v in self.grafo.neighbours(u):
                    yield (u, v)
        def __len__(self):
            return sum(1 for caminho in self)
        def __str__(self):
            return str({e for e in self.grafo.caminhos})

    def __init__(self):
        self.represente = dict()
        self.nohs = Grafo.nohSet(self)
        self.caminhos = Grafo.defineCaminho(self)
    def add_noh(self, u):
        self.represente[u] = set()
    def add_caminho(self, u, v):
        self.represente[u] |= {v}
    def neighbours(self, u):
        for v in self.represente[u]:
            yield v
    @property
    def adjacency_matrix(self):
        def adjacency_matrix_row(neighbours_set):
            for v in self.nohs:
                if v in neighbours_set:
                    yield 1
                else:
                    yield 0
        for u in self.nohs:
            yield adjacency_matrix_row({v for v in self.neighbours(u)})

if __name__ == '__main__':
    import random
    grafo = Grafo()
    for i in range(5):
        grafo.add_noh(i)
    print(set(grafo.nohs))
    for i in range(5):
        for j in range(5):
            grafo.add_caminho(random.randint(0, 4), random.randint(0, 4))
    print(set(grafo.caminhos))
    for row in grafo.adjacency_matrix:
        for element in row:
            print('[{}]'.format(element), end='')
        print('')
    print(len(grafo.nohs))
    print(len(grafo.caminhos))