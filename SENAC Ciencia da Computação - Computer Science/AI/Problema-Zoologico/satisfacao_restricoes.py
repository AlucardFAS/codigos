#Problema de Classic Computer Science Problems in Python por David Kopec(2019)
from typing import *
from abc import ABC, abstractmethod

V = TypeVar('V') 
D = TypeVar('D') 

class Restricao(Generic[V, D], ABC):
    def __init__(self, variaveis: List[V]) -> None:
        self.variaveis = variaveis

    @abstractmethod
    def satisfaz(self, task: Dict[V, D]) -> bool:
        ...

class Satisfacao_Restricoes(Generic[V, D]):
    
    def __init__(self, variaveis: List[V], dominios: Dict[V, List[D]]) -> None:

        self.variaveis: List[V] = variaveis 
        self.dominios: Dict[V, List[D]] = dominios
        self.restricoes: Dict[V, List[Restricao[V, D]]] = {}
    
        for variavel in self.variaveis:
            self.restricoes[variavel] = []

            if variavel not in self.dominios:
                raise LookupError

    def add_restricao(self, restricao: Restricao[V, D]) -> None:

        for variavel in restricao.variaveis:

            if variavel not in self.variaveis:
                raise LookupError
            else:
                self.restricoes[variavel].append(restricao)

    def consistent(self, variavel: V, task: Dict[V, D]) -> bool:

        for restricao in self.restricoes[variavel]:
            if not restricao.satisfaz(task):
                return False
  
        return True

    def backtracking(self, task: Dict[V, D] = {}) -> Optional[Dict[V, D]]:

        if len(task) == len(self.variaveis):
            return task

        unassigned: List[V] = [v for v in self.variaveis if v not in task]

        primeiro: V = unassigned[0]

        for valor in self.dominios[primeiro]:
            task_local = task.copy()
            task_local[primeiro] = valor

            if self.consistent(primeiro, task_local):
                resultado: Optional[Dict[V, D]] = self.backtracking(task_local)

                if resultado is not None:
                    return resultado

        return None