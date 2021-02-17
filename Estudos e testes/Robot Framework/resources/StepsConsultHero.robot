*** Settings ***
Library     RequestsLibrary
Library     Collections

*** Variables ***
${Host}				https://superheroapi.com/api
${APP_KEY}			3630587223674860
${URL}				${Host}/${APP_KEY}
&{SEARCHED_HERO} 	green_arrow=298			flash=100 		ant_man=30
&{NAMES}			green_arrow=Green Arrow	flash=Flash 	ant_man=Ant-Man
${INTELLIGENCE} 	81
${REAL_NAME}		Oliver Queen
${AFFILIATE}		Justice League Elite


*** Test Cases ***
Consultar a ficha de um super-herói (/id)
	Create Session      consultaHeroi     ${URL}    disable_warnings=True


    ${RESPONSE}=        GET On Session  consultaHeroi  /${SEARCHED_HERO.green_arrow}
	
	${HERO_DATA}      Create Dictionary   name=${NAMES.green_arrow}   intelligence=${INTELLIGENCE}   full_name=${REAL_NAME}   group_affiliation=${AFFILIATE}
	
	Dictionary Should Contain Item    ${RESPONSE.json()}				name				${HERO_DATA.name}
	Dictionary Should Contain Item    ${RESPONSE.json()['powerstats']}	intelligence		${HERO_DATA.intelligence}
	Dictionary Should Contain Item    ${RESPONSE.json()['biography']}	full-name			${HERO_DATA.full_name}
	Dictionary Should Contain Key     ${RESPONSE.json()['connections']}	group-affiliation	${HERO_DATA.group_affiliation}


Consultar qual o super-herói mais inteligente, rápido e forte (/id/powerstats)
	Create Session     	consultaHeroi     ${URL}    disable_warnings=True

	#Eu ia usar uma collection pra armazenar esses heróis, mas acabei ficando apertado em tempo e não consegui ver como aplicar
	${FLASH_RESPONSE}=       	GET On Session  consultaHeroi  /${SEARCHED_HERO.flash}/powerstats
	${ANTMAN_RESPONSE}=       	GET On Session  consultaHeroi  /${SEARCHED_HERO.ant_man}/powerstats

	Return The Biggest	${FLASH_RESPONSE.json()['intelligence']}	${ANTMAN_RESPONSE.json()['intelligence']}
	Return The Biggest	${FLASH_RESPONSE.json()['speed']}			${ANTMAN_RESPONSE.json()['speed']}
	Return The Biggest	${FLASH_RESPONSE.json()['strength']}		${ANTMAN_RESPONSE.json()['strength']}


***Keywords***
Flash
	Set test Variable	${NAMES.flash}
	
Ant Man
	Set test Variable	${NAMES.ant_man}

Return The Biggest
    [Arguments]    ${value_1}    ${value_2}
    Run Keyword If    ${value_1} > ${value_2}	Flash
    ...		ELSE    Ant Man 
