*** Settings ***
Resource  StepsConsultHero.robot

*** Keywords ***
#### DADO
Dado que esteja conectado na SuperHeroAPI
    Conecta ao WebService 

#### QUANDO
Quando o usuário consultar o super-herói "${HEROI}"
    Realiza requisição na SuperHeroAPI   ${HEROI}

#### ENTÃO
Então deve ser retornado a inteligência "${INTELIGENCIA}"
    Confere o status code       200
    Confere a inteligência do super-herói     ${INTELIGENCIA}

E deve ser retornado o verdadeiro nome "${NOME}"
    Confere o nome real do super-herói     ${NOME}

E deve ser retornado o grupo em que é afiliado "${GRUPO}"
    Confere o grupo do super-herói      ${GRUPO}
