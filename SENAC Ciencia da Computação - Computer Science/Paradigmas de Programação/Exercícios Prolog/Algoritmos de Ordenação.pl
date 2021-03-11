%Exemplo de entrada: quicksort([2,16,10,8,4,3,5,1],Ordene).
pivo(_, [], [], []).
pivo(Pivo, [Head|Tail], [Head|MenorOuIgual], MaiorQue) :- Pivo >= Head, pivo(Pivo, Tail, MenorOuIgual, MaiorQue). 
pivo(Pivo, [Head|Tail], MenorOuIgual, [Head|MaiorQue]) :- pivo(Pivo, Tail, MenorOuIgual, MaiorQue).

quicksort([], []).
quicksort([Head|Tail], Ordenado) :- pivo(Head, Tail, Lista1, Lista2), quicksort(Lista1, ListaOrdenada1), quicksort(Lista2, ListaOrdenada2), append(ListaOrdenada1, [Head|ListaOrdenada2], Ordenado).



%Exemplo de entrada: bubble([2,4,3,5,1],Ordene).
bubble( Lista, Ordenada) :-
 swap( Lista, Lista1 ), ! ,
 bubble( Lista1, Ordenada) .
bubble( Lista, Lista).
swap( [ X, Y | Rest ], [ Y, X | Rest ] ) :- X > Y, ! .
swap( [ Z | Rest ], [ Z | Rest1 ] ) :- swap(Rest, Rest1 ).


%Exemplo de entrada: selectionsort(Lista,[2,4,3,5,1]).
selectionsort([],[]).
selectionsort([M1|S],[H|T]):-min(H,T,M1),remove(M1,[H|T],N),selectionsort(S,N).
min(M,[],M).
min(M,[H|T],M1):-min2(M,H,N),min(N,T,M1).
min2(A,B,A):-menor(A,B).
min2(A,B,B):-not(menor(A,B)).
menor(A,B):-(A<B).
insere([],B,B).
insere([H|A],B,[H|AB]):-insere(A,B,AB).
remove(X,L,N):-insere(A,[X|B],L),insere(A,B,N).