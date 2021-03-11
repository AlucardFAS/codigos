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

Acessar a página de login admin
    Go To       ${URL_ADMIN_LOGIN}

Logar com o "${USUARIO}" e "${SENHA}"
    Input Text      xpath=//*[contains(@name, 'email')]     ${USUARIO}
    Input Text      xpath=//*[contains(@name, 'password')]     ${SENHA}
    Click Element   xpath=//*[contains(@type, 'submit')]

Conferir informações do dashboard inicial para usuário logado
    Wait Until Element Is Visible       id=mainHeader
    Element Should Be Visible           xpath=//*[contains(@href, 'https://phptravels.net/admin/profile')]
    Element Text Should Be              xpath=//*[@id="mainHeader"]/strong                                  Hi Admin!

Clicar no item do menu "${MENU_ITEM}"
    Click Element                   xpath=/html/body/header/div/nav/a[contains(text(),'${MENU_ITEM}')]
    Wait Until Element Is Visible   xpath=//div[contains(@class, 'cards')]

Clicar no dropdown "${DROPDOWN_ITEM}"
    Wait Until Element Is Visible   id=social-sidebar-menu
    Click Element                   xpath=//*[contains(@href, '#${DROPDOWN_ITEM}')]

Clicar no item "${DROPDOWN_LIST_ITEM}" da lista do dropdown
    ${ITEM_XPATH}   Set Variable       //*[contains(@aria-expanded, 'true')]//*[contains(text(),'${DROPDOWN_LIST_ITEM}')]
    Wait Until Element Is Visible     xpath=${ITEM_XPATH}
    Click Element      xpath=${ITEM_XPATH}

Checar se o plano "${PLANO}" e valor "${VALOR}" são exibidos
    Element Text Should Be      //div[contains(@class, 'pricing')]//*[contains(text(),'${PLANO}')]/..//div[contains(@class, 'plan-type')]                                                       ${PLANO}
    Element Text Should Be      //div[contains(@class, 'pricing')]//*[normalize-space(text())='${PLANO}']/..//div[contains(@class, 'show-price yearly')]//*[contains(number(),'${VALOR}')]      ${VALOR}
