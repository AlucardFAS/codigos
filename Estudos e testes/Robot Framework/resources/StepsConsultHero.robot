*** Settings ***
Library     RequestsLibrary
Library     Collections

*** Variables ***
${Host}				https://superheroapi.com/api
${APP_KEY}			3630587223674860
${URL}				${Host}/${APP_KEY}
${SEARCHED_HERO} 	green_arrow
${NAME}				Green Arrow
${INTELLIGENCE} 	81
${REAL_NAME}		Oliver Queen
${AFFILIATE}		Justice League Elite


*** Test Cases ***
Consultar a ficha de um super-herói (/id)
	Create Session      consultaHeroi     ${URL}    disable_warnings=True


    ${RESPONSE}=        GET On Session  consultaHeroi  /search/${SEARCHED_HERO}
    Set Test Variable   ${RESPONSE}
	${HERO_DATA}      Create Dictionary   name=${NAME}   intelligence=${INTELLIGENCE}   real-name=${REAL_NAME}   group-affiliation=${AFFILIATE}
	
	Dictionary Should Contain Item    ${RESPONSE.json()['results'][0]}					name				${NAME}
	Dictionary Should Contain Item    ${RESPONSE.json()['results'][0]['powerstats']}	intelligence		${INTELLIGENCE}
	Dictionary Should Contain Item    ${RESPONSE.json()['results'][0]['biography']}		full-name			${REAL_NAME}
	Dictionary Should Contain Key     ${RESPONSE.json()['results'][0]['connections']}	group-affiliation	${AFFILIATE}


Consultar qual o super-herói mais inteligente, rápido e forte (/id/powerstats)
	Create Session      consultaHeroi     ${URL}    disable_warnings=True
