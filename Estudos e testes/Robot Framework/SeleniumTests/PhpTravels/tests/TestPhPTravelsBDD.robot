*** Settings ***
Resource            ../resource/Resource.robot
Test Setup          Abrir navegador
Test Teardown       Fechar navegador

*** Variables ***
${URL}          https://phptravels.com/demo/
${BROWSER}      chrome

*** Test Case ***
Cenário 01: Verificar Planos e Preços
    Dado que estou conectado na home do site
    Quando eu clicar no item do menu "Pricing"
    Deve ser mostrado o plano "Web App" por $"499"
    Deve ser mostrado o plano "Android App" por $"999"
    Deve ser mostrado o plano "iOS App" por $"999"
    Deve ser mostrado o plano "Complete Bundle" por $"2499"

*** Keywords ***
Dado que estou conectado na home do site
    Acessar a página home do site

Quando eu clicar no item do menu "${MENU_ITEM}"
    Clicar no item do menu "${MENU_ITEM}"

Deve ser mostrado o plano "${PLANO}" por $"${VALOR}"
    Checar se o plano "${PLANO}" e valor "${VALOR}" são exibidos