%MADE BY ALUCARDFAS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%CHECK THE HIGHEST NUMBER%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%

maior(X,Y,Z) :- ( X > Y ), Z is X.
maior(X,Y,Z) :- ( Y > X ), Z is Y. 