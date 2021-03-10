*** Settings ***
Resource            ../resource/Resource.robot
Test Setup          Abrir navegador
Test Teardown       Fechar navegador

*** Variables ***
${URL_ADMIN_LOGIN}  http://phptravels.net/admin/
${USUARIO}          admin@phptravels.com
${SENHA}            demoadmin

*** Test Case ***
Cenário 01: Login com sucesso
    Dado que estou conectado na página de login
    Após acessar com credenciais válidas
    O dashboard inicial para usuário logado deve ser exibido

*** Keywords ***
Dado que estou conectado na página de login
    Acessar a página de login admin

Após acessar com credenciais válidas
    Logar com o "${USUARIO}" e "${SENHA}"

O dashboard inicial para usuário logado deve ser exibido
    Conferir informações do dashboard inicial para usuário logado
