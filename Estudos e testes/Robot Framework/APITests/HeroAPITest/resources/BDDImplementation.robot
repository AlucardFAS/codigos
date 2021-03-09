*** Settings ***
Resource  StepsConsultHero.robot

*** Keywords ***
Consultar a ficha de um herói (/id)
#### DADO
Dado que esteja conectado na SuperHeroAPI
    Conecta ao WebService 

#### QUANDO
Quando o usuário consultar o herói "${HEROI}"
    Realiza requisição na SuperHeroAPI (/id)  ${HEROI}

#### ENTÃO
Então deve ser retornado a inteligência "${INTELIGENCIA}"
    Confere o status code       200
    Confere a inteligência do herói     ${INTELIGENCIA}

E deve ser retornado o verdadeiro nome "${NOME}"
    Confere o nome real do herói     ${NOME}

E deve ser retornado o grupo em que é afiliado "${GRUPO}"
    Confere o grupo do herói      ${GRUPO}

########################################################################

Consultar qual o herói mais inteligente, rápido e forte (/id/powerstats)
#### DADO
Dado que esteja conectado na SuperHeroAPI
    Conecta ao WebService 

#### QUANDO
Quando o usuário consultar os heróis "${HEROI1}" e "${HEROI2}"
    Realiza requisição na SuperHeroAPI (/id/powerstats)   ${HEROI1}
	Realiza requisição na SuperHeroAPI (/id/powerstats)   ${HEROI2}

#### ENTÃO
Então devem ser retornados os powerstats dos heróis "${HEROI1}" e "${HEROI2}"
    Confere o status code       200
    Confere os stats dos heróis "${HEROI1}" e "${HEROI2}"

Então deve ser retornado o herói mais inteligente entre "${HEROI1}" e "${HEROI2}"
    Confere o herói mais inteligente     ${NOME}

E deve ser retornado o herói mais rápido entre "${HEROI1}" e "${HEROI2}"
    Confere o herói mais rápido     ${NOME}

E deve ser retornado o herói mais forte entre "${HEROI1}" e "${HEROI2}"
    Confere o herói mais forte     ${NOME}