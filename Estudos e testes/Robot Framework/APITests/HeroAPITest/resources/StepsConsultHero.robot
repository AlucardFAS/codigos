*** Settings ***
Library     RequestsLibrary
Library     Collections

*** Variables ***
${Host}				https://superheroapi.com/api
${APP_KEY}			3630587223674860
${URL}				${Host}/${APP_KEY}
&{SEARCHED_HERO} 	green_arrow=298		flash=100 		ant_man=30
&{COMPARE_NAMES}	flash=Flash 		ant_man=Ant-Man
&{GREEN_ARROW}		name=Green Arrow	intelligence=81	real_name=Oliver Queen	affiliate=Justice League Elite


*** Test Cases ***
Consultar a ficha de um super-herói (/id)
	Create Session      consultaHeroi     ${URL}    disable_warnings=True

    ${RESPONSE}=        GET On Session  consultaHeroi  /${SEARCHED_HERO.green_arrow}
	
	${HERO_DATA}      Create Dictionary   name=${GREEN_ARROW.name}   			intelligence=${GREEN_ARROW.intelligence}   
	...									  full_name=${GREEN_ARROW.real_name}    group_affiliation=${GREEN_ARROW.affiliate}
	
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
	Set test Variable	${COMPARE_NAMES.flash}
	
Ant Man
	Set test Variable	${COMPARE_NAMES.ant_man}

Return The Biggest
    [Arguments]    ${value_1}    ${value_2}
    Run Keyword If    ${value_1} > ${value_2}	Flash
    ...		ELSE    Ant Man 
