*** Settings ***
Library     SeleniumLibrary
Library     String

*** Variables ***
&{SIMPLE_GUEST_USER}       firstName=Guest  lastName=Test  emailProvider=@mailinator.com  password=12345678  country=Brazil
${BTN_SUBMIT_FORM_XPATH}   //div[contains(@class,'panel-footer')]//Button[contains(text(),'Submit')]
${USER_TABLE_XPATH}        //div[contains(@class,'xcrud-list-container')]//tbody

*** Keywords ***
#->Ações
Clicar para adicionar um novo
    ${BTN_ADD_XPATH}  Set Variable  //*[@id="content"]//button[contains(@type, 'submit')]
    Wait Until Element Is Visible   //div[contains(@class,'panel panel-default')]/*[contains(text(),'Guest Management')]
    Wait Until Element Is Visible   xpath=${BTN_ADD_XPATH}
    Click Button                    xpath=${BTN_ADD_XPATH}

Esperar paineis ficarem visíveis
    Wait Until Element Is Visible   //*[contains(text(),'Add Guest')]
    Wait Until Element Is Visible   //*[contains(text(),'Main Settings')]
    Wait Until Element Is Visible   //*[contains(@class, 'panel-body')]
    Wait Until Element Is Visible   ${BTN_SUBMIT_FORM_XPATH}

Verificar Guest Customer criado na listagem
    Wait Until Element Is Visible   ${USER_TABLE_XPATH}

#->Preenchimento de formulário
Preencher formulário com informações requeridas
    ${COUNTRY_FIELD_XPATH}  Set Variable  //*[@id="select2-drop"]//input
    ${EMAIL}                Generate Random String  length=8  chars=[LETTERS]

    Esperar paineis ficarem visíveis
    Input Text      name=fname          ${SIMPLE_GUEST_USER.firstName}
    Input Text      name=lname          ${SIMPLE_GUEST_USER.lastName}
    Input Text      name=email          ${EMAIL}${SIMPLE_GUEST_USER.emailProvider}
    Input Text      name=password       ${SIMPLE_GUEST_USER.password}
    Click Element   id=s2id_autogen1
    Input Text      xpath=${COUNTRY_FIELD_XPATH}   ${SIMPLE_GUEST_USER.country}
    Press Keys      xpath=${COUNTRY_FIELD_XPATH}   RETURN

Clicar no botão submit do form
    Click Button    xpath=${BTN_SUBMIT_FORM_XPATH}
