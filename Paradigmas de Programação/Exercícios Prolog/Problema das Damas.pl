%Exemplo de entrada: damas(4,Solução).
damas(N,L) :- template(1,N,L), solucao1(N,L).
template(N,N,[(N,_)]).
template(M,N,[(M,_)|L]) :- M<N, M1 is M+1, template(M1,N,L).
solucao1(_,[]).
solucao1(N,[(X,Y)|Resto]) :- solucao1(N,Resto),
entre(1,N,L),
member(Y,L), 
naoataca((X,Y),Resto).
entre(M,N,[M|L]) :- M<N, M1 is M+1, entre(M1,N,L).
entre(N,N,[N]).
naoataca(_,[]).
naoataca((X,Y),[(X1,Y1)|Resto]) :- X =\= X1, Y =\= Y1,
X-X1 =\= Y-Y1, X-X1 =\= Y1-Y,
naoataca((X,Y),Resto).