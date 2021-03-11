from . import *

input = {'noh': [], 'caminho': []}

def novo(data=input):
    grafo = Grafo()
    for u in data['noh']:
        grafo.add_noh(u)
    for (u, v) in data['caminho']:
        grafo.add_caminho(u, v)
    return grafo

def carregaDado(filename):
    import json
    with open(filename, 'r') as data:
        data = json.load(data)
    return novo(data)

def salvar(grafo, filename):
    import json
    with open(filename, 'w') as data:
        json.dump({
            'noh': list(u for u in grafo.noh),
            'caminho': list([u, v] for (u, v) in grafo.caminhos)
        }, data, indent=2)