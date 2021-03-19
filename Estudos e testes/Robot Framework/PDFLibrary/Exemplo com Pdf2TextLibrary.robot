***Settings***
Library     Pdf2TextLibrary
Library     String
Library     Collections
Library     BuiltIn

***Variables***
${ARQUIVO_PDF}      PDF_EXEMPLO.pdf

***Test Cases***
Cenário 01: Encontrar texto no PDF
    ${PDF_TEXT}     Convert Pdf To Txt     ${ARQUIVO_PDF}
    ${PDF_TEXT}     Split String           ${PDF_TEXT}      \n
    Should Be True  ' A Simple PDF File ' in ${PDF_TEXT}

Cenário 02: Contar páginas
    ${PDF_PAGES}    Count Pdf Pages     ${ARQUIVO_PDF}
    Should Be Equal  ${PDF_PAGES}       ${2}

Cenário 03: Conferir posição do texto na lista
    ${PDF_TEXT}     Convert Pdf To Txt     ${ARQUIVO_PDF}
    ${PDF_TEXT}     Split String           ${PDF_TEXT}      \n
    ${INDEX}        Get Index From List    ${PDF_TEXT}  \x0c Simple PDF File 2${SPACE}

    Should Be Equal  ${INDEX}   ${15}

Cenário 04: Conferir ordem do texto na lista 
    ${PDF_TEXT}     Convert Pdf To Txt     ${ARQUIVO_PDF}
    ${PDF_TEXT}     Split String           ${PDF_TEXT}      \n
    ${SMALLEST_INDEX}        Get Index From List    ${PDF_TEXT}  ${SPACE}A Simple PDF File${SPACE}
    ${HIGHER_INDEX}       Get Index From List    ${PDF_TEXT}  \x0c Simple PDF File 2${SPACE}

    Should Be True  ${SMALLEST_INDEX} < ${HIGHER_INDEX}
