# Estudos de Robot Framework
Os testes aqui desenvolvidos tem como objetivo aprender e acostumar-se com o desenvolvimento em Robot Framework.


### Dependências
- Python 3.9.2
- Robot Framework 3.2.2
- Robot Framework Selenium Library 5.1.0
- Selenium 3.141.0
- Chrome Driver 2.24.1


### Como rodar os testes 

Exemplo de comando para executar um único teste
```robot -d .\results -t "Cenário 02: Adicionar um novo Guest Customer" SeleniumTests\PhpTravels\tests\AdminTestsBDD.robot```

Exemplo de comando para executar todos os testes de um arquivo de testes
```robot -d .\results SeleniumTests\PhpTravels\tests\AdminTestsBDD.robot```