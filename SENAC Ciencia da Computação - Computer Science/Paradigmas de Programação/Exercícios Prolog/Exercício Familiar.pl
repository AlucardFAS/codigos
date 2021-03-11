%%%%%%%%%%MADE BY ALUCARDFAS%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%DISCOVER THE LEVEL OF RELATIONSHIP%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%LOGICAL STATEMENTS%%%%%%%%%%
mãe(ana,joana).
mãe(joana,pedro).
pai(pedro,jose).
pai(jose,clara).

%%%%%%%%%%%%%%PREDICATE%%%%%%%%%%%%%%
avo(X,Y) :- (mãe(X,Z),mãe(Z,Y) ; pai(X,Z),pai(Z,Y) ;
            mãe(X,Z),pai(Z,Y) ; pai(X,Z),mãe(Z,Y)). %GRANDMA

bisavo(X,Y) :- (avo(X,Z),pai(Z,Y) ; avo(X,Z),mãe(Z,Y)). %GREAT GRANDMA

%%avó(X,Y) :- mãe(X,Z),mãe(Z,Y).%GRANDMOTHER
%avô(X,Y) :- pai(X,Z),pai(Z,Y).%GRANDFATHER
%bisavó(X,Y) :- mãe(X,Z),mãe(Z,K),mãe(K,Y).%GREAT GRANDMOTHER
