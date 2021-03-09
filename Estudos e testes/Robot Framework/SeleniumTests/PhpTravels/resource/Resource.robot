*** Settings ***
Library     SeleniumLibrary

*** Variables ***
${URL}          https://phptravels.com/demo/
${BROWSER}      chrome

*** Keywords ***
#-> SETUP E TEARDOWN
Abrir navegador
    Open Browser        about:blank     ${BROWSER}

Fechar navegador
    Close Browser

#-> AÇÕES
Acessar a página home do site
    Go To               ${URL}

Clicar no item do menu "${MENU_ITEM}"
    Click Element       xpath=/html/body/header/div/nav/a[contains(text(),'Pricing')]