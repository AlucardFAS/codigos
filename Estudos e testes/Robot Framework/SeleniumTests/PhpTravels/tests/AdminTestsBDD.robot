*** Settings ***
Resource            ../resource/Resource.robot
Resource            ../resource/GuestCustomersResource.robot
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
    E no dropdown "ACCOUNTS" acessar a página de "GuestCustomers"
    Ao clicar para adicionar um novo Guest Customer
    E preencher as informações requeridas para criar um Guest Customer
    E então clicar no botão submit do form
    Deve ser criado um usuário com as informações enviadas

*** Keywords ***
Dado que estou conectado na página de login
    Acessar a página de login admin

Após acessar com credenciais válidas
    Logar com o "${USUARIO}" e "${SENHA}"

O dashboard inicial para usuário logado deve ser exibido
    Conferir informações do dashboard inicial para usuário logado

E no dropdown "${DROPDOWN_ITEM}" acessar a página de "${DROPDOWN_LIST_ITEM}"
    Expandir o dropdown "${DROPDOWN_ITEM}"
    Acessar o item "${DROPDOWN_LIST_ITEM}" no dropdown

Ao clicar para adicionar um novo Guest Customer
    Clicar para adicionar um novo

Expandir o dropdown "${DROPDOWN_ITEM}"
    Clicar no dropdown "${DROPDOWN_ITEM}"

Acessar o item "${DROPDOWN_LIST_ITEM}" no dropdown
    Clicar no item "${DROPDOWN_LIST_ITEM}" da lista do dropdown

E preencher as informações requeridas para criar um Guest Customer
    Preencher formulário com informações requeridas

E então clicar no botão submit do form
    Clicar no botão submit do form

Deve ser criado um usuário com as informações enviadas
    Verificar Guest Customer criado na listagem