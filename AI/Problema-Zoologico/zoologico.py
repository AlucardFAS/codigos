#Problema de Classic Computer Science Problems in Python por David Kopec(2019)
from satisfacao_restricoes import *
from typing import Dict, List, Optional


class RestricoesZoo(Restricao[str, str]):
    
    def __init__(self, animal1: str, animal2: str, fica_junto: bool = False) -> None:
    
        super().__init__([animal1, animal2])
    
        self.animal1: str = animal1
        self.animal2: str = animal2
        self.fica_junto: bool = fica_junto

    def check_restricao(self, task: Dict[str, str]) -> bool:
    
        leao = task.get('Leao')
        tigre = task.get('Tigre')
        antilope = task.get('Antilope')
    
        if not leao or not tigre or not antilope:
            return True
    
        if leao == 1:
            if (antilope + 1 != leao and antilope + 1 != tigre) and\
                (antilope - 1 != leao and antilope - 1 != tigre):
                return True 
    
        return False

    def satisfaz(self, task: Dict[str, str]) -> bool:
        
        if self.animal1 not in task or self.animal2 not in task:
            return True
        
        if not self.check_restricao(task):
            return False
        
        if self.fica_junto:
            return task[self.animal1] == task[self.animal2]
        
        else:
            return task[self.animal1] != task[self.animal2]


if __name__ == '__main__':
    
    variaveis: List[str] = ['Leao', 'Antilope', 'Hiena',
            'Tigre', 'Pavao', 'Suricate', 'Javali']
    domains: Dict[str, List[str]] = {}
    
    for variavel in variaveis:
        domains[variavel] = [1, 2, 3, 4]
    satisfacao_restricoes: Satisfacao_Restricoes[str, str] = Satisfacao_Restricoes(variaveis, domains)
    
    satisfacao_restricoes.add_restricao(RestricoesZoo('Leao', 'Tigre'))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Suricate', 'Javali', True))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Hiena', 'Tigre', True))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Tigre', 'Suricate'))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Tigre', 'Javali'))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Tigre', 'Pavao'))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Tigre', 'Antilope'))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Leao', 'Antilope'))
    satisfacao_restricoes.add_restricao(RestricoesZoo('Leao', 'Pavao'))
    
    solucao: Optional[Dict[str, str]] = satisfacao_restricoes.backtracking()
    
    print(solucao)