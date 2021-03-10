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
    Go To       ${URL}

Clicar no item do menu "${MENU_ITEM}"
    Click Element                   xpath=/html/body/header/div/nav/a[contains(text(),'${MENU_ITEM}')]
    Wait Until Element Is Visible   xpath=//div[contains(@class, 'cards')]

Checar se o plano "${PLANO}" e valor "${VALOR}" são exibidos
    Element Text Should Be      //div[contains(@class, 'pricing')]//*[contains(text(),'${PLANO}')]/..//div[contains(@class, 'plan-type')]                                                       ${PLANO}
    Element Text Should Be      //div[contains(@class, 'pricing')]//*[normalize-space(text())='${PLANO}']/..//div[contains(@class, 'show-price yearly')]//*[contains(number(),'${VALOR}')]      ${VALOR}