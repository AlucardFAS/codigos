%%%%%%%%%%MADE BY ALUCARDFAS%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%DISCOVER BY TYPE OF PROGENITOR%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%LOGICAL STATEMENTS%%%%%%%%%%
genitor(paulo,ana).
genitor(rose,ana).
genitor(paulo,liliane).
genitor(rose,liliane).
homem(paulo).
mulher(rose).
mulher(ana).
mulher(liliane).

%%%%%%%%%%%%%%PREDICATE%%%%%%%%%%%%%%
pai(X,Y) :- genitor(X,Y),homem(X). %FATHER
mae(X,Y) :- genitor(X,Y),mulher(X). %MOTHER
filho(X,Y) :- genitor(X,Y),homem(Y). %SON
filha(X,Y) :- genitor(X,Y),mulher(Y). %DAUGHTER
irma(X,Y) :- pai(Z,X) , pai(Z,Y) , mae(M,X) , mae(M,Y) , not(X=Y) , mulher(X). %SISTER
irmao(X,Y) :- pai(Z,X) , pai(Z,Y) , mae(M,X) , mae(M,Y) , not(X=Y) , homem(X). %BROTHER
avô(X,Y) :- pai(X,Z) , ( pai(Z,Y) ; mae(Z,Y) ). %GRANDFATHER
avó(X,Y) :- mae(X,Z) , ( pai(Z,Y) ; mae(Z,Y) ). %GRANDMOTHER
primo(X,Y) :- homem(X) , ( irmao(Z,M) ; irma(Z,M) ), 
    (   (   pai(Z,X) , mae(M,Y)	;
			pai(Z,X) , pai(M,Y)	;
        	mae(Z,X) , mae(M,Y)	;
	        mae(Z,X) , pai(M,Y)	)	). %COUSIN
