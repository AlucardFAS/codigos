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

Cenário 02: Adicionar um novo Guest Customer
    Dado que estou conectado na página de login
    Após acessar com credenciais válidas
    No dropdown "ACCOUNTS" acessar a página de "GuestCustomers"
    Clicar para adicionar um novo
    Preencher as informações
    Clicar para enviar as informações
    Verificar se o usuário foi criado

*** Keywords ***
Dado que estou conectado na página de login
    Acessar a página de login admin

Após acessar com credenciais válidas
    Logar com o "${USUARIO}" e "${SENHA}"

O dashboard inicial para usuário logado deve ser exibido
    Conferir informações do dashboard inicial para usuário logado

No dropdown "${DROPDOWN_ITEM}" acessar a página de "${DROPDOWN_LIST_ITEM}"
    Expandir o dropdown "${DROPDOWN_ITEM}"
    Acessar o item "${DROPDOWN_LIST_ITEM}" no dropdown

Expandir o dropdown "${DROPDOWN_ITEM}"
    Clicar no dropdown "${DROPDOWN_ITEM}"

Acessar o item "${DROPDOWN_LIST_ITEM}" no dropdown
    Clicar no item "${DROPDOWN_LIST_ITEM}" da lista do dropdown

Clicar para adicionar um novo

Preencher as informações

Clicar para enviar as informações

Verificar se o usuário foi criado