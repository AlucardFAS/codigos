*** Settings ***
Resource            ../resources/BDDImplementation.robot

*** Test Case ***
Cenário 01: Consultar a ficha de um super-herói (/id)
    Dado que esteja conectado na SuperHeroAPI
	Quando requisitar o histórico do super-herói "Green Arrow"
	Então deve ser retornado que a sua inteligência é superior a "80"
	E deve ser retornado que o seu verdadeiro nome é ser "Oliver Queen"
	E deve ser retornado que é afiliado do grupo "Justice League Elite"


Cenário 02: Consultar qual o super-herói mais inteligente, rápido e forte (/id/powerstats)
    Dado que esteja conectado na SuperHeroAPI
	Quando requisitar as estatísticas de poder dos super-heróis "Flash" e "Ant-Man"
	Então deve ser retornado que o mais inteligente é o herói "Ant-Man"
	E deve ser retornado que o mais rápido é o herói "Flash"
	E deve ser retornado que o mais forte é o herói "Ant-Man"