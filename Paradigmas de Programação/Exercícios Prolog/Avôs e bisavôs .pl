%%%%%%%%%%MADE BY ALUCARDFAS%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%DISCOVER THE LEVEL OF RELATIONSHIP%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%LOGICAL STATEMENTS%%%%%%%%%%
pai(jose,joao).
pai(joao,julio).
pai(julio,jorge).
pai(jorge,fabio).
pai(julio,jow).
male(jose).
male(joao).
male(julio).
male(jorge).
male(fabio).
male(jow).

%%%%%%%%%%%%%%PREDICATE%%%%%%%%%%%%%%
filho(X,Y) :- pai(Y,X). %SON
avo(X,Y) :- pai(X,Z),pai(Z,Y). %GRANDMA
bisavo(X,Y) :- pai(X,Z),pai(Z,K),pai(K,Y). %GREAT GRANDFATHER
trisavo(X,Y) :- avo(X,Z),avo(Z,Y). %GREAT-GRANDFATHER
irmaoPai(X,Y) :- pai(Q,X),pai(Q,Y), not(X=Y). %BROTHER BY FATHER
apenasFilho(X) :- \+pai(X,_). %IS NOT A FATHER / JUST SON
